--- src/datasources/hdf5/hdf5.h.orig	2022-02-16 19:03:30 UTC
+++ src/datasources/hdf5/hdf5.h
@@ -11,14 +11,14 @@
  ***************************************************************************/
 
 
-#ifndef HDF5_H
-#define HDF5_H
+#ifndef KST2_HDF5_H
+#define KST2_HDF5_H
 
 #include <datasource.h>
 #include <dataplugin.h>
 
 #include <QFileInfo>
-#include <hdf5/serial/H5Cpp.h>
+#include <H5Cpp.h>
 #include <exception>
 
 #include "debug.h"
