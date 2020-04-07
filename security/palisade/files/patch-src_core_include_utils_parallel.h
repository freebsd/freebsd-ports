Backport of the patch fixing build: https://gitlab.com/palisade/palisade-development/-/commit/7a6c36e61fb060dc592357b99916a88467022325
The upstream patch doesn't apply due to other incompatible chages.

--- src/core/include/utils/parallel.h.orig	2020-04-07 23:38:54 UTC
+++ src/core/include/utils/parallel.h
@@ -56,7 +56,7 @@ namespace lbcrypto {
     // @Brief returns current number of threads that are usable
     // @return int # threads
     int GetNumThreads() {
-      int out, nthreads, tid;
+      int out = 0, nthreads = 0, tid;
 	  	
       // Fork a team of threads giving them their own copies of variables
       //so we can see how many threads we have to work with
