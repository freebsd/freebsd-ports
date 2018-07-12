--- node_build/make.js.orig	2018-07-12 12:41:34 UTC
+++ node_build/make.js
@@ -29,7 +29,7 @@ var GCC = process.env['CC'];
 var CFLAGS = process.env['CFLAGS'];
 var LDFLAGS = process.env['LDFLAGS'];
 
-var NO_MARCH_FLAG = ['arm', 'ppc', 'ppc64'];
+var NO_MARCH_FLAG = ['arm', 'arm64', 'ppc', 'ppc64'];
 
 if (GCC) {
     // Already specified.
