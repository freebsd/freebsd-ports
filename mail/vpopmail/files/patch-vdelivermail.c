--- vdelivermail.c.orig	Fri Sep  2 20:47:29 2005
+++ vdelivermail.c	Sun Jul  2 15:17:29 2006
@@ -66,6 +66,7 @@
 
 #define FILE_SIZE 156
 char loop_buf[FILE_SIZE];
+char spam_buf[FILE_SIZE];
 
 #define MSG_BUF_SIZE 5000
 char msgbuf[MSG_BUF_SIZE];
@@ -93,7 +94,10 @@
 void usernotfound(void);
 int is_loop_match( const char *dt, const char *address);
 int deliver_quota_warning(const char *dir, const char *q);
-
+#ifdef SPAM_THRESHOLD
+int is_spam(int threshold);
+int is_spam_match(char *xsl, int threshold);
+#endif
 
 /* print an error string and then exit
  * vexit() never returns, so vexiterr() and vexit() should actually return void
@@ -201,7 +205,7 @@
     if ( is_domain_valid(TheDomain) != 0 )
         vexiterr (EXIT_BOUNCE, "invalid domain name");
 
-    strncpy(TheUserFull, TheUser, sizeof(TheUserFull));
+    snprintf (TheUserFull, sizeof(TheUserFull), "%s", TheUser);
 
 #ifdef QMAIL_EXT
     /* !! Shouldn't this work its way backwards, and try all possibilities?
@@ -247,7 +251,7 @@
 
     /* check for wildcard if there's no match */
     if(tmpstr == NULL) {
-        for(i=strlen(TheUser);i >= 0 && j != 1;--i) {
+        for(i=strlen(TheUser);i > 0 && j != 1;--i) {
             if(TheUser[i-1]=='-') {
                 tmpuser[0] = '\0';
                 strncat(tmpuser,TheUser,i); 
@@ -410,6 +414,8 @@
   char local_file_new[FILE_SIZE];
   size_t headerlen;
   int write_fd;
+  int nread;
+  int pim[2];
   char quota[80];
 
     headerlen = strlen (extra_headers);
@@ -434,6 +440,49 @@
         return(-2);
     }
 
+#ifdef SPAMC
+    /* fork the SpamAssassin client - patch by Alex Dupre */
+    if (!pipe(pim)) {
+        pid = vfork();
+        switch (pid) {
+            case -1:
+                close(pim[0]);
+                close(pim[1]);
+                break;
+            case 0:
+                close(pim[0]);
+                dup2(pim[1], 1);
+                close(pim[1]);
+                if (execl(SPAMC, SPAMC, "-u", maildir_to_email(maildir), 0) == -1) {
+                    while ((nread = read(0, msgbuf, MSG_BUF_SIZE)) > 0)
+                        write(1, msgbuf, nread);
+                    _exit(0);
+                }
+        }
+        close(pim[1]);
+        dup2(pim[0], 0);
+        close(pim[0]);
+    }
+#ifdef SPAM_THRESHOLD
+    /* silently delete message if spam level > SPAM_THRESHOLD */
+    if (is_spam(SPAM_THRESHOLD) == 1) {
+        close(write_fd);
+        unlink(local_file_tmp);
+        return 0;
+    }
+
+#ifdef MAKE_SEEKABLE
+    if (!Seekable(0))
+        MakeSeekable(stdin);
+#endif
+
+    if (lseek(0, 0L, SEEK_SET) < 0) {
+        printf("lseek errno=%d\n", errno);
+        return -2;
+    }
+#endif
+#endif
+
     if (fdcopy (write_fd, read_fd, extra_headers, headerlen) != 0) {
         /* Did the write fail because we were over quota? */
         if ( errno == EDQUOT ) {
@@ -547,10 +596,10 @@
             if (user_over_maildirquota(address,format_maildirquota(quota))==1) {
 
                 /* check for over quota message in domain */
-                sprintf(tmp_file, "%s/.over-quota.msg",TheDomainDir);
+                snprintf(tmp_file, sizeof(tmp_file), "%s/.over-quota.msg",TheDomainDir);
                 if ( (fs=fopen(tmp_file, "r")) == NULL ) {
                     /* if no domain over quota then check in vpopmail dir */
-                    sprintf(tmp_file, "%s/%s/.over-quota.msg",VPOPMAILDIR,DOMAINS_DIR);
+                    snprintf(tmp_file, sizeof(tmp_file), "%s/%s/.over-quota.msg",VPOPMAILDIR,DOMAINS_DIR);
                     fs=fopen(tmp_file, "r");
                 }
 
@@ -577,10 +626,10 @@
         if (domain_over_maildirquota(address)==1)
         {
             /* check for over quota message in domain */
-            sprintf(tmp_file, "%s/.over-quota.msg",TheDomainDir);
+            snprintf(tmp_file, sizeof(tmp_file), "%s/.over-quota.msg",TheDomainDir);
             if ( (fs=fopen(tmp_file, "r")) == NULL ) {
                 /* if no domain over quota then check in vpopmail dir */
-                sprintf(tmp_file, "%s/%s/.over-quota.msg",VPOPMAILDIR,DOMAINS_DIR);
+                snprintf(tmp_file, sizeof(tmp_file), "%s/%s/.over-quota.msg",VPOPMAILDIR,DOMAINS_DIR);
                 fs=fopen(tmp_file, "r");
             }
 
@@ -769,6 +818,7 @@
      printf("Unable to fork: %d.", errno); 
      vexit(EXIT_DEFER);
    case 0:
+     setenv("SHELL", "/bin/sh", 1);
      args[0] = "/bin/sh"; args[1] = "-c"; args[2] = prog; args[3] = 0;
      sig_catch(SIGPIPE,SIG_DFL);
      execv(*args,args);
@@ -824,9 +874,13 @@
 
         /* if we find the line, return error (looping) */
         if (is_loop_match(loop_buf, address)==1 ) {
+            /* seek to the end of stdin */
+            fseek(stdin, 0L, SEEK_END);
             /* return the loop found */
             return(1);
         } else if (*loop_buf == '\r' || *loop_buf == '\n') {
+            /* seek to the end of stdin */
+            fseek(stdin, 0L, SEEK_END);
             /* end of headers return not found looping message value */
             return(0);
         }
@@ -943,10 +997,10 @@
       FILE *fs;
       char tmp_file[256];
 
-        sprintf(tmp_file, "%s/.no-user.msg",TheDomainDir);
+        snprintf(tmp_file, sizeof(tmp_file), "%s/.no-user.msg",TheDomainDir);
         if ( (fs=fopen(tmp_file, "r")) == NULL ) {
             /* if no domain no user then check in vpopmail dir */
-            sprintf(tmp_file, "%s/%s/.no-user.msg",VPOPMAILDIR,DOMAINS_DIR);
+            snprintf(tmp_file, sizeof(tmp_file), "%s/%s/.no-user.msg",VPOPMAILDIR,DOMAINS_DIR);
             fs=fopen(tmp_file, "r");
         }
         if ( fs == NULL ) {
@@ -993,7 +1047,7 @@
  struct stat     sb;
  char quotawarnmsg[BUFF_SIZE];
 
-    sprintf (quotawarnmsg, "%s%s", dir, "/quotawarn");
+    snprintf (quotawarnmsg, sizeof(quotawarnmsg), "%s%s", dir, "/quotawarn");
     time(&tm);
 
     /* Send only one warning every 24 hours */
@@ -1011,12 +1065,12 @@
     close(fd);
 
     /* Look in the domain for a .quotawarn.msg */
-    sprintf(quotawarnmsg, "%s/.quotawarn.msg", TheDomainDir);
+    snprintf(quotawarnmsg, sizeof(quotawarnmsg), "%s/.quotawarn.msg", TheDomainDir);
     if ( ((read_fd = open(quotawarnmsg, O_RDONLY)) < 0) || 
            (stat(quotawarnmsg, &sb) != 0)) {
 
         /* if that fails look in vpopmail dir */
-        sprintf(quotawarnmsg, "%s/%s/.quotawarn.msg", VPOPMAILDIR, DOMAINS_DIR);
+        snprintf(quotawarnmsg, sizeof(quotawarnmsg), "%s/%s/.quotawarn.msg", VPOPMAILDIR, DOMAINS_DIR);
         if ( ((read_fd = open(quotawarnmsg, O_RDONLY)) < 0) || 
               (stat(quotawarnmsg, &sb) != 0)) {
             return 0;
@@ -1057,3 +1111,97 @@
 
     return (strcasecmp (compare, (dt+14)) == 0);
 }
+
+#ifdef SPAM_THRESHOLD
+/* Check for a spam message
+ * This is done by checking for a matching line
+ * in the email headers for X-Spam-Level: which
+ * we put in each spam email
+ *
+ * Return 1 if spam
+ * Return 0 if not spam
+ * Return -1 on error
+ */
+int is_spam(int threshold)
+{
+ int i;
+ int found;
+
+#ifdef MAKE_SEEKABLE
+    if (!Seekable(0))
+        MakeSeekable(stdin);
+#endif
+
+    if ( lseek(0, 0L, SEEK_SET) < 0 ) {
+        printf("lseek errno=%d\n", errno);
+        return(-1);
+    }
+
+    while (fgets(spam_buf, sizeof(spam_buf), stdin) != NULL){
+
+        /* if we find the line, return error (looping) */
+        if (strncmp(spam_buf, "X-Spam-Level: ", 14) == 0 &&
+            is_spam_match(spam_buf, threshold) ==1) {
+
+            /* seek to the end of stdin */
+            lseek(0, 0L, SEEK_END);
+
+            /* return the spam found */
+            return(1);
+
+            /* check for the start of the body, we only need
+            * to check the headers.
+            */
+        } else {
+
+            /* walk through the charaters in the body */
+            for (i = 0, found = 0; spam_buf[i] != 0 && found == 0; ++i) {
+                switch(spam_buf[i]) {
+
+                    /* skip blank spaces and new lines */
+                    case ' ':
+                    case '\n':
+                    case '\t':
+                    case '\r':
+                        break;
+
+                    /* found a non blank, so we are still
+                    * in the headers
+                    */
+                    default:
+
+                        /* set the found non blank char flag */
+                        found = 1;
+                        break;
+                }
+            }
+
+            /* if the line only had blanks, then it is the
+             * delimiting line between the headers and the
+             * body. We don't need to check the body for
+             * the X-Spam-Level: line. Hence, we
+             * are done with our search and can return the
+             * spam not found value
+            */
+            if (found == 0) {
+                /* seek to the end of stdin */
+                lseek(0, 0L, SEEK_END);
+                /* return not found spam message value */
+                return(0);
+            }
+        }
+    }
+
+    /* if we get here then there is either no body
+     * or SpamAssassin drop it, so mark the message
+     * as spam.
+     */
+    return(1);
+}
+
+int is_spam_match(char *xsl, int threshold)
+{
+    if (strlen(xsl) - strlen("X-Spam-Level: ") > threshold) return(1);
+    else return(0);
+}
+#endif
