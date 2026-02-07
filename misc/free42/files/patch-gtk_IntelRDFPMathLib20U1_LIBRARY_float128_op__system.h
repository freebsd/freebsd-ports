--- gtk/IntelRDFPMathLib20U1/LIBRARY/float128/op_system.h.orig	2011-06-29 18:33:08 UTC
+++ gtk/IntelRDFPMathLib20U1/LIBRARY/float128/op_system.h
@@ -103,6 +103,24 @@
 #	define OP_SYSTEM linux
 
 
+#elif (defined(__FreeBSD__))
+
+#	undef  dos
+#	undef  vms
+#	undef  wnt
+#	undef  osf
+#	undef  hp_ux
+#	undef  linux
+#	undef  unicos
+#	undef  ultrix
+#       undef  win64
+#       undef  darwin 
+#       undef  interix 
+
+#	define linux 8
+#	define OP_SYSTEM freebsd
+
+
 #elif (defined(osf) || defined(OSF) || defined(__osf__))
 
 
