--- src/commands.c.orig	2022-10-30 10:46:52 UTC
+++ src/commands.c
@@ -70,8 +70,7 @@
 #include <ne_dates.h>
 
 #include "i18n.h"
-#include "basename.h"
-#include "dirname.h"
+#include <libgen.h>
 #include "cadaver.h"
 #include "commands.h"
 #include "options.h"
@@ -771,17 +770,17 @@ static char *clever_path(const char *p, const char *sr
     dest_is_coll = (dest[strlen(dest)-1] == '/');
     src_is_coll = (src[strlen(src)-1] == '/');
     if (strcmp(dest, ".") == 0) {
-	ret = resolve_path(p, base_name(src), false);
+	ret = resolve_path(p, basename(src), false);
     } else if (strcmp(dest, "..") == 0) {
 	char *parent;
 	parent = ne_path_parent(p);
-	ret = resolve_path(parent, base_name(src), false);
+	ret = resolve_path(parent, basename(src), false);
 	free(parent);
     } else if (!src_is_coll && dest_is_coll) {
 	/* Moving a file to a collection... the destination should
 	 * be the basename of file concated with the collection. */
 	char *tmp = resolve_path(p, dest, true);
-        char *enc = escape_path(base_name(src));
+        char *enc = escape_path(basename(src));
 	ret = ne_concat(tmp, enc, NULL);
         free(enc);
 	free(tmp);
@@ -979,7 +978,7 @@ static void execute_get(const char *remote, const char
     if (local == NULL) {
 	struct stat st;
 	/* Choose an appropriate local filename */
-	if (stat(base_name(remote), &st) == 0) {
+	if (stat(basename(remote), &st) == 0) {
 	    char buf[BUFSIZ];
 	    /* File already exists... don't overwrite */
 	    snprintf(buf, BUFSIZ, _("Enter local filename for `%s': "),
@@ -992,7 +991,7 @@ static void execute_get(const char *remote, const char
 		return;
 	    }
 	} else {
-	    filename = ne_strdup(base_name(remote));
+	    filename = ne_strdup(basename(remote));
 	}
     } else {
 	filename = ne_strdup(local);
@@ -1035,7 +1034,7 @@ static void execute_put(const char *local, const char 
 {
     char *real_remote;
     if (remote == NULL) {
-	real_remote = resolve_path(session.uri.path, base_name(local), false);
+	real_remote = resolve_path(session.uri.path, basename(local), false);
     } else {
 	real_remote = resolve_path(session.uri.path, remote, false);
     }
--- src/edit.c.orig	2022-10-30 10:46:52 UTC
+++ src/edit.c
@@ -116,7 +116,7 @@ void execute_edit(const char *remote)
     struct ne_lock *lock = NULL;
     char fname[PATH_MAX] = "/tmp/cadaver-edit-XXXXXX";
     const char *pnt;
-    int fd;
+    int fd, sufx_len;
     int is_checkout, is_checkin;
     
     real_remote = resolve_path(session.uri.path, remote, false);
@@ -140,9 +140,11 @@ void execute_edit(const char *remote)
     if (pnt != NULL && strchr(pnt, '/') == NULL) {
 	strncat(fname, pnt, PATH_MAX);
 	fname[PATH_MAX-1] = '\0';
-    }
+	sufx_len = strlen(pnt);
+    } else
+	sufx_len = 0;
 
-    fd = cad_mkstemp(fname);
+    fd = mkstemps(fname, sufx_len);
     if (fd == -1) {
 	printf(_("Could not create temporary file %s:\n%s\n"), fname,
 	       strerror(errno));
