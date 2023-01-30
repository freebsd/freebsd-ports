--- src/cares_wrap.h.orig	2021-08-18 22:13:12 UTC
+++ src/cares_wrap.h
@@ -22,7 +22,7 @@
 # include <netdb.h>
 #endif  // __POSIX__
 
-# include <ares_nameser.h>
+# include <arpa/nameser.h>
 
 namespace node {
 namespace cares_wrap {
