
$FreeBSD: /tmp/pcvs/ports/net/mad_fcl/files/Attic/extra-patch-alclib_defines.h,v 1.1 2004-08-26 21:42:04 sem Exp $

--- alclib/defines.h.orig	Fri Jun 25 13:18:59 2004
+++ alclib/defines.h	Fri Jun 25 13:35:11 2004
@@ -29,7 +29,7 @@
 #define SSM
 
 /* Use ZLIB compression library */
-#define USE_ZLIB
+/*#define USE_ZLIB */
 
 /* Use  OpenSSL library for MD5*/
 #define USE_OPENSSL
