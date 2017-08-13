
VDA patch against postfix-2.11.10+

It seems the upstream VDA project is no longer maintained, the last
changes against postfix-2.x could also be archived by using the -p1
parameter.  This is an updated patch against 2.11.10 and it will be
the last VDA patch for the postfix ports.

Users using the VDA patch should adopt dovecot-lda which has also quota
support.  As alternative users can jump on the wagon and try to become
an active maintainer of the SF.net VDA project (or a fork)

The 2.11 port will be deprecated at the time postfix-2.11.x is no longer
supported by the postfix author (Wietse Venema), this will happen with
the release of postfix-3.3.x.

===========================================================================
--- README_FILES/VDA_README.orig	1970-01-01 01:00:00.000000000 +0100
+++ README_FILES/VDA_README
@@ -0,0 +1,10 @@
+Postfix VDA patch for maildir++ quota support by 
+    Anderson Nadal <andernadal@gmail.com>
+    Tomas Macek <maca02@atlas.cz>
+    Lucca Longinotti
+
+See VDA patch official website http://vda.sf.net for instructions
+howto patch the Postfix's sourcetree and configure the options 
+provided by this patch.
+
+
--- src/global/mail_params.h.orig	2017-08-13 09:19:28 UTC
+++ src/global/mail_params.h
@@ -2413,6 +2413,54 @@ extern char *var_virt_uid_maps;
 #define DEF_VIRT_GID_MAPS		""
 extern char *var_virt_gid_maps;
 
+#define VAR_VIRT_MAILBOX_LIMIT_MAPS     "virtual_mailbox_limit_maps"
+#define DEF_VIRT_MAILBOX_LIMIT_MAPS     ""
+extern char *var_virt_mailbox_limit_maps;
+
+#define VAR_VIRT_MAILBOX_LIMIT_INBOX    "virtual_mailbox_limit_inbox"
+#define DEF_VIRT_MAILBOX_LIMIT_INBOX    0
+extern bool var_virt_mailbox_limit_inbox;
+
+#define VAR_VIRT_MAILBOX_LIMIT_OVERRIDE "virtual_mailbox_limit_override"
+#define DEF_VIRT_MAILBOX_LIMIT_OVERRIDE 0
+extern bool var_virt_mailbox_limit_override;
+
+#define VAR_VIRT_MAILDIR_EXTENDED       "virtual_maildir_extended"
+#define DEF_VIRT_MAILDIR_EXTENDED       0
+extern bool var_virt_maildir_extended;
+
+#define VAR_VIRT_OVERQUOTA_BOUNCE       "virtual_overquota_bounce"
+#define DEF_VIRT_OVERQUOTA_BOUNCE       0
+extern bool var_virt_overquota_bounce;
+
+#define VAR_VIRT_MAILDIR_LIMIT_MESSAGE  "virtual_maildir_limit_message"
+#define DEF_VIRT_MAILDIR_LIMIT_MESSAGE  "Sorry, the user's maildir has overdrawn his diskspace quota, please try again later."
+extern char *var_virt_maildir_limit_message;
+
+#define VAR_VIRT_MAILDIR_LIMIT_MESSAGE_MAPS "virtual_maildir_limit_message_maps"
+#define DEF_VIRT_MAILDIR_LIMIT_MESSAGE_MAPS ""
+extern char *var_virt_maildir_limit_message_maps;
+
+#define VAR_VIRT_MAILDIR_SUFFIX         "virtual_maildir_suffix"
+#define DEF_VIRT_MAILDIR_SUFFIX         ""
+extern char *var_virt_maildir_suffix;
+
+#define VAR_VIRT_TRASH_COUNT            "virtual_trash_count"
+#define DEF_VIRT_TRASH_COUNT            0
+extern bool var_virt_trash_count;
+
+#define VAR_VIRT_TRASH_NAME             "virtual_trash_name"
+#define DEF_VIRT_TRASH_NAME             ".Trash"
+extern char *var_virt_trash_name;
+
+#define VAR_VIRT_MAILDIR_FILTER         "virtual_maildir_filter"
+#define DEF_VIRT_MAILDIR_FILTER         0
+extern bool var_virt_maildir_filter;
+
+#define VAR_VIRT_MAILDIR_FILTER_MAPS    "virtual_maildir_filter_maps"
+#define DEF_VIRT_MAILDIR_FILTER_MAPS    ""
+extern char *var_virt_maildir_filter_maps;
+
 #define VAR_VIRT_MINUID			"virtual_minimum_uid"
 #define DEF_VIRT_MINUID			100
 extern int var_virt_minimum_uid;
--- src/util/file_limit.c.orig	2003-10-22 18:48:36 UTC
+++ src/util/file_limit.c
@@ -85,7 +85,11 @@ void    set_file_limit(off_t limit)
 #else
     struct rlimit rlim;
 
-    rlim.rlim_cur = rlim.rlim_max = limit;
+    /* rlim_max can only be changed by root. */
+    if (getrlimit(RLIMIT_FSIZE, &rlim) < 0)
+        msg_fatal("getrlimit: %m");
+    rlim.rlim_cur = limit;
+
     if (setrlimit(RLIMIT_FSIZE, &rlim) < 0)
 	msg_fatal("setrlimit: %m");
 #ifdef SIGXFSZ
--- src/virtual/mailbox.c.orig	2016-08-22 21:24:31 UTC
+++ src/virtual/mailbox.c
@@ -52,6 +52,7 @@
 #include <mymalloc.h>
 #include <stringops.h>
 #include <set_eugid.h>
+#include <iostuff.h>
 
 /* Global library. */
 
@@ -70,6 +71,70 @@
 #define YES	1
 #define NO	0
 
+/* change_mailbox_limit - change limit for mailbox file */
+static int change_mailbox_limit(LOCAL_STATE state, USER_ATTR usr_attr)
+{
+    char *myname = "change_mailbox_limit";
+    const char *limit_res;
+    long n = 0;
+    int status = NO;
+
+    /*
+     * Look up the virtual mailbox limit size for this user.
+     * Fall back to virtual_mailbox_limit in case lookup failed.
+     * If virtual mailbox limit size is negative, fall back to virtual_mailbox_limit.
+     * If it's 0, set the mailbox limit to 0, which means unlimited.
+     * If it's more than 0 (positive int), check if the value is smaller than the maximum message size,
+     * if it is and the virtual mailbox limit can't be overridden, fall back to virtual_mailbox_limit and
+     * warn the user, else use the value directly as the mailbox limit.
+     */
+    if (*var_virt_mailbox_limit_maps != 0 && (limit_res = mail_addr_find(virtual_mailbox_limit_maps, state.msg_attr.user, (char **) NULL)) != 0) {
+        n = atol(limit_res);
+        if (n > 0) {
+            if ((n < var_message_limit) && (!var_virt_mailbox_limit_override)) {
+                set_file_limit(var_virt_mailbox_limit);
+                status = NO;
+
+                msg_warn("%s: recipient %s - virtual mailbox limit is "
+                        "smaller than %s in %s - falling back to %s",
+                        myname,
+                        state.msg_attr.user,
+                        VAR_MESSAGE_LIMIT,
+                        virtual_mailbox_limit_maps->title,
+                        VAR_VIRT_MAILBOX_LIMIT);
+            }
+            else {
+                set_file_limit((off_t) n);
+                status = YES;
+
+                if (msg_verbose)
+                    msg_info("%s: set virtual mailbox limit size for %s to %ld",
+                            myname, usr_attr.mailbox, n);
+            }
+        }
+        else if (n == 0) {
+                set_file_limit(OFF_T_MAX);
+                status = YES;
+
+                if (msg_verbose)
+                    msg_info("%s: set virtual mailbox limit size for %s to %ld",
+                            myname, usr_attr.mailbox, OFF_T_MAX);
+        }
+        else {
+            /* Invalid limit size (negative). Use default virtual_mailbox_limit. */
+            set_file_limit(var_virt_mailbox_limit);
+            status = NO;
+        }
+    }
+    else {
+        /* There is no limit in the maps. Use default virtual_mailbox_limit. */
+        set_file_limit(var_virt_mailbox_limit);
+        status = NO;
+    }
+
+    return(status);
+}
+
 /* deliver_mailbox_file - deliver to recipient mailbox */
 
 static int deliver_mailbox_file(LOCAL_STATE state, USER_ATTR usr_attr)
