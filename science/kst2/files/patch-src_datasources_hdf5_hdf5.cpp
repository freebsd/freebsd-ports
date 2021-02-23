--- src/datasources/hdf5/hdf5.cpp.orig	2021-01-24 05:51:19 UTC
+++ src/datasources/hdf5/hdf5.cpp
@@ -308,7 +308,11 @@ herr_t HDF5Source::visitFunc(hid_t id, const char* nam
       return 0;
     }
 
+#if H5_VERSION_GE(1,12,0)
+    status = H5Oget_info_by_name(id, name, &infobuf, H5O_INFO_BASIC, H5P_DEFAULT);
+#else
     status = H5Oget_info_by_name(id, name, &infobuf, H5P_DEFAULT);
+#endif
     if(status == 0){
         if(infobuf.type == H5O_TYPE_DATASET){
             H5::DataSet dataset = h5Source->_hdfFile->openDataSet(name);
