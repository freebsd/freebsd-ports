--- src/prc.cpp.orig	2021-12-08 05:59:55 UTC
+++ src/prc.cpp
@@ -36,6 +36,7 @@
 #include <hpdf.h>
 #include <hpdf_u3d.h>
 #include <hpdf_annotation.h>
+#include <hpdf_version.h>
 #endif // MGL_HAVE_PDF
 
 
@@ -959,7 +960,12 @@ void MGL_EXPORT mgl_write_prc(HMGL gr, const char *fna
 		HPDF_U3D_SetDefault3DView(u3d, "DefaultView");
 
 		//	Create annotation
-		annot = HPDF_Page_Create3DAnnot (page, rect, u3d );
+		annot
+		#if HPDF_VERSION_ID >= 20400
+		 = HPDF_Page_Create3DAnnot (page, rect, HPDF_FALSE, HPDF_FALSE, u3d, NULL);
+		#else
+		 = HPDF_Page_Create3DAnnot (page, rect, u3d);
+		#endif
 
 		//  Enable toolbar
 		HPDF_Dict action = (HPDF_Dict)HPDF_Dict_GetItem (annot, "3DA", HPDF_OCLASS_DICT);
