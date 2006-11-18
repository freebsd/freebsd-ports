--- extensions/transformiix/source/base/Double.cpp.orig	Thu Jan 30 09:26:46 2003
+++ extensions/transformiix/source/base/Double.cpp	Sun Nov 16 01:46:42 2003
@@ -51,10 +51,10 @@
 //A trick to handle IEEE floating point exceptions on FreeBSD - E.D.
 #ifdef __FreeBSD__
 #include <ieeefp.h>
-#ifdef __alpha__
-fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP;
-#else
+#if defined(__i386__)
 fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP|FP_X_DNML;
+#else
+fp_except_t allmask = FP_X_INV|FP_X_OFL|FP_X_UFL|FP_X_DZ|FP_X_IMP;
 #endif
 fp_except_t oldmask = fpsetmask(~allmask);
 #endif
@@ -75,22 +75,31 @@
 #define TX_DOUBLE_HI32_EXPMASK   0x7ff00000
 #define TX_DOUBLE_HI32_MANTMASK  0x000fffff
 
+union ui32dun {
+    PRUint32 i[2];
+    double d;
+};
+
 //-- Initialize Double related constants
 #ifdef IS_BIG_ENDIAN
-const PRUint32 nanMask[2] =    {TX_DOUBLE_HI32_EXPMASK | TX_DOUBLE_HI32_MANTMASK,
-                                0xffffffff};
-const PRUint32 infMask[2] =    {TX_DOUBLE_HI32_EXPMASK, 0};
-const PRUint32 negInfMask[2] = {TX_DOUBLE_HI32_EXPMASK | TX_DOUBLE_HI32_SIGNBIT, 0};
+const union ui32dun nanMask =
+    {{TX_DOUBLE_HI32_EXPMASK | TX_DOUBLE_HI32_MANTMASK, 0xffffffff}};
+const union ui32dun infMask =
+    {{TX_DOUBLE_HI32_EXPMASK, 0}};
+const union ui32dun negInfMask =
+    {{TX_DOUBLE_HI32_EXPMASK | TX_DOUBLE_HI32_SIGNBIT, 0}};
 #else
-const PRUint32 nanMask[2] =    {0xffffffff,
-                                TX_DOUBLE_HI32_EXPMASK | TX_DOUBLE_HI32_MANTMASK};
-const PRUint32 infMask[2] =    {0, TX_DOUBLE_HI32_EXPMASK};
-const PRUint32 negInfMask[2] = {0, TX_DOUBLE_HI32_EXPMASK | TX_DOUBLE_HI32_SIGNBIT};
+const union ui32dun nanMask =
+    {{0xffffffff, TX_DOUBLE_HI32_EXPMASK | TX_DOUBLE_HI32_MANTMASK}};
+const union ui32dun infMask =
+    {{0, TX_DOUBLE_HI32_EXPMASK}};
+const union ui32dun negInfMask =
+    {{0, TX_DOUBLE_HI32_EXPMASK | TX_DOUBLE_HI32_SIGNBIT}};
 #endif
 
-const double Double::NaN = *((double*)nanMask);
-const double Double::POSITIVE_INFINITY = *((double*)infMask);
-const double Double::NEGATIVE_INFINITY = *((double*)negInfMask);
+const double Double::NaN = nanMask.d;
+const double Double::POSITIVE_INFINITY = infMask.d;
+const double Double::NEGATIVE_INFINITY = negInfMask.d;
 
 /*
  * Determines whether the given double represents positive or negative
