--- Lib/System.cpp.orig	2018-12-01 20:15:38 UTC
+++ Lib/System.cpp
@@ -27,9 +27,13 @@
 #include <stdlib.h>
 #  include <unistd.h>
 #  if !__APPLE__ && !__CYGWIN__
-#    include <sys/prctl.h>
+//#    include <sys/prctl.h>
 #  endif
 
+#if defined (__FreeBSD__)
+#include <sys/wait.h>
+#endif
+
 #include <dirent.h>
 
 #include <cerrno>
@@ -360,7 +364,7 @@ void System::terminateImmediately(int re
  */
 void System::registerForSIGHUPOnParentDeath()
 {
-#if __APPLE__ || __CYGWIN__
+#if __APPLE__ || __CYGWIN__ || __FreeBSD__
   // cerr<<"Death of parent process not being handled on Mac and Windows"<<endl;
   // NOT_IMPLEMENTED;
 #else
