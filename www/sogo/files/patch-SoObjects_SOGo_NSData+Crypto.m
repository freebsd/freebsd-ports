--- SoObjects/SOGo/NSData+Crypto.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/NSData+Crypto.m
@@ -23,7 +23,7 @@
  * Boston, MA 02111-1307, USA.
  */
 
-#ifndef __OpenBSD__
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <crypt.h>
 #endif
 
