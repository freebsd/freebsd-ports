--- VTK/ThirdParty/exodusII/vtkexodusII/src/ex_utils.c.orig	2022-03-11 22:19:30 UTC
+++ VTK/ThirdParty/exodusII/vtkexodusII/src/ex_utils.c
@@ -1770,11 +1770,11 @@ void ex__compress_variable(int exoid, int varid, int t
         */
 
         /* const int NC_SZIP_EC = 4; */ /* Selects entropy coding method for szip. */
-        const int NC_SZIP_NN = 32;      /* Selects nearest neighbor coding method for szip. */
+        const int NC_SZIP_NN_ = 32;      /* Selects nearest neighbor coding method for szip. */
         /* Even and between 4 and 32; typical values are 8, 10, 16, 32 */
         const int SZIP_PIXELS_PER_BLOCK =
             file->compression_level == 0 ? 32 : file->compression_level;
-        nc_def_var_szip(exoid, varid, NC_SZIP_NN, SZIP_PIXELS_PER_BLOCK);
+        nc_def_var_szip(exoid, varid, NC_SZIP_NN_, SZIP_PIXELS_PER_BLOCK);
 #else
         char errmsg[MAX_ERR_LENGTH];
         snprintf(errmsg, MAX_ERR_LENGTH,
