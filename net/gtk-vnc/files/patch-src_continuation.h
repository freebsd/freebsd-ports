--- src/continuation.h.orig	2007-12-16 13:58:18.000000000 -0500
+++ src/continuation.h	2007-12-16 13:58:39.000000000 -0500
@@ -11,6 +11,7 @@
 #ifndef _CONTINUATION_H_
 #define _CONTINUATION_H_
 
+#include <sys/types.h>
 #include <ucontext.h>
 
 struct continuation
