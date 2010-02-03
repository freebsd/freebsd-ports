--- common/common.h.orig	2010-02-03 17:25:48.378388768 +0100
+++ common/common.h	2010-02-03 17:26:24.401327942 +0100
@@ -634,3 +634,5 @@
 
 #endif
 
+#define	M_LOG2_E	0.693147180559945309417
+#define	log2f(x)	(logf (x) / (float) M_LOG2_E)
