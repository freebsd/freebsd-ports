--- src/commands.c.orig	2025-09-18 19:33:52 UTC
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
@@ -970,7 +969,7 @@
         else if (dest_is_coll && src_is_coll) {
             /* Case 1. */
             char *tmp = ne_strndup(ops[n].src, strlen(ops[n].src)-1);
-            ops[n].dest = ne_concat(uri_dest, base_name(tmp), NULL);
+            ops[n].dest = ne_concat(uri_dest, basename(tmp), NULL);
             ne_free(tmp);
         }
         else if (src_is_coll && !dest_is_coll) {
@@ -980,7 +979,7 @@
         }
         else if (dest_is_coll) {
             /* Case 2. */
-            ops[n].dest = ne_concat(uri_dest, base_name(ops[n].src), NULL);
+            ops[n].dest = ne_concat(uri_dest, basename(ops[n].src), NULL);
         }
         else {
             /* Case 3. */
@@ -1044,7 +1043,7 @@
         filename = ne_strdup(native_local);
     }
     else {
-        filename = ne_strdup(base_name(native_remote));
+        filename = ne_strdup(basename(native_remote));
     }
 
     if (stat(filename, &st) == 0) {
@@ -1134,7 +1133,7 @@
 
 static void execute_put(const char *local, const char *remote)
 {
-    char *uri_path = uri_resolve_native(remote ? remote : base_name(local));
+    char *uri_path = uri_resolve_native(remote ? remote : basename(local));
     simple_put(local, uri_path);
     free(uri_path);
 }
