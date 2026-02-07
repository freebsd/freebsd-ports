--- xkb/ddxLoad.c.orig	2024-04-03 20:50:12 UTC
+++ xkb/ddxLoad.c
@@ -31,6 +31,7 @@ THE USE OR PERFORMANCE OF THIS SOFTWARE.
 #include <xkb-config.h>
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <X11/X.h>
 #include <X11/Xos.h>
@@ -70,9 +71,17 @@ OutputDirectory(char *outdir, size_t size)
     /* Can we write an xkm and then open it too? */
     if (access(XKM_OUTPUT_DIR, W_OK | X_OK) == 0) {
         directory = XKM_OUTPUT_DIR;
-        if (XKM_OUTPUT_DIR[strlen(XKM_OUTPUT_DIR) - 1] != '/')
-            pathsep = "/";
+    } else {
+        const char *xdg_runtime_dir = getenv("XDG_RUNTIME_DIR");
+
+        if (xdg_runtime_dir && xdg_runtime_dir[0] == '/' &&
+            access(xdg_runtime_dir, W_OK | X_OK) == 0)
+            directory = xdg_runtime_dir;
     }
+
+    if (directory && directory[strlen(directory) - 1] != '/')
+        pathsep = "/";
+
 #else
     directory = Win32TempDir();
     pathsep = "\\";
