--- Servers/Filters/vtkHDF5RawImageReader.cxx.orig	Mon Sep 13 10:47:52 2004
+++ Servers/Filters/vtkHDF5RawImageReader.cxx	Wed Jun  8 17:34:58 2005
@@ -294,7 +294,7 @@
   if(!(this->UpdateExtentIsWholeExtent() && (this->Stride[0] == 1) &&
       (this->Stride[1] == 1) && (this->Stride[2] == 1)))
     {
-    hssize_t h_start[3]  = {0,0,0};
+    hsize_t  h_start[3]  = {0,0,0};
     hsize_t  h_count[3]  = {0,0,0};
     hsize_t  h_stride[3] = {0,0,0};
     hsize_t  h_total[3]  = {0,0,0};
@@ -323,7 +323,7 @@
       result = 0;
       }
     hid_t memspace = H5Screate_simple(this->Rank, h_count, 0);
-    hssize_t moffset[3] = {0, 0, 0};
+    hsize_t moffset[3] = {0, 0, 0};
     if(H5Sselect_hyperslab(memspace, H5S_SELECT_SET,
                               moffset, 0, h_count, 0) < 0)
       {
