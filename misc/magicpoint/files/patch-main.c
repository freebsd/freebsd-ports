--- contrib/xmindpath/main.c.orig	1998-09-30 23:58:17 UTC
+++ contrib/xmindpath/main.c
@@ -42,6 +42,10 @@
 #include <X11/X.h>
 #include <X11/extensions/XTest.h>
 #include <X11/keysym.h>
+#include <string.h>
+#include <err.h>
+#include <sys/types.h>
+#include <libutil.h>
 
 #ifdef X_DISPLAY_MISSING
 # error this program cannot be compiled without X11.
