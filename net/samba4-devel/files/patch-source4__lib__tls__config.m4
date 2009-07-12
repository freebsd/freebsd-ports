--- ./source4/lib/tls/config.m4.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./source4/lib/tls/config.m4	2009-07-12 02:39:36.000000000 +0000
@@ -10,8 +10,8 @@
     fi])
 
 
-if test x$use_gnutls = xauto && pkg-config --exists gnutls; then
-	SMB_EXT_LIB_FROM_PKGCONFIG(GNUTLS, gnutls < 2.6.0, 
+if test x$use_gnutls = xauto && $PKG_CONFIG --exists gnutls; then
+	SMB_EXT_LIB_FROM_PKGCONFIG(GNUTLS, gnutls, 
 							   [use_gnutls=yes], 
 							   [use_gnutls=no])
 fi
