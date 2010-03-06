--- coda-src/venus/user.cc
+++ coda-src/venus/user.cc
@@ -42,7 +42,6 @@
 #include <netinet/in.h>
 #include <errno.h>
 #include <struct.h>
-#include <utmp.h>
 #include <pwd.h>
 
 #include <rpc2/rpc2.h>
@@ -167,7 +166,7 @@
 
 int ConsoleUser(uid_t user)
 {
-#ifdef __CYGWIN32__
+#if 1
     return(1);
 
 #elif defined(__linux__)
