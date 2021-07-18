--- src/hdf5_wrapper.cpp.orig	2021-04-19 19:25:22 UTC
+++ src/hdf5_wrapper.cpp
@@ -150,7 +150,7 @@ hid_t get_parameters() {
   RMF_HDF5_CALL(H5Pset_libver_bounds(plist, H5F_LIBVER_V18, H5F_LIBVER_LATEST));
 #elif defined(H5_VERS_MAJOR) && \
     H5_VERS_MAJOR == 1 && H5_VERS_MINOR == 8 && H5_VERS_RELEASE >= 6
-  RMF_HDF5_CALL(H5Pset_libver_bounds(plist, H5F_LIBVER_18, H5F_LIBVER_LATEST));
+  RMF_HDF5_CALL(H5Pset_libver_bounds(plist, H5F_LIBVER_V18, H5F_LIBVER_LATEST));
 #endif
   return plist;
 }
