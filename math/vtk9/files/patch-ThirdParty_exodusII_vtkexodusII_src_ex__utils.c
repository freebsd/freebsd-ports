--- ThirdParty/exodusII/vtkexodusII/src/ex_utils.c.orig	2022-06-22 15:58:58.543731000 +0200
+++ ThirdParty/exodusII/vtkexodusII/src/ex_utils.c	2022-06-22 16:00:28.263448000 +0200
@@ -1770,7 +1770,9 @@
         */
 
         /* const int NC_SZIP_EC = 4; */ /* Selects entropy coding method for szip. */
+#if !defined(NC_SZIP_NN)
         const int NC_SZIP_NN = 32;      /* Selects nearest neighbor coding method for szip. */
+#endif
         /* Even and between 4 and 32; typical values are 8, 10, 16, 32 */
         const int SZIP_PIXELS_PER_BLOCK =
             file->compression_level == 0 ? 32 : file->compression_level;
