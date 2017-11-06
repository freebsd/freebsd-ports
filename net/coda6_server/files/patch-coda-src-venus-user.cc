--- coda-src/venus/user.cc.orig	2007-08-01 18:31:21 UTC
+++ coda-src/venus/user.cc
@@ -42,7 +42,6 @@ extern "C" {
 #include <netinet/in.h>
 #include <errno.h>
 #include <struct.h>
-#include <utmp.h>
 #include <pwd.h>
 
 #include <rpc2/rpc2.h>
@@ -167,7 +166,7 @@ int AuthorizedUser(uid_t thisUser)
 
 int ConsoleUser(uid_t user)
 {
-#ifdef __CYGWIN32__
+#if 1
     return(1);
 
 #elif defined(__linux__)
