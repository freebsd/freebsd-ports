--- src/apm.h.orig	2012-07-17 04:52:01 UTC
+++ src/apm.h
@@ -33,9 +33,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 /* I2C support */
 #include "xf86i2c.h"
 
