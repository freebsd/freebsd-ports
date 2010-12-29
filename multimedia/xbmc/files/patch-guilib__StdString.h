--- guilib/StdString.h.orig	2009-09-25 16:12:41.000000000 +0200
+++ guilib/StdString.h	2010-12-13 21:19:16.000000000 +0100
@@ -2,6 +2,7 @@
 #include <string>
 #include <stdint.h>
 #include <vector>
+#include <cstring>
 
 #if defined(_WIN32) && !defined(va_copy)
 #define va_copy(dst, src) ((dst) = (src))
@@ -864,7 +865,8 @@
       PWSTR pNextDstW      = pDstW;
       SSCodeCvt::result res  = SSCodeCvt::ok;
       const SSCodeCvt& conv  = SS_USE_FACET(loc, SSCodeCvt);
-      SSCodeCvt::state_type st= { 0 };
+      SSCodeCvt::state_type st;
+	  memset(&st, 0, sizeof(SSCodeCvt::state_type));
       res            = conv.in(st,
                     pSrcA, pSrcA + nSrc, pNextSrcA,
                     pDstW, pDstW + nDst, pNextDstW);
@@ -907,7 +909,8 @@
       PCWSTR pNextSrcW    = pSrcW;
       SSCodeCvt::result res  = SSCodeCvt::ok;
       const SSCodeCvt& conv  = SS_USE_FACET(loc, SSCodeCvt);
-      SSCodeCvt::state_type st= { 0 };
+      SSCodeCvt::state_type st;
+	  memset(&st, 0, sizeof(SSCodeCvt::state_type));
       res            = conv.out(st,
                     pSrcW, pSrcW + nSrc, pNextSrcW,
                     pDstA, pDstA + nDst, pNextDstA);
