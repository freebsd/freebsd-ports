--- config/mkdepend/imakemdep.h.orig	Tue Apr 20 14:38:14 2004
+++ config/mkdepend/imakemdep.h
@@ -440,6 +440,9 @@
 # ifdef __i386__
 	"-D__i386__",
 # endif
+# if defined(__amd64__) || defined(__x86_64__)
+	"-D__amd64__ -D__x86_64__",
+# endif
 # ifdef __GNUC__
 	"-traditional",
 # endif
