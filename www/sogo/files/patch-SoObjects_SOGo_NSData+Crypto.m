--- SoObjects/SOGo/NSData+Crypto.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/NSData+Crypto.m
@@ -23,10 +23,6 @@
  * Boston, MA 02111-1307, USA.
  */
 
-#ifndef __OpenBSD__
-#include <crypt.h>
-#endif
-
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
