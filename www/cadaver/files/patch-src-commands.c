--- src/commands.c	2008-11-11 03:40:54.000000000 -0500
+++ src/commands.c	2010-04-16 14:31:42.000000000 -0400
@@ -71,6 +71,5 @@
 
 #include "i18n.h"
-#include "basename.h"
-#include "dirname.h"
+#include <libgen.h>
 #include "cadaver.h"
 #include "commands.h"
@@ -765,9 +764,9 @@
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
@@ -775,5 +774,5 @@
 	 * be the basename of file concated with the collection. */
 	char *tmp = resolve_path(p, dest, true);
-        char *enc = escape_path(base_name(src));
+        char *enc = escape_path(basename(src));
 	ret = ne_concat(tmp, enc, NULL);
         free(enc);
@@ -950,5 +949,5 @@
 	struct stat st;
 	/* Choose an appropriate local filename */
-	if (stat(base_name(remote), &st) == 0) {
+	if (stat(basename(remote), &st) == 0) {
 	    char buf[BUFSIZ];
 	    /* File already exists... don't overwrite */
@@ -962,5 +961,5 @@
 	    }
 	} else {
-	    filename = ne_strdup(base_name(remote));
+	    filename = ne_strdup(basename(remote));
 	}
     } else {
@@ -1004,5 +1003,5 @@
     char *real_remote;
     if (remote == NULL) {
-	real_remote = resolve_path(session.uri.path, base_name(local), false);
+	real_remote = resolve_path(session.uri.path, basename(local), false);
     } else {
 	real_remote = resolve_path(session.uri.path, remote, false);
--- src/edit.c	2008-10-24 07:36:41.000000000 -0400
+++ src/edit.c	2010-04-16 14:37:24.000000000 -0400
@@ -117,5 +117,5 @@
     char fname[PATH_MAX] = "/tmp/cadaver-edit-XXXXXX";
     const char *pnt;
-    int fd;
+    int fd, sufx_len;
     int is_checkout, is_checkin;
     
@@ -141,7 +141,9 @@
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
