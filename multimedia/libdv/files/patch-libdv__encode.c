--- libdv/encode.c.orig	Thu Dec 14 23:24:41 2006
+++ libdv/encode.c	Thu Dec 14 23:25:20 2006
@@ -513,8 +513,7 @@
 	emms();
 #else	
 	for (i = 0; i < 64; i++) {
-	  //		*(unsigned short*) ((char*) zigzag + reorder[i])=bl->coeffs[i];
-	  zigzag[reorder[i] - 1] = bl->coeffs[i];
+	  *(unsigned short*) ((char*) zigzag + reorder[i])=bl->coeffs[i];
 	}
 	memcpy(bl->coeffs, zigzag, 64 * sizeof(dv_coeff_t));
 #endif
