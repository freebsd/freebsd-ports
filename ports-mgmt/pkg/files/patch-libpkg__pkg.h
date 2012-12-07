--- ./libpkg/pkg.h.orig	2012-12-05 12:00:45.000000000 +0100
+++ ./libpkg/pkg.h	2012-12-07 17:13:11.533719154 +0100
@@ -37,10 +37,10 @@
 #include <sys/sbuf.h>
 #include <openssl/pem.h>
 
-#define PKGVERSION "1.0.2"
+#define PKGVERSION "1.0.3"
 /* PORTVERSION equivalent for proper pkg-static->ports-mgmt/pkg version comparison
  * in pkgdb_query_newpkgversion() */
-#define PKG_PORTVERSION "1.0.2"
+#define PKG_PORTVERSION "1.0.3_1"
 
 struct pkg;
 struct pkg_dep;
