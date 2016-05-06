--- modules/hdf5/src/c/h5_readDataFromFile.c.orig	2015-03-31 09:31:29 UTC
+++ modules/hdf5/src/c/h5_readDataFromFile.c
@@ -10,7 +10,7 @@
 *
 */
 
-#define H5_NO_DEPRECATED_SYMBOLS
+#define H5_USE_18_API
 
 #ifndef _MSC_VER
 #include <sys/time.h>
