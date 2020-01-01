--- src/hdf5_wrapper.cpp.orig	2019-10-16 16:05:15 UTC
+++ src/hdf5_wrapper.cpp
@@ -138,7 +138,7 @@ hid_t get_parameters() {
   RMF_HDF5_CALL(H5Pset_cache(plist, 0, 10000, 10000000, 0.0));
 #if defined(H5_VERS_MAJOR) && H5_VERS_MAJOR >= 1 && H5_VERS_MINOR >= 8 && \
     H5_VERS_RELEASE >= 6
-  RMF_HDF5_CALL(H5Pset_libver_bounds(plist, H5F_LIBVER_18, H5F_LIBVER_LATEST));
+  RMF_HDF5_CALL(H5Pset_libver_bounds(plist, H5F_LIBVER_V18, H5F_LIBVER_LATEST));
 #endif
   return plist;
 }
