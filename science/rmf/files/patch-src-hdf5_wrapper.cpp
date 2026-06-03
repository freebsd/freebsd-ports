--- src/hdf5_wrapper.cpp.orig	2026-04-29 23:05:31 UTC
+++ src/hdf5_wrapper.cpp
@@ -149,7 +149,7 @@ hid_t get_parameters() {
   RMF_HDF5_CALL(H5Pset_libver_bounds(plist, H5F_LIBVER_V18, H5F_LIBVER_LATEST));
 #elif defined(H5_VERS_MAJOR) && \
     H5_VERS_MAJOR == 1 && H5_VERS_MINOR == 8 && H5_VERS_RELEASE >= 6
-  RMF_HDF5_CALL(H5Pset_libver_bounds(plist, H5F_LIBVER_18, H5F_LIBVER_LATEST));
+  RMF_HDF5_CALL(H5Pset_libver_bounds(plist, H5F_LIBVER_V18, H5F_LIBVER_LATEST));
 #endif
   return plist;
 }
