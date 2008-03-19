--- Utilities/Xdmf/libsrc/XdmfDataDesc.cxx.orig	2008-03-09 00:31:13.000000000 +0800
+++ Utilities/Xdmf/libsrc/XdmfDataDesc.cxx	2008-03-09 00:32:42.000000000 +0800
@@ -347,7 +347,7 @@
 status = H5Sselect_elements( this->DataSpace,
         H5S_SELECT_SET,
          NElements,
-         ( const hsize_t **)HCoordinates);
+         ( const hsize_t *)HCoordinates);
 #else
 status = H5Sselect_elements( this->DataSpace,
         H5S_SELECT_SET,
