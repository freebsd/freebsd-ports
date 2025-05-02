--- src/commands.c.orig	2025-05-02 18:23:47 UTC
+++ src/commands.c
@@ -74,8 +74,7 @@
 #include <ne_dates.h>
 
 #include "i18n.h"
-#include "basename.h"
-#include "dirname.h"
+#include <libgen.h>
 #include "cadaver.h"
 #include "commands.h"
 #include "options.h"
@@ -956,7 +955,7 @@ static void do_copymove(int argc, const char *argv[],
         else if (dest_is_coll && src_is_coll) {
             /* Case 1. */
             char *tmp = ne_strndup(ops[n].src, strlen(ops[n].src)-1);
-            ops[n].dest = ne_concat(uri_dest, base_name(tmp), NULL);
+            ops[n].dest = ne_concat(uri_dest, basename(tmp), NULL);
             ne_free(tmp);
         }
         else if (src_is_coll && !dest_is_coll) {
@@ -966,7 +965,7 @@ static void do_copymove(int argc, const char *argv[],
         }
         else if (dest_is_coll) {
             /* Case 2. */
-            ops[n].dest = ne_concat(uri_dest, base_name(ops[n].src), NULL);
+            ops[n].dest = ne_concat(uri_dest, basename(ops[n].src), NULL);
         }
         else {
             /* Case 3. */
@@ -1030,7 +1029,7 @@ static void execute_get(const char *native_remote, con
     else {
         struct stat st;
 
-        filename = ne_strdup(base_name(native_remote));
+        filename = ne_strdup(basename(native_remote));
 
         /* Choose an appropriate local filename */
         if (stat(filename, &st) == 0) {
@@ -1084,7 +1083,7 @@ static void execute_put(const char *local, const char 
 
 static void execute_put(const char *local, const char *remote)
 {
-    char *uri_path = uri_resolve_native(remote ? remote : base_name(local));
+    char *uri_path = uri_resolve_native(remote ? remote : basename(local));
     simple_put(local, uri_path);
     free(uri_path);
 }
--- src/edit.c.orig	2025-05-02 18:26:58 UTC
+++ src/edit.c
@@ -116,7 +116,7 @@ void execute_edit(const char *native_path)
     struct ne_lock *lock = NULL;
     char fname[PATH_MAX] = "/tmp/cadaver-edit-XXXXXX";
     const char *pnt;
-    int fd;
+    int fd, sufx_len;
     int is_checkout, is_checkin;
     
     uri_path = uri_resolve_native(native_path);
@@ -140,9 +140,11 @@ void execute_edit(const char *native_path)
     if (pnt != NULL && strchr(pnt, '/') == NULL) {
 	strncat(fname, pnt, PATH_MAX-1);
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
