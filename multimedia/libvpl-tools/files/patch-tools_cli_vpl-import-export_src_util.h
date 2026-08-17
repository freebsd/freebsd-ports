--- tools/cli/vpl-import-export/src/util.h.orig	2026-06-25 23:06:43 UTC
+++ tools/cli/vpl-import-export/src/util.h
@@ -24,7 +24,7 @@
 #include <windows.h>
 #include <windowsx.h>

-#elif defined __linux__
+#elif defined __unix__

 #include <fcntl.h>
 #include <unistd.h>
