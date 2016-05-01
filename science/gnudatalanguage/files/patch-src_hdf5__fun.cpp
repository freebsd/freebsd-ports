--- src/hdf5_fun.cpp.orig	2016-04-29 17:03:25 UTC
+++ src/hdf5_fun.cpp
@@ -348,7 +348,7 @@ namespace lib {
     SizeT nParam=e->NParam(1);
     hsize_t dims_out[MAXRANK];
 
-    hid_t h5a_id;
+    DLong h5a_id;
     e->AssureLongScalarPar(0, h5a_id);
     
     hid_t h5s_id = H5Aget_space(h5a_id);
@@ -402,7 +402,7 @@ namespace lib {
     SizeT nParam=e->NParam(1);
     hsize_t dims_out[MAXRANK];
 
-    hid_t h5d_id;
+    DLong h5d_id;
     e->AssureLongScalarPar(0, h5d_id);
     
     hid_t h5s_id = H5Dget_space(h5d_id);