@@ -214,62 +279,72 @@ int     deliver_mailbox(LOCAL_STATE stat
      * Look up the mailbox owner rights. Defer in case of trouble.
      */
     uid_res = mail_addr_find(virtual_uid_maps, state.msg_attr.user,
-			     IGNORE_EXTENSION);
-    if (uid_res == 0) {
-	msg_warn("recipient %s: not found in %s",
-		 state.msg_attr.user, virtual_uid_maps->title);
-	dsb_simple(why, "4.3.5", "mail system configuration error");
-	*statusp = defer_append(BOUNCE_FLAGS(state.request),
-				BOUNCE_ATTR(state.msg_attr));
-	RETURN(YES);
+                            IGNORE_EXTENSION);
+
+    if ((uid_res = mail_addr_find(virtual_uid_maps, state.msg_attr.user, (char **) 0)) == 0) {
+        if ((uid_res = maps_find(virtual_uid_maps, strchr(state.msg_attr.user, '@'), DICT_FLAG_FIXED)) == 0) {
+			msg_warn("recipient %s: not found in %s", state.msg_attr.user, virtual_uid_maps->title);
+			dsb_simple(why, "4.3.5", "mail system configuration error");
+			*statusp = defer_append(BOUNCE_FLAGS(state.request), BOUNCE_ATTR(state.msg_attr));
+			RETURN(YES);
+        }
     }
+
     if ((n = atol(uid_res)) < var_virt_minimum_uid) {
-	msg_warn("recipient %s: bad uid %s in %s",
-		 state.msg_attr.user, uid_res, virtual_uid_maps->title);
-	dsb_simple(why, "4.3.5", "mail system configuration error");
-	*statusp = defer_append(BOUNCE_FLAGS(state.request),
-				BOUNCE_ATTR(state.msg_attr));
-	RETURN(YES);
+		msg_warn("recipient %s: bad uid %s in %s", state.msg_attr.user, uid_res, virtual_uid_maps->title);
+		dsb_simple(why, "4.3.5", "mail system configuration error");
+		*statusp = defer_append(BOUNCE_FLAGS(state.request), BOUNCE_ATTR(state.msg_attr));
+		RETURN(YES);
     }
+
     usr_attr.uid = (uid_t) n;
 
     /*
      * Look up the mailbox group rights. Defer in case of trouble.
      */
     gid_res = mail_addr_find(virtual_gid_maps, state.msg_attr.user,
-			     IGNORE_EXTENSION);
-    if (gid_res == 0) {
-	msg_warn("recipient %s: not found in %s",
-		 state.msg_attr.user, virtual_gid_maps->title);
-	dsb_simple(why, "4.3.5", "mail system configuration error");
-	*statusp = defer_append(BOUNCE_FLAGS(state.request),
-				BOUNCE_ATTR(state.msg_attr));
-	RETURN(YES);
+                            IGNORE_EXTENSION);
+
+    if ((gid_res = mail_addr_find(virtual_gid_maps, state.msg_attr.user, (char **) 0)) == 0) {
+        if ((gid_res = maps_find(virtual_gid_maps, strchr(state.msg_attr.user, '@'), DICT_FLAG_FIXED)) == 0) {
+			msg_warn("recipient %s: not found in %s", state.msg_attr.user, virtual_gid_maps->title);
+			dsb_simple(why, "4.3.5", "mail system configuration error");
+			*statusp = defer_append(BOUNCE_FLAGS(state.request), BOUNCE_ATTR(state.msg_attr));
+			RETURN(YES);
+        }
     }
+
     if ((n = atol(gid_res)) <= 0) {
-	msg_warn("recipient %s: bad gid %s in %s",
-		 state.msg_attr.user, gid_res, virtual_gid_maps->title);
-	dsb_simple(why, "4.3.5", "mail system configuration error");
-	*statusp = defer_append(BOUNCE_FLAGS(state.request),
-				BOUNCE_ATTR(state.msg_attr));
-	RETURN(YES);
+		msg_warn("recipient %s: bad gid %s in %s", state.msg_attr.user, gid_res, virtual_gid_maps->title);
+		dsb_simple(why, "4.3.5", "mail system configuration error");
+		*statusp = defer_append(BOUNCE_FLAGS(state.request), BOUNCE_ATTR(state.msg_attr));
+		RETURN(YES);
     }
+
     usr_attr.gid = (gid_t) n;
 
     if (msg_verbose)
-	msg_info("%s[%d]: set user_attr: %s, uid = %u, gid = %u",
-		 myname, state.level, usr_attr.mailbox,
-		 (unsigned) usr_attr.uid, (unsigned) usr_attr.gid);
+        msg_info("%s[%d]: set user_attr: %s, uid = %u, gid = %u",
+                myname, state.level, usr_attr.mailbox,
+                (unsigned) usr_attr.uid, (unsigned) usr_attr.gid);
 
     /*
      * Deliver to mailbox or to maildir.
      */
 #define LAST_CHAR(s) (s[strlen(s) - 1])
 
-    if (LAST_CHAR(usr_attr.mailbox) == '/')
-	*statusp = deliver_maildir(state, usr_attr);
-    else
-	*statusp = deliver_mailbox_file(state, usr_attr);
+    if (LAST_CHAR(usr_attr.mailbox) == '/') {
+        *statusp = deliver_maildir(state, usr_attr);
+    }
+    else {
+        int changed_limit;
+
+        changed_limit = change_mailbox_limit(state, usr_attr);
+        *statusp = deliver_mailbox_file(state, usr_attr);
+
+        if (changed_limit)
+            set_file_limit(var_virt_mailbox_limit);
+    }
 
     /*
      * Cleanup.
--- src/virtual/maildir.c.orig	2012-01-25 00:41:08 UTC
+++ src/virtual/maildir.c
@@ -64,28 +64,420 @@
 #include <mbox_open.h>
 #include <dsn_util.h>
 
+/* Patch library. */
+
+#include <sys/types.h> /* opendir(3), stat(2) */
+#include <sys/stat.h>  /* stat(2) */
+#include <dirent.h>    /* opendir(3) */
+#include <unistd.h>    /* stat(2) */
+#include <stdlib.h>    /* atol(3) */
+#include <string.h>    /* strrchr(3) */
+#include <vstring_vstream.h>
+#include <dict.h>
+#include <dict_regexp.h>
+#include <ctype.h>
+#include <stdio.h>
+#include <sys_defs.h>
+#include <mail_addr_find.h>
+
 /* Application-specific. */
 
 #include "virtual.h"
 
-/* deliver_maildir - delivery to maildir-style mailbox */
+/* Maildirsize maximal size. */
 
-int     deliver_maildir(LOCAL_STATE state, USER_ATTR usr_attr)
+#define SIZEFILE_MAX 5120
+
+/*
+ * Chris Stratford <chriss@pipex.net>
+ * Read the maildirsize file to get quota info.
+ *
+ * Arguments:
+ *  dirname: the maildir
+ *  countptr: number of messages
+ *
+ * Returns the size of all mails as read from maildirsize,
+ * zero if it couldn't read the file.
+ */
+static long read_maildirsize(char *filename, long *sumptr, long *countptr)
+{
+    char *myname = "read_maildirsize";
+    struct stat statbuf;
+    VSTREAM *sizefile;
+    char *p;
+    int len, first;
+    long sum = 0, count = 0, ret_value = -1;
+
+    if (msg_verbose) 
+	msg_info("%s: we will use sizefile = '%s'", myname, filename);
+	
+    sizefile = vstream_fopen(filename, O_RDONLY, 0);
+    if (!sizefile) {
+	if (msg_verbose)
+	    msg_info("%s: cannot open %s: %m (maybe file does not exist)", myname, filename);
+	    
+	return -1;
+    } else if (stat(filename, &statbuf) < 0 || statbuf.st_size > SIZEFILE_MAX) {
+        if (sizefile) {
+            vstream_fclose(sizefile);
+            unlink(filename);
+        }
+        
+        if (msg_verbose) 
+	    msg_info("%s: stat() returned < 0 or filesize > SIZEFILE_MAX (filename = %s, filesize = %ld)", myname, filename, statbuf.st_size);
+        
+        return -1;
+    }
+    
+    VSTRING *sizebuf = vstring_alloc(SIZEFILE_MAX);
+    len = vstream_fread(sizefile, STR(sizebuf), SIZEFILE_MAX);
+
+    p = STR(sizebuf);
+    *(p + len) = '\0';
+    first = 1;
+
+    while (*p) {
+        long n = 0, c = 0;
+        char *q = p;
+
+        while (*p) {
+            if (*p++ == '\n') {
+                p[-1] = 0;
+                break;
+            }
+        }
+
+        if (first) {
+            first = 0;
+            continue;
+        }
+
+        if (sscanf(q, "%ld %ld", &n, &c) == 2) {
+            sum += n;
+            count += c;
+            /* if (msg_verbose)
+    		msg_info("%s: we read line '%s', totals: sum = %ld, count = %ld", myname, q, sum, count); */
+        }
+        else {
+            vstream_fclose(sizefile);
+            unlink(filename);
+            msg_warn("%s: invalid line '%s' found in %s, removing maildirsize file", myname, q, filename);
+            vstring_free(sizebuf);
+
+            return -1;
+        }
+    }
+
+    *countptr = count;
+    *sumptr = sum;
+        
+    if (sum < 0 || count < 0 || (sum == 0 && count != 0) || (sum != 0 && count == 0)) {
+	if (msg_verbose) {
+	    msg_info("%s: we will return -1 and unlink %s, because file count or sum is <= 0 (sum = %ld, count = %ld)", myname, filename, sum, count);
+	}
+	
+	unlink(filename);
+	ret_value = -1;
+    } else {
+	if (msg_verbose) 
+	    msg_info("%s: we will return Maildir size = %ld, count = %ld", myname, *sumptr, *countptr);
+
+	ret_value = sum;	
+    }
+
+    vstream_fclose(sizefile);
+    vstring_free(sizebuf);
+    
+    return ret_value;
+}
+
+/*
+ * Gives the size of the file according to the Maildir++ extension
+ * present in the filename (code taken from courier-imap).
+ *
+ * Arguments:
+ *  n: filename
+ *
+ * Returns the size given in ",S=<size>" in the filename,
+ * zero if it cannot find ",S=<size>" in the filename.
+ */
+static long maildir_parsequota(const char *n)
+{
+    const char *o;
+    int yes = 0;
+
+    if ((o = strrchr(n, '/')) == 0)
+        o = n;
+
+    for (; *o; o++) {
+        if (*o == ':')
+            break;
+    }
+
+    for (; o >= n; --o) {
+        if (*o == '/')
+            break;
+
+        if (*o == ',' && o[1] == 'S' && o[2] == '=') {
+            yes = 1;
+            o += 3;
+            break;
+        }
+    }
+
+    if (yes) {
+        long s = 0;
+
+        while (*o >= '0' && *o <= '9')
+            s = s*10 + (*o++ - '0');
+
+        return s;
+    }
+
+    return 0;
+}
+
+/*
+ * Computes quota usage for a directory (taken from exim).
+ *
+ * This function is called to determine the exact quota usage of a virtual
+ * maildir box. To achieve maximum possible speed while doing this, it takes
+ * advantage of the maildirsize file and the Maildir++ extensions to filenames,
+ * when applicable and configured to be used. In all other cases it simply
+ * stats all the files as needed to get the size information.
+ *
+ * Arguments:
+ *  dirname: the name of the directory
+ *  countptr: where to add the file count (because this function recurses)
+ *
+ * Returns the sum of the sizes of all measurable files,
+ * zero if the directory could not be opened.
+ */
+static long check_dir_size(char *dirname, long *countptr)
+{
+    char *myname = "check_dir_size";
+    DIR *dir;
+    long sum = 0;
+    struct dirent *ent;
+    struct stat statbuf;
+
+    dir = opendir(dirname);
+    if (dir == NULL) {
+        if (make_dirs(dirname, 0700) == 0) {    /* Try to create the dirs. */
+            dir = opendir(dirname);             /* Reopen the dir. */
+            if (dir == NULL) {
+                msg_warn("%s: cannot reopen directory: %s", myname, dirname);
+                return 0;
+            }
+        }
+        else {
+            msg_warn("%s: cannot open directory: %s", myname, dirname);
+            return 0;
+        }
+    }
+
+    while ((ent = readdir(dir)) != NULL) {
+        char *name = ent->d_name;
+        long tmpsum = 0;
+        VSTRING *buffer;
+
+	/* do not count dot a double-dot dirs */
+        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
+            continue;
+        /* do not count if this is the trash subdir and if we should NOT count it */
+	else if (var_virt_trash_count == 0 && strcmp(name, var_virt_trash_name) == 0)
+    	    continue;
+
+        /*
+         * Here comes the real logic behind this function.
+         * Optimized to be the most efficient possible,
+         * depending on the settings given.
+         * See above for a more detailed description.
+         */
+        if (var_virt_mailbox_limit_inbox) {
+            if (var_virt_maildir_extended && (tmpsum = maildir_parsequota(name))) {
+                sum += tmpsum;
+                (*countptr)++;
+            }
+            else {
+                buffer = vstring_alloc(1024);
+                vstring_sprintf(buffer, "%s/%s", dirname, name);
+
+                if (stat(STR(buffer), &statbuf) < 0) {
+                    vstring_free(buffer);
+                    continue;
+                }
+                if ((statbuf.st_mode & S_IFREG) != 0) {
+                    sum += (long) statbuf.st_size;
+                    (*countptr)++;
+                }
+
+                vstring_free(buffer);
+            }
+        }
+        else {
+            buffer = vstring_alloc(1024);
+            vstring_sprintf(buffer, "%s/%s", dirname, name);
+
+            if (stat(STR(buffer), &statbuf) < 0) {
+                vstring_free(buffer);
+                continue;
+            }
+            if ((statbuf.st_mode & S_IFREG) != 0) {
+                if (strcmp(dirname + strlen(dirname) - 3, "new") == 0 || strcmp(dirname + strlen(dirname) - 3, "cur") == 0 || strcmp(dirname + strlen(dirname) - 3, "tmp") == 0) {
+                    sum += (long) statbuf.st_size;
+                    (*countptr)++;
+                }
+            }
+            else if ((statbuf.st_mode & S_IFDIR) != 0) {
+                sum += check_dir_size(STR(buffer), countptr);
+            }
+
+            vstring_free(buffer);
+        }
+    }
+    closedir(dir);
+
+    if (msg_verbose)
+        msg_info("%s: full scan done: dir=%s sum=%ld count=%ld", myname, dirname, sum, *countptr);
+
+    return sum;
+}
+
+/* Cut all occurrences of pattern from string. */
+static char *strcut(char *str, const char *pat)
+{
+    char *ptr, *loc, *ret;
+    ret = str;
+    loc = str;
+
+    /* No match, return original string. */
+    if (!strstr(loc, pat))
+        return(str);
+
+    while (*loc && (ptr = strstr(loc, pat))) {
+        while (loc < ptr)
+            *str++ = *loc++;
+        loc += strlen(pat);
+    }
+
+    while (*loc)
+        *str++ = *loc++;
+
+    *str = 0;
+
+    return(ret);
+}
+
+/* Check if maildirfilter file is up-to-date compared to SQL, (re)write it if not. */
+static long sql2file(char *filename, char *user)
+{
+    char *myname = "sql2file";
+    char *filter_sqlres;
+    char filter_fileres[128];
+    long sqlmtime = 0, filemtime = 0, retval = 0;
+    int filterfile, size_sqlres, i;
+    struct stat statbuf;
+
+    if (*var_virt_maildir_filter_maps != 0) {
+        filter_sqlres = (char *) mymalloc(16000);
+        filter_sqlres = (char *) mail_addr_find(virtual_maildir_filter_maps, user, (char **) 0);
+
+        if (filter_sqlres) {
+            strcut(filter_sqlres, "\r");
+            if (filter_sqlres[0] == '#' && filter_sqlres[1] == ' ' && filter_sqlres[2] == 'M') {
+                size_sqlres = strlen(filter_sqlres);
+
+                for (i = 4; i <= size_sqlres; i++) {
+                    if(filter_sqlres[i] == '/' && filter_sqlres[i+1] == '^') {
+                        filter_sqlres[i-1] = '\n';
+                    }
+                }
+
+                filter_sqlres[(size_sqlres+1)] = '\0';
+
+                sqlmtime = atol(filter_sqlres+3);
+                retval = sqlmtime;
+
+                filterfile = open(filename, O_RDONLY, 0);
+                if (filterfile) {
+                    read(filterfile, (void *) filter_fileres, 127);
+                    close(filterfile);
+
+                    filemtime = atol(filter_fileres+3);
+                }
+
+                if (msg_verbose)
+                    msg_info("%s: filter data: sql_size=%li sql_mtime=%ld file_mtime=%ld", myname, strlen(filter_sqlres), sqlmtime, filemtime);
+            }
+            if (sqlmtime != filemtime && sqlmtime != 0) {
+                if ((filterfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0640))) {
+                    if (msg_verbose)
+                        msg_info("%s: updating filter file: %s", myname, filename);
+                    write(filterfile, filter_sqlres, strlen(filter_sqlres));
+                    close(filterfile);
+                }
+                else {
+                    msg_warn("%s: can't create filter file: %s", myname, filename);
+                    retval = 0;
+                }
+            }
+        }
+    }
+    else {
+        if (stat(filename, &statbuf) == 0)
+            retval = (long) statbuf.st_mtime;
+        if (msg_verbose)
+            msg_info("%s: processing filter file: file_mtime=%ld", myname, retval);
+    }
+
+    return retval;
+}
+
+/* deliver_maildir - delivery to maildir-style mailbox */
+int deliver_maildir(LOCAL_STATE state, USER_ATTR usr_attr)
 {
     const char *myname = "deliver_maildir";
-    char   *newdir;
-    char   *tmpdir;
-    char   *curdir;
-    char   *tmpfile;
-    char   *newfile;
+    char    *newdir;
+    char    *tmpdir;
+    char    *curdir;
+    char    *newfile;
+    char    *tmpfile;
     DSN_BUF *why = state.msg_attr.why;
     VSTRING *buf;
     VSTREAM *dst;
-    int     mail_copy_status;
-    int     deliver_status;
-    int     copy_flags;
-    struct stat st;
-    struct timeval starttime;
+    int      mail_copy_status;
+    int      deliver_status;
+    int      copy_flags;
+    struct   stat st;
+    struct   timeval starttime;
+
+    /* Maildir Quota. */
+    const char *limit_res;              /* Limit from map. */
+    char    *sizefilename = (char *) 0; /* Maildirsize file name. */
+    VSTRING *filequota;                 /* Quota setting from the maildirsize file. */
+    VSTREAM *sizefile;                  /* Maildirsize file handle. */
+    long     n = 0;                     /* Limit in long integer format. */
+    long     saved_count = 0;           /* The total number of files. */
+    long     saved_size = 0;            /* The total quota of all files. */
+    struct   stat mail_stat;            /* To check the size of the mail to be written. */
+    struct   stat sizefile_stat;        /* To check the size of the maildirsize file. */
+    time_t   tm;                        /* To check the age of the maildirsize file. */
+
+    /* Maildir Filters. */
+    const char *value, *cmd_text;       /* Filter values. */
+    char    *filtername;
+    char    *header;
+    char    *bkpnewfile;
+    char    *mdffilename = (char *) 0;  /* Maildirfolder file name. */
+    VSTRING *fltstr;
+    VSTREAM *tmpfilter;
+    VSTREAM *mdffile;                   /* Maildirfolder file handle. */
+    DICT    *FILTERS;
+    long     sqlmtime;                  /* Latest modification time from sql2file(). */
+    int      cmd_len;
+    int	    read_mds = -1;		/* read_maildirsize() returned value */
+    struct   stat mdffile_stat;         /* To check if the maildirfolder file exists. */
 
     GETTIMEOFDAY(&starttime);
 
@@ -94,15 +486,14 @@ int     deliver_maildir(LOCAL_STATE stat
      */
     state.level++;
     if (msg_verbose)
-	MSG_LOG_STATE(myname, state);
+	    MSG_LOG_STATE(myname, state);
 
     /*
      * Don't deliver trace-only requests.
      */
     if (DEL_REQ_TRACE_ONLY(state.request->flags)) {
-	dsb_simple(why, "2.0.0", "delivers to maildir");
-	return (sent(BOUNCE_FLAGS(state.request),
-		     SENT_ATTR(state.msg_attr)));
+        dsb_simple(why, "2.0.0", "delivers to maildir");
+        return (sent(BOUNCE_FLAGS(state.request), SENT_ATTR(state.msg_attr)));
     }
 
     /*
@@ -110,18 +501,116 @@ int     deliver_maildir(LOCAL_STATE stat
      * attribute to reflect the final recipient.
      */
     if (vstream_fseek(state.msg_attr.fp, state.msg_attr.offset, SEEK_SET) < 0)
-	msg_fatal("seek message file %s: %m", VSTREAM_PATH(state.msg_attr.fp));
+        msg_fatal("seek message file %s: %m", VSTREAM_PATH(state.msg_attr.fp));
     state.msg_attr.delivered = state.msg_attr.rcpt.address;
     mail_copy_status = MAIL_COPY_STAT_WRITE;
     buf = vstring_alloc(100);
 
-    copy_flags = MAIL_COPY_TOFILE | MAIL_COPY_RETURN_PATH
-	| MAIL_COPY_DELIVERED | MAIL_COPY_ORIG_RCPT;
+    copy_flags = MAIL_COPY_TOFILE | MAIL_COPY_RETURN_PATH | MAIL_COPY_DELIVERED | MAIL_COPY_ORIG_RCPT;
 
-    newdir = concatenate(usr_attr.mailbox, "new/", (char *) 0);
-    tmpdir = concatenate(usr_attr.mailbox, "tmp/", (char *) 0);
-    curdir = concatenate(usr_attr.mailbox, "cur/", (char *) 0);
+    /*
+     * Concatenate the maildir suffix (if set).
+     */
+    if (*var_virt_maildir_suffix == 0) {
+        newdir = concatenate(usr_attr.mailbox, "new/", (char *) 0);
+        tmpdir = concatenate(usr_attr.mailbox, "tmp/", (char *) 0);
+        curdir = concatenate(usr_attr.mailbox, "cur/", (char *) 0);
+    }
+    else {
+        newdir = concatenate(usr_attr.mailbox, var_virt_maildir_suffix, (char *) 0);
+        tmpdir = concatenate(usr_attr.mailbox, var_virt_maildir_suffix, (char *) 0);
+        curdir = concatenate(usr_attr.mailbox, var_virt_maildir_suffix, (char *) 0);
+        newdir = concatenate(newdir, "new/", (char *) 0);
+        tmpdir = concatenate(tmpdir, "tmp/", (char *) 0);
+        curdir = concatenate(curdir, "cur/", (char *) 0);
+    }
+
+    /* get the sizefilename, no matter if we use var_virt_maildir_extended */
+    if (*var_virt_maildir_suffix == 0) {
+        sizefilename = concatenate(usr_attr.mailbox, "maildirsize", (char *) 0);
+    } else {
+        sizefilename = concatenate(usr_attr.mailbox, var_virt_maildir_suffix, (char *) 0);
+        sizefilename = concatenate(sizefilename, "maildirsize", (char *) 0);
+    }
+    
+    /*
+     * Look up the virtual maildir limit size for this user.
+     * Fall back to virtual_mailbox_limit in case lookup failed.
+     * If virtual maildir limit size is negative, fall back to virtual_mailbox_limit.
+     * If it's 0, set the mailbox limit to 0, which means unlimited.
+     * If it's more than 0 (positive int), check if the value is smaller than the maximum message size,
+     * if it is and the virtual maildir limit can't be overridden, fall back to virtual_mailbox_limit and
+     * warn the user, else use the value directly as the maildir limit.
+     */
+    if (*var_virt_mailbox_limit_maps != 0 && (limit_res = mail_addr_find(virtual_mailbox_limit_maps, state.msg_attr.user, (char **) NULL)) != 0) {
+        n = atol(limit_res);
+        if (n > 0) {
+            if ((n < var_message_limit) && (!var_virt_mailbox_limit_override)) {
+                n = var_virt_mailbox_limit;
+
+                msg_warn("%s: recipient %s - virtual maildir limit is smaller than %s in %s - falling back to %s",
+                        myname, state.msg_attr.user, VAR_MESSAGE_LIMIT, virtual_mailbox_limit_maps->title,
+                        VAR_VIRT_MAILBOX_LIMIT);
+            }
+            else {
+                if (msg_verbose)
+                    msg_info("%s: set virtual maildir limit size for %s to %ld",
+                            myname, usr_attr.mailbox, n);
+            }
+        }
+        else if (n == 0) {
+                if (msg_verbose)
+                    msg_info("%s: set virtual maildir limit size for %s to %ld",
+                            myname, usr_attr.mailbox, n);
+        }
+        else {
+	    if (msg_verbose)
+		msg_info("%s: quota is negative (%ld), using default virtual_mailbox_limit (%ld)", 
+			    myname, n, var_virt_mailbox_limit);
+            /* Invalid limit size (negative). Use default virtual_mailbox_limit. */
+            n = var_virt_mailbox_limit;
+        }
+    }
+    else {
+	if (msg_verbose)
+	    msg_info("%s: no limit found in the maps, using default virtual_mailbox_limit (%ld)", 
+			myname, var_virt_mailbox_limit);
+        /* There is no limit in the maps. Use default virtual_mailbox_limit. */
+        n = var_virt_mailbox_limit;
+    }
 
+    /* If there should is a quota on maildir generaly, check it before delivering the mail */
+    if (n != 0) {
+        set_eugid(usr_attr.uid, usr_attr.gid);
+	/* try to read the quota from maildirsize file. Returned values by read_maildirsize:
+	x < 0  = something failed
+	x >= 0 = reading successfully finished - sum si returned, so sum size of Maildir was 0 or more */
+        if (!var_virt_mailbox_limit_inbox && var_virt_maildir_extended && (read_mds = read_maildirsize(sizefilename, &saved_size, &saved_count)) >= 0) {
+    	    if (msg_verbose)
+        	msg_info("%s: maildirsize used=%s sum=%ld count=%ld", myname, sizefilename, saved_size, saved_count);
+	} else {
+	    if (msg_verbose) 
+		msg_info("%s: We will recount the quota (var_virt_mailbox_limit = %ld, var_virt_maildir_extended = %d, read_maildirsize = %d)", 
+			    myname, var_virt_mailbox_limit, var_virt_maildir_extended, read_mds);
+
+	    /* sanity */
+	    saved_size = 0; 
+	    saved_count = 0;
+	    
+    	    if (var_virt_mailbox_limit_inbox) {
+        	/* Check Inbox only (new, cur and tmp dirs). */
+        	saved_size = check_dir_size(newdir, &saved_count);
+        	saved_size += check_dir_size(curdir, &saved_count);
+        	saved_size += check_dir_size(tmpdir, &saved_count);
+    	    } else {
+        	/* Check all boxes. */
+        	saved_size = check_dir_size(usr_attr.mailbox, &saved_count);
+    	    }
+
+    	    set_eugid(var_owner_uid, var_owner_gid);
+    	}    	
+    }
+    
     /*
      * Create and write the file as the recipient, so that file quota work.
      * Create any missing directories on the fly. The file name is chosen
@@ -175,46 +664,288 @@ int     deliver_maildir(LOCAL_STATE stat
      * [...]
      */
     set_eugid(usr_attr.uid, usr_attr.gid);
-    vstring_sprintf(buf, "%lu.P%d.%s",
-		 (unsigned long) starttime.tv_sec, var_pid, get_hostname());
+    vstring_sprintf(buf, "%lu.P%d.%s", (unsigned long) starttime.tv_sec, var_pid, get_hostname());
     tmpfile = concatenate(tmpdir, STR(buf), (char *) 0);
     newfile = 0;
+    bkpnewfile = 0;
     if ((dst = vstream_fopen(tmpfile, O_WRONLY | O_CREAT | O_EXCL, 0600)) == 0
-	&& (errno != ENOENT
-	    || make_dirs(tmpdir, 0700) < 0
-	    || (dst = vstream_fopen(tmpfile, O_WRONLY | O_CREAT | O_EXCL, 0600)) == 0)) {
-	dsb_simple(why, mbox_dsn(errno, "4.2.0"),
-		   "create maildir file %s: %m", tmpfile);
-    } else if (fstat(vstream_fileno(dst), &st) < 0) {
+        && (errno != ENOENT
+            || make_dirs(tmpdir, 0700) < 0
+            || (dst = vstream_fopen(tmpfile, O_WRONLY | O_CREAT | O_EXCL, 0600)) == 0)) {
+        dsb_simple(why, mbox_dsn(errno, "4.2.0"), "create maildir file %s: %m", tmpfile);
+    }
+    else if (fstat(vstream_fileno(dst), &st) < 0) {
+        /*
+         * Coverity 200604: file descriptor leak in code that never executes.
+         * Code replaced by msg_fatal(), as it is not worthwhile to continue
+         * after an impossible error condition.
+         */
+        msg_fatal("fstat %s: %m", tmpfile);
+    }
+    else {
+        vstring_sprintf(buf, "%lu.V%lxI%lxM%lu.%s",
+                (unsigned long) starttime.tv_sec,
+                (unsigned long) st.st_dev,
+                (unsigned long) st.st_ino,
+                (unsigned long) starttime.tv_usec,
+                get_hostname());
+        newfile = concatenate(newdir, STR(buf), (char *) 0);
+        bkpnewfile = concatenate(STR(buf), (char *) 0); /* Will need it later, if we MOVE to other folders. */
 
-	/*
-	 * Coverity 200604: file descriptor leak in code that never executes.
-	 * Code replaced by msg_fatal(), as it is not worthwhile to continue
-	 * after an impossible error condition.
-	 */
-	msg_fatal("fstat %s: %m", tmpfile);
-    } else {
-	vstring_sprintf(buf, "%lu.V%lxI%lxM%lu.%s",
-			(unsigned long) starttime.tv_sec,
-			(unsigned long) st.st_dev,
-			(unsigned long) st.st_ino,
-			(unsigned long) starttime.tv_usec,
-			get_hostname());
-	newfile = concatenate(newdir, STR(buf), (char *) 0);
-	if ((mail_copy_status = mail_copy(COPY_ATTR(state.msg_attr),
-					  dst, copy_flags, "\n",
-					  why)) == 0) {
-	    if (sane_link(tmpfile, newfile) < 0
-		&& (errno != ENOENT
-		    || (make_dirs(curdir, 0700), make_dirs(newdir, 0700)) < 0
-		    || sane_link(tmpfile, newfile) < 0)) {
-		dsb_simple(why, mbox_dsn(errno, "4.2.0"),
-			   "create maildir file %s: %m", newfile);
-		mail_copy_status = MAIL_COPY_STAT_WRITE;
-	    }
-	}
-	if (unlink(tmpfile) < 0)
-	    msg_warn("remove %s: %m", tmpfile);
+        if ((mail_copy_status = mail_copy(COPY_ATTR(state.msg_attr), dst, copy_flags, "\n", why)) == 0) {
+            /*
+             * Add a ",S=<sizeoffile>" to the newly written file according to the
+             * Maildir++ specifications: http://www.inter7.com/courierimap/README.maildirquota.html
+             * This needs a stat(2) of the tempfile and modification of the
+             * name of the file.
+             */
+            if (stat(tmpfile, &mail_stat) == 0) {
+                if (n != 0) {
+                    saved_size += (long) mail_stat.st_size;
+                    saved_count++;
+                }
+                if (var_virt_maildir_extended) {
+                    /* Append the size of the file to newfile. */
+                    vstring_sprintf(buf, ",S=%ld", (long) mail_stat.st_size);
+                    newfile = concatenate(newfile, STR(buf), (char *) 0);
+                    bkpnewfile = concatenate(bkpnewfile, STR(buf), (char *) 0);
+                }
+            }
+
+            /*
+             * Now we have the maildir size in saved_size, compare it to the max
+             * quota value and eventually issue a message that we've overdrawn it.
+             */
+            if (saved_size > n) {
+                mail_copy_status = MAIL_COPY_STAT_WRITE;
+                if (((long) mail_stat.st_size > n) || (var_virt_overquota_bounce))
+                    errno = EFBIG;
+                else
+                    errno = EDQUOT;
+            }
+            else {
+                /* Maildirfilter code by rk@demiurg.net. */
+                if (var_virt_maildir_filter) {
+                    if (msg_verbose)
+                        msg_info("%s: loading DICT filters", myname);
+
+#define STREQUAL(x,y,l) (strncasecmp((x), (y), (l)) == 0 && (y)[l] == 0)
+#define MAIL_COPY_STAT_REJECT  (1<<3)
+#define MAIL_COPY_STAT_DISCARD (1<<4)
+
+                    /* Read filters. */
+                    filtername = concatenate("regexp:", usr_attr.mailbox, "maildirfilter", (char *) 0);
+                    sqlmtime = sql2file(strchr(filtername, '/'), state.msg_attr.user);
+
+                    /* Check if this filter is already registered as dictionary. */
+                    if (msg_verbose)
+                        msg_info("%s: checking DICT filters for %s", myname, filtername);
+
+                    if ((FILTERS = dict_handle(filtername))) {
+                        if (msg_verbose)
+                            msg_info("%s: DICT filter found", myname);
+
+                        /*
+                         * If we have mtime in our DICT structure, check it against sqlmtime
+                         * and reload the filters if they differ.
+                         */
+                        if (FILTERS->mtime > 0 && sqlmtime > 0 && FILTERS->mtime != sqlmtime) {
+                            if (msg_verbose)
+                                msg_info("%s: reloading DICT filters (dict_mtime=%ld != sql_mtime=%ld)",
+                                        myname, FILTERS->mtime, sqlmtime);
+
+                            dict_unregister(filtername);
+                            FILTERS = dict_open(filtername, O_RDONLY, DICT_FLAG_LOCK);
+                            dict_register(filtername, FILTERS);
+                            FILTERS->mtime = sqlmtime;
+                        }
+                    }
+                    else {
+                        if (sqlmtime > 0) {
+                            /* Registering filter as new dictionary. */
+                            if (msg_verbose)
+                                msg_info("%s: loading DICT filters from %s (mtime=%ld)",
+                                        myname, filtername, sqlmtime);
+
+                            FILTERS = dict_open(filtername, O_RDONLY, DICT_FLAG_LOCK);
+                            dict_register(filtername, FILTERS);
+                            FILTERS->mtime = sqlmtime;
+                        }
+                    }
+
+                    if (FILTERS && (tmpfilter = vstream_fopen(tmpfile, O_RDONLY, 0))) {
+                        fltstr = vstring_alloc(1024);
+                        header = (char *) malloc(8192); /* !!!INSECURE!!! See 7168-hack below. */
+                        header[0] = 0;
+                        vstring_get_nonl_bound(fltstr, tmpfilter, 1023);
+                        header = concatenate(header, STR(fltstr), (char *) 0);
+
+                        while(!vstream_feof(tmpfilter) && fltstr->vbuf.data[0] && strlen(header) < 7168 ) {
+                            vstring_get_nonl_bound(fltstr, tmpfilter, 1023);
+                            /* Glue multiline headers, replacing leading TAB with space. */
+                            if (msg_verbose)
+                                msg_info("%s: fltstr value: %s", myname, STR(fltstr));
+
+                            if (fltstr->vbuf.data[0] == ' ' || fltstr->vbuf.data[0] == '\t' ) {
+                                if (fltstr->vbuf.data[0] == '\t')
+                                    fltstr->vbuf.data[0] = ' ';
+                                header = concatenate(header, STR(fltstr), (char *) 0);
+                            }
+                            else {
+                                header = concatenate(header, "\n", STR(fltstr), (char *) 0);
+                            }
+                        }
+
+                        if (msg_verbose)
+                            msg_info("%s: checking filter CMD for %s", myname, filtername);
+
+                        /* Check whole header part with regexp maps. */
+                        if ((value = dict_get(FILTERS, lowercase(header))) != 0) {
+                            if (msg_verbose)
+                                msg_info("%s: preparing filter CMD", myname);
+
+                            cmd_text = value + strcspn(value, " \t");
+                            cmd_len = cmd_text - value;
+                            while (*cmd_text && ISSPACE(*cmd_text))
+                                cmd_text++;
+
+                            if (msg_verbose)
+                                msg_info("%s: executing filter CMD", myname);
+
+                            if (STREQUAL(value, "REJECT", cmd_len)) {
+                                if (msg_verbose)
+                                    msg_info("%s: executing filter CMD REJECT", myname);
+
+                                mail_copy_status = MAIL_COPY_STAT_REJECT;
+                                vstring_sprintf(why->reason, "%s", cmd_text);
+                                dsb_simple(why, "5.0.0", "User filter - REJECT");
+                            }
+
+                            if (STREQUAL(value, "DISCARD", cmd_len)) {
+                                if (msg_verbose)
+                                    msg_info("%s: executing filter CMD DISCARD", myname);
+
+                                mail_copy_status = MAIL_COPY_STAT_DISCARD;
+                                vstring_sprintf(why->reason, "%s", cmd_text);
+                                dsb_simple(why, "5.0.0", "User filter - DISCARD");
+                            }
+
+                            if (var_virt_maildir_extended) {
+                                if (STREQUAL(value, "MOVE", cmd_len)) {
+                                    if (msg_verbose)
+                                        msg_info("%s: executing filter CMD MOVE", myname);
+
+                                    strcut((char *) cmd_text, " ");
+                                    strcut((char *) cmd_text, "\t");
+                                    strcut((char *) cmd_text, "/");
+                                    strcut((char *) cmd_text, "..");
+
+                                    if (*var_virt_maildir_suffix == 0) {
+                                        newfile = concatenate(usr_attr.mailbox, (char *) 0);
+                                    }
+                                    else {
+                                        newfile = concatenate(usr_attr.mailbox, var_virt_maildir_suffix, (char *) 0);
+                                    }
+
+                                    if (cmd_text[0] != '.') {
+                                        newfile = concatenate(newfile, ".", (char *) 0);
+                                    }
+                                    newdir  = concatenate(newfile, cmd_text, "/", "new/", (char *) 0);
+                                    tmpdir  = concatenate(newfile, cmd_text, "/", "tmp/", (char *) 0);
+                                    curdir  = concatenate(newfile, cmd_text, "/", "cur/", (char *) 0);
+                                    mdffilename = concatenate(newfile, cmd_text, "/", "maildirfolder", (char *) 0);
+                                    newfile = concatenate(newfile, cmd_text, "/", "new/", bkpnewfile, (char *) 0);
+                                }
+                            }
+
+                            if (STREQUAL(value, "LOG", cmd_len) || STREQUAL(value, "WARN", cmd_len)) {
+                                msg_warn("%s: header check warning: %s", myname, cmd_text);
+                            }
+
+                            if (STREQUAL(value, "INFO", cmd_len)) {
+                                msg_info("%s: header check info: %s", myname, cmd_text);
+                            }
+
+                            if (msg_verbose)
+                                msg_info("%s: exiting filter CMD", myname);
+                        } /* End-Of-Check */
+
+                        myfree(header);
+                        vstring_free(fltstr);
+                        vstream_fclose(tmpfilter);
+                    }
+
+                    myfree(filtername);
+                } /* End-Of-Maildirfilter */
+
+                /* Deliver to curdir. */
+                if (mail_copy_status == 0) {
+                    if (sane_link(tmpfile, newfile) < 0
+                        && (errno != ENOENT
+                            || (make_dirs(curdir, 0700), make_dirs(newdir, 0700), make_dirs(tmpdir, 0700)) < 0
+                            || sane_link(tmpfile, newfile) < 0)) {
+                        dsb_simple(why, mbox_dsn(errno, "4.2.0"), "create maildir file %s: %m", newfile);
+                        mail_copy_status = MAIL_COPY_STAT_WRITE;
+                    }
+
+                    if (var_virt_maildir_extended) {
+                        time(&tm);
+
+                        /* Check if the quota in the file is the same as the current one, if not, delete the file. */
+                        sizefile = vstream_fopen(sizefilename, O_RDONLY, 0);
+                        if (sizefile) {
+                            filequota = vstring_alloc(128);
+                            vstring_get_null_bound(filequota, sizefile, 127);
+                            vstream_fclose(sizefile);
+                            if (atol(vstring_export(filequota)) != n)
+                                unlink(sizefilename);
+                        }
+
+                        /* Open maildirsize file to append this transaction. */
+                        sizefile = vstream_fopen(sizefilename, O_WRONLY | O_APPEND, 0640);
+
+                        /* If the open fails (maildirsize doesn't exist), or it's too large, or too old, overwrite it. */
+                        if(!sizefile || (stat(sizefilename, &sizefile_stat) < 0) || (sizefile_stat.st_size > SIZEFILE_MAX) || (sizefile_stat.st_mtime + 15*60 < tm)) {
+                            /* If the file exists, sizefile has been opened above, so close it first. */
+                            if (sizefile) {
+                                vstream_fclose(sizefile);
+                                sizefile = vstream_fopen(sizefilename, O_WRONLY | O_TRUNC, 0640);
+                            }
+                            else {
+                                sizefile = vstream_fopen(sizefilename, O_WRONLY | O_CREAT, 0640);
+                            }
+
+                            /* If the creation worked, write to the file, otherwise just give up. */
+                            if (sizefile) {
+                                vstream_fprintf(sizefile, "%ldS\n%ld %ld\n", n, saved_size, saved_count);
+                                vstream_fclose(sizefile);
+                            }
+                        }
+                        else {
+                            /* We opened maildirsize, so let's just append this transaction and close it. */
+                            vstream_fprintf(sizefile, "%ld 1\n", (long) mail_stat.st_size);
+                            vstream_fclose(sizefile);
+                        }
+
+                        /*
+                         * 1) mdffilename != 0, so the maildirfilter code went through the MOVE to subfolder rule.
+                         * 2) stat() failed, maybe the file does not exist? Try to create it.
+                         */
+                        if (mdffilename && (stat(mdffilename, &mdffile_stat) < 0)) {
+                            mdffile = vstream_fopen(mdffilename, O_WRONLY | O_CREAT, 0600);
+                            if (mdffile) {
+                                vstream_fclose(mdffile);
+                            }
+                            else {
+                                msg_warn("Cannot create maildirfolder file '%s': %s", mdffilename, strerror(errno));
+                            }
+                        }
+                    }
+                }
+            }
+        }
+        if (unlink(tmpfile) < 0)
+            msg_warn("remove %s: %m", tmpfile);
     }
     set_eugid(var_owner_uid, var_owner_gid);
 
@@ -224,31 +955,64 @@ int     deliver_maildir(LOCAL_STATE stat
      * location possibly under user control.
      */
     if (mail_copy_status & MAIL_COPY_STAT_CORRUPT) {
-	deliver_status = DEL_STAT_DEFER;
-    } else if (mail_copy_status != 0) {
-	if (errno == EACCES) {
-	    msg_warn("maildir access problem for UID/GID=%lu/%lu: %s",
-		     (long) usr_attr.uid, (long) usr_attr.gid,
-		     STR(why->reason));
-	    msg_warn("perhaps you need to create the maildirs in advance");
-	}
-	vstring_sprintf_prepend(why->reason, "maildir delivery failed: ");
-	deliver_status =
-	    (STR(why->status)[0] == '4' ?
-	     defer_append : bounce_append)
-	    (BOUNCE_FLAGS(state.request),
-	     BOUNCE_ATTR(state.msg_attr));
-    } else {
-	dsb_simple(why, "2.0.0", "delivered to maildir");
-	deliver_status = sent(BOUNCE_FLAGS(state.request),
-			      SENT_ATTR(state.msg_attr));
+        deliver_status = DEL_STAT_DEFER;
     }
+    else if (mail_copy_status != 0) {
+        if (errno == EACCES) {
+            msg_warn("maildir access problem for UID/GID=%lu/%lu: %s",
+                    (long) usr_attr.uid, (long) usr_attr.gid, STR(why->reason));
+            msg_warn("perhaps you need to create the maildirs in advance");
+        }
+
+        /* Support per-recipient bounce messages. */
+        const char *limit_message;
+        int errnored = errno; /* Seems like mail_addr_find resets errno ... */
+
+        if (*var_virt_maildir_limit_message_maps != 0 && (limit_message = mail_addr_find(virtual_maildir_limit_message_maps, state.msg_attr.user, (char **) NULL)) != 0) {
+            errno = errnored;
+            if (errno == EFBIG) {
+                dsb_simple(why, "5.2.2", limit_message, NULL);
+            }
+            if (errno == EDQUOT) {
+                dsb_simple(why, "4.2.2", limit_message, NULL);
+            }
+        }
+        else {
+            errno = errnored;
+            if (errno == EFBIG) {
+                dsb_simple(why, "5.2.2", var_virt_maildir_limit_message, NULL);
+            }
+            if (errno == EDQUOT) {
+                dsb_simple(why, "4.2.2", var_virt_maildir_limit_message, NULL);
+            }
+        }
+
+        vstring_sprintf_prepend(why->reason, "maildir delivery failed: ");
+        deliver_status =
+                (STR(why->status)[0] == '4' ? defer_append : bounce_append)
+                (BOUNCE_FLAGS(state.request), BOUNCE_ATTR(state.msg_attr));
+    }
+    else {
+        dsb_simple(why, "2.0.0", "delivered to maildir");
+        deliver_status = sent(BOUNCE_FLAGS(state.request), SENT_ATTR(state.msg_attr));
+    }
+
     vstring_free(buf);
+
     myfree(newdir);
     myfree(tmpdir);
     myfree(curdir);
+
+    if (sizefilename)
+        myfree(sizefilename);
+    if (mdffilename)
+        myfree(mdffilename);
+
     myfree(tmpfile);
     if (newfile)
-	myfree(newfile);
+        myfree(newfile);
+    if (bkpnewfile)
+        myfree(bkpnewfile);
+
     return (deliver_status);
 }
--- src/virtual/virtual.c.orig	2011-02-19 00:46:06 UTC
+++ src/virtual/virtual.c
@@ -335,12 +335,30 @@ long    var_virt_mailbox_limit;
 char   *var_mail_spool_dir;		/* XXX dependency fix */
 bool    var_strict_mbox_owner;
 
+char   *var_virt_mailbox_limit_maps;
+bool    var_virt_mailbox_limit_inbox;
+bool    var_virt_mailbox_limit_override;
+bool    var_virt_maildir_extended;
+bool    var_virt_overquota_bounce;
+char   *var_virt_maildir_limit_message;
+char   *var_virt_maildir_limit_message_maps;
+char   *var_virt_maildir_suffix;
+bool    var_virt_trash_count;
+char   *var_virt_trash_name;
+bool    var_virt_maildir_filter;
+char   *var_virt_maildir_filter_maps;
+
+
  /*
   * Mappings.
   */
 MAPS   *virtual_mailbox_maps;
 MAPS   *virtual_uid_maps;
 MAPS   *virtual_gid_maps;
+MAPS   *virtual_mailbox_limit_maps;
+MAPS   *virtual_maildir_limit_message_maps;
+MAPS   *virtual_maildir_filter_maps;
+
 
  /*
   * Bit masks.
@@ -450,15 +468,28 @@ static void post_init(char *unused_name,
      */
     virtual_mailbox_maps =
 	maps_create(VAR_VIRT_MAILBOX_MAPS, var_virt_mailbox_maps,
-		    DICT_FLAG_LOCK | DICT_FLAG_PARANOID);
+		    DICT_FLAG_LOCK);
 
     virtual_uid_maps =
 	maps_create(VAR_VIRT_UID_MAPS, var_virt_uid_maps,
-		    DICT_FLAG_LOCK | DICT_FLAG_PARANOID);
+		    DICT_FLAG_LOCK);
 
     virtual_gid_maps =
 	maps_create(VAR_VIRT_GID_MAPS, var_virt_gid_maps,
-		    DICT_FLAG_LOCK | DICT_FLAG_PARANOID);
+		    DICT_FLAG_LOCK);
+
+    virtual_mailbox_limit_maps =
+        maps_create(VAR_VIRT_MAILBOX_LIMIT_MAPS, var_virt_mailbox_limit_maps,
+                    DICT_FLAG_LOCK);
+
+    virtual_maildir_limit_message_maps =
+        maps_create(VAR_VIRT_MAILDIR_LIMIT_MESSAGE_MAPS, var_virt_maildir_limit_message_maps,
+                    DICT_FLAG_LOCK);
+
+    virtual_maildir_filter_maps =
+        maps_create(VAR_VIRT_MAILDIR_FILTER_MAPS, var_virt_maildir_filter_maps,
+                    DICT_FLAG_LOCK);
+
 
     virtual_mbox_lock_mask = mbox_lock_mask(var_virt_mailbox_lock);
 }
