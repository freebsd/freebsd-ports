Build fix for clang.

  error: use of undeclared identifier 'pthread_mutex_lock'
  error: use of undeclared identifier 'pthread_mutex_unlock'
  error: use of undeclared identifier 'pthread_self'
  error: use of undeclared identifier 'pthread_mutex_init'
  error: use of undeclared identifier 'pthread_mutex_destroy'

--- kopete/protocols/jabber/googletalk/libjingle/talk/base/ssladapter.cc.orig	2013-11-04 01:20:09.000000000 +0200
+++ kopete/protocols/jabber/googletalk/libjingle/talk/base/ssladapter.cc	2013-11-04 01:20:20.000000000 +0200
@@ -29,6 +29,7 @@
 
 #ifdef POSIX
 extern "C" {
+#include <pthread.h>
 #include <unistd.h>
 }
 #endif
