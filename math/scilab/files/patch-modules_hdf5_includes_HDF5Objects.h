--- modules/hdf5/includes/HDF5Objects.h.orig	2015-03-31 09:31:29 UTC
+++ modules/hdf5/includes/HDF5Objects.h
@@ -13,15 +13,13 @@
 #ifndef __HDF5OBJECTS_H__
 #define __HDF5OBJECTS_H__
 
-#define H5_NO_DEPRECATED_SYMBOLS
 #undef H5_USE_16_API
+#define H5_USE_18_API
 
 #define H5Eset_auto_vers 2
 #include <hdf5.h>
 #include <hdf5_hl.h>
 
-#undef H5_NO_DEPRECATED_SYMBOLS
-
 //#define __HDF5OBJECTS_DEBUG__
 //#define __HDF5ERROR_PRINT__
 