@@ -510,10 +541,22 @@ int     main(int argc, char **argv)
 	VAR_VIRT_GID_MAPS, DEF_VIRT_GID_MAPS, &var_virt_gid_maps, 0, 0,
 	VAR_VIRT_MAILBOX_BASE, DEF_VIRT_MAILBOX_BASE, &var_virt_mailbox_base, 1, 0,
 	VAR_VIRT_MAILBOX_LOCK, DEF_VIRT_MAILBOX_LOCK, &var_virt_mailbox_lock, 1, 0,
+	VAR_VIRT_MAILBOX_LIMIT_MAPS, DEF_VIRT_MAILBOX_LIMIT_MAPS, &var_virt_mailbox_limit_maps, 0, 0,
+	VAR_VIRT_MAILDIR_LIMIT_MESSAGE, DEF_VIRT_MAILDIR_LIMIT_MESSAGE, &var_virt_maildir_limit_message, 1, 0,
+	VAR_VIRT_MAILDIR_LIMIT_MESSAGE_MAPS, DEF_VIRT_MAILDIR_LIMIT_MESSAGE_MAPS, &var_virt_maildir_limit_message_maps, 0, 0,
+	VAR_VIRT_MAILDIR_SUFFIX, DEF_VIRT_MAILDIR_SUFFIX, &var_virt_maildir_suffix, 0, 0,
+	VAR_VIRT_TRASH_NAME, DEF_VIRT_TRASH_NAME, &var_virt_trash_name, 0, 0,
+	VAR_VIRT_MAILDIR_FILTER_MAPS, DEF_VIRT_MAILDIR_FILTER_MAPS, &var_virt_maildir_filter_maps, 0, 0,
 	0,
     };
     static const CONFIG_BOOL_TABLE bool_table[] = {
 	VAR_STRICT_MBOX_OWNER, DEF_STRICT_MBOX_OWNER, &var_strict_mbox_owner,
+	VAR_VIRT_MAILBOX_LIMIT_INBOX, DEF_VIRT_MAILBOX_LIMIT_INBOX, &var_virt_mailbox_limit_inbox,
+	VAR_VIRT_MAILBOX_LIMIT_OVERRIDE, DEF_VIRT_MAILBOX_LIMIT_OVERRIDE, &var_virt_mailbox_limit_override,
+	VAR_VIRT_MAILDIR_EXTENDED, DEF_VIRT_MAILDIR_EXTENDED, &var_virt_maildir_extended,
+	VAR_VIRT_OVERQUOTA_BOUNCE, DEF_VIRT_OVERQUOTA_BOUNCE, &var_virt_overquota_bounce,
+	VAR_VIRT_TRASH_COUNT, DEF_VIRT_TRASH_COUNT, &var_virt_trash_count,
+	VAR_VIRT_MAILDIR_FILTER, DEF_VIRT_MAILDIR_FILTER, &var_virt_maildir_filter,
 	0,
     };
 
@@ -530,6 +573,7 @@ int     main(int argc, char **argv)
 		       MAIL_SERVER_PRE_INIT, pre_init,
 		       MAIL_SERVER_POST_INIT, post_init,
 		       MAIL_SERVER_PRE_ACCEPT, pre_accept,
+                       MAIL_SERVER_BOOL_TABLE, bool_table,
 		       MAIL_SERVER_PRIVILEGED,
 		       0);
 }
--- src/virtual/virtual.h.orig	2006-01-07 23:59:47 UTC
+++ src/virtual/virtual.h
@@ -34,6 +34,9 @@
 extern MAPS *virtual_mailbox_maps;
 extern MAPS *virtual_uid_maps;
 extern MAPS *virtual_gid_maps;
+extern MAPS *virtual_mailbox_limit_maps;
+extern MAPS *virtual_maildir_limit_message_maps;
+extern MAPS *virtual_maildir_filter_maps;
 
  /*
   * User attributes: these control the privileges for delivery to external
