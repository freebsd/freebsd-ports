--- libsrc4/nc4hdf.c.orig	2008-06-10 23:38:34.000000000 +0800
+++ libsrc4/nc4hdf.c	2008-12-04 00:10:23.755371693 +0800
@@ -465,6 +465,9 @@
    int need_to_extend = 0, fill_value_recs = 0;
    int scalar = 0, retval = NC_NOERR, range_error = 0, i, d2;
    void *bufr = NULL;
+#ifdef HDF5_CONVERT
+   H5T_conv_except_func_t except_func;
+#endif
 #ifndef HDF5_CONVERT   
    int need_to_convert = 0;
    size_t len = 1;
