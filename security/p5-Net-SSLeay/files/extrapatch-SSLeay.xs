--- SSLeay.xs.orig	Sat Dec 31 17:20:25 2005
+++ SSLeay.xs	Sat Dec 31 17:23:39 2005
@@ -94,6 +94,13 @@
 }
 #endif
 
+#ifndef XST_mPVN
+#define XST_mPVN(i,v,n) (ST(i) = sv_2mortal(newSVpvn(v,n)))
+#endif
+#ifndef XSRETURN_PVN
+#define XSRETURN_PVN(v,n) STMT_START { XST_mPVN(0,v,n);  XSRETURN(1); } STMT_END
+#endif
+
 /* OpenSSL-0.9.3a has some strange warning about this in
  *    openssl/des.h
  */
