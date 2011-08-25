--- mozilla/toolkit/xre/glxtest.cpp.orig	2011-08-19 18:57:10.604870746 +0300
+++ mozilla/toolkit/xre/glxtest.cpp	2011-08-19 18:59:43.620447963 +0300
@@ -51,6 +51,8 @@
 // which runs the glxtest() static function. This creates a X connection, a GLX context, calls glGetString, and writes that
 // to the 'write' end of the pipe.

+#include <sys/types.h>
+#include <sys/wait.h>
 #include <cstdio>
 #include <cstdlib>
 #include <unistd.h>
@@ -224,6 +226,7 @@
 void fire_glxtest_process()
 {
   int pfd[2];
+  int status;
   if (pipe(pfd) == -1) {
       perror("pipe");
       exit(EXIT_FAILURE);
@@ -244,4 +247,5 @@
   close(pfd[1]);
   mozilla::widget::glxtest_pipe = pfd[0];
   mozilla::widget::glxtest_pid = pid;
+  waitpid(pid, &status, 0);
 }
