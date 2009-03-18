--- src/gpm-array-float.h.orig	2009-03-18 19:35:24.000000000 -0400
+++ src/gpm-array-float.h	2009-03-18 19:35:42.000000000 -0400
@@ -49,9 +49,9 @@ gfloat		 gpm_array_float_get_average		(G
 gboolean	 gpm_array_float_print			(GArray		*array);
 GArray		*gpm_array_float_convolve		(GArray		*data,
 							 GArray		*kernel);
-inline gfloat	 gpm_array_float_get			(GArray		*array,
+gfloat	 gpm_array_float_get			(GArray		*array,
 							 guint		 i);
-inline void	 gpm_array_float_set			(GArray		*array,
+void	 gpm_array_float_set			(GArray		*array,
 							 guint		 i,
 							 gfloat		 value);
 
