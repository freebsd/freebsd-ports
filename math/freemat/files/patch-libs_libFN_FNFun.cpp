--- ./libs/libFN/FNFun.cpp.orig	2008-03-14 16:43:05.000000000 +0100
+++ ./libs/libFN/FNFun.cpp	2008-03-18 22:05:39.000000000 +0100
@@ -23,6 +23,15 @@
 #include "Malloc.hpp"
 #include <math.h>
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 800022
+float
+tgammaf(float x)
+{
+
+	return (tgamma(x));
+}
+#endif
+
 //!
 //@Module ERFC Complimentary Error Function
 //@@Section MATHFUNCTIONS
