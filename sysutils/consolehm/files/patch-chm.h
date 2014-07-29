--- chm.h.orig	Wed May 31 19:42:57 2000
+++ chm.h	Mon Aug  1 04:41:00 2005
@@ -19,7 +19,7 @@
 #include <machine/cpufunc.h>
 
 #ifdef HAVE_SMBUS
-        #include <machine/smb.h>
+        #include <dev/smbus/smb.h>
         int SMBUS = 1;
 #else
         int SMBUS = 0;
