--- gptcurses.cc.orig	2020-02-17 22:34:11 UTC
+++ gptcurses.cc
@@ -23,7 +23,7 @@
 #include <iostream>
 #include <string>
 #include <sstream>
-#ifdef __APPLE__
+#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__) || defined (__APPLE__)
 #include <ncurses.h>
 #else
 #include <ncursesw/ncurses.h>
