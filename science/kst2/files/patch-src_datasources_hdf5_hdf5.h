--- src/datasources/hdf5/hdf5.h.orig	2024-08-25 02:15:46 UTC
+++ src/datasources/hdf5/hdf5.h
@@ -18,7 +18,7 @@
 #include <dataplugin.h>
 
 #include <QFileInfo>
-#include <hdf5/serial/H5Cpp.h>
+#include <H5Cpp.h>
 #include <exception>
 
 #include "debug.h"
