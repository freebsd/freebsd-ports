--- src/FLTK/fl_funcs.cpp.orig	2024-03-16 22:11:54.230417000 +0100
+++ src/FLTK/fl_funcs.cpp	2024-03-16 22:12:06.912058000 +0100
@@ -19,6 +19,7 @@
 #include <signal.h>
 #include <time.h>
 #include <sys/stat.h>
+#include <sys/syslimits.h>
 
 #ifndef WIN32
 #include <sys/wait.h>
