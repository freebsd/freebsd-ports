--- spnksocket.hpp.orig	2008-02-18 12:21:26.000000000 +0800
+++ spnksocket.hpp	2008-02-18 12:21:43.000000000 +0800
@@ -6,6 +6,7 @@
 #ifndef __spnksocket_hpp__
 #define __spnksocket_hpp__
 
+#include <sys/time.h>
 #include <sys/socket.h>
 
 class SP_NKSocket {
