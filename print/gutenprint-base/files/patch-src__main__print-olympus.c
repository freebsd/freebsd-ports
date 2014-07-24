--- ./src/main/print-olympus.c.orig	2014-05-14 22:18:36.000000000 -0300
+++ ./src/main/print-olympus.c	2014-07-22 15:47:50.000000000 -0300
@@ -4901,13 +4901,13 @@
   }
 
   if (pv.bytes_per_ink_channel > 1) {
-#if defined(__LITTLE_ENDIAN) || defined(__LITTLE_ENDIAN__)
+#if __BYTE_ORDER == __LITTLE_ENDIAN
     pv.byteswap = dyesub_feature(caps, DYESUB_FEATURE_BIGENDIAN);
-#elif defined (__BIG_ENDIAN) || defined(__BIG_ENDIAN__)
+#elif __BYTE_ORDER == __BIG_ENDIAN
     pv.byteswap = !dyesub_feature(caps, DYESUB_FEATURE_BIGENDIAN);
 #else
 #error "Unable to determine endianness, aborting compilation!"
-#endif    
+#endif
   }
 
   pv.image_data = dyesub_read_image(v, &pv, image);
