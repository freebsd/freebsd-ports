--- libi2pd_client/BOB.cpp.orig	2019-06-07 14:25:55 UTC
+++ libi2pd_client/BOB.cpp
@@ -4,6 +4,8 @@
 #include "util.h"
 #include "BOB.h"
 
+#undef isset  // Prevent clash with isset macro from param.h
+
 namespace i2p
 {
 namespace client
