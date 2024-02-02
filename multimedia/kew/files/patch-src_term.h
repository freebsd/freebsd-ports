- workaround for https://github.com/ravachol/kew/issues/115

--- src/term.h.orig	2024-02-02 21:18:33 UTC
+++ src/term.h
@@ -4,7 +4,7 @@
 #define __USE_POSIX
 #endif
 #ifndef _POSIX_C_SOURCE
-#define _POSIX_C_SOURCE 200809L
+//#define _POSIX_C_SOURCE 200809L
 #endif
 #include <unistd.h>
 #include <termios.h>
