--- apps/topaz/include/grass_plucker.h.orig	2022-10-03 19:41:15 UTC
+++ apps/topaz/include/grass_plucker.h
@@ -122,7 +122,7 @@ using CubeIndex = NamedType<Int, CubeIndexTag>;
   inline constexpr Int max_n_vertices(31); 
   inline constexpr Int first_cube_index(Int(1) << max_n_vertices);
 */
-#define max_n_vertices 31
+#define max_n_vertices ((Int) sizeof(Int)*4-1)
 #define first_cube_index (CubeIndex(Int(1) << (2*max_n_vertices)))
 #define MAGIC_VERTEX_MULTIPLE 256
    
