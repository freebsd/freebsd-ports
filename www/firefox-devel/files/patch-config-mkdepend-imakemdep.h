$FreeBSD$
  $MCom: ports/www/firefox-devel/files/patch-config-mkdepend-imakemdep.h,v 1.6 2005/07/14 05:25:44 ahze Exp $

--- config/mkdepend/imakemdep.h	Fri Sep  4 21:22:25 1998
+++ config/mkdepend/imakemdep.h	Thu Oct 16 22:43:25 2003
@@ -278,4 +278,7 @@
 	"-D__i386__",
 # endif
+# if defined(__amd64__) || defined(__x86_64__)
+	"-D__amd64__ -D__x86_64__",
+# endif
 # ifdef __GNUC__
 	"-traditional",
