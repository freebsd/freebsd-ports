--- src/cares_wrap.h.orig	2023-05-16 06:58:21 UTC
+++ src/cares_wrap.h
@@ -23,7 +23,7 @@
 # include <netdb.h>
 #endif  // __POSIX__
 
-# include <ares_nameser.h>
+# include <arpa/nameser.h>
 
 namespace node {
 namespace cares_wrap {
