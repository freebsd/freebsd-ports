--- src/SubProcess.cc.orig	2008-10-26 06:17:37.000000000 -0700
+++ src/SubProcess.cc	2009-11-19 23:58:03.399815119 -0800
@@ -22,6 +22,7 @@
 #if defined(__FreeBSD__)
 #include <libutil.h>
 #include <sys/ioctl.h>
+#include <termios.h>
 #elif defined(__OpenBSD__)
 #include <termios.h>
 #include <util.h>
