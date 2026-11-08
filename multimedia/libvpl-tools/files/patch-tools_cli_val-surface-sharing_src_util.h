--- tools/cli/val-surface-sharing/src/util.h.orig	2026-06-25 23:06:43 UTC
+++ tools/cli/val-surface-sharing/src/util.h
@@ -23,7 +23,7 @@
     #include <windows.h>
     #include <windowsx.h>

-#elif defined __linux__
+#elif defined __unix__

     #include <fcntl.h>
     #include <unistd.h>
