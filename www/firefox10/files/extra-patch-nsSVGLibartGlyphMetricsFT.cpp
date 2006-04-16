--- layout/svg/renderer/src/libart/nsSVGLibartGlyphMetricsFT.cpp.orig	Wed Mar  2 12:36:59 2005
+++ layout/svg/renderer/src/libart/nsSVGLibartGlyphMetricsFT.cpp	Wed Mar  2 12:36:37 2005
@@ -56,6 +56,13 @@
 #include "nsArray.h"
 #include "nsDataHashtable.h"
 
+
+#ifdef HAVE_CPP_2BYTE_WCHAR_T
+  typedef nsDependentString nsLiteralString;
+#else
+  typedef NS_ConvertASCIItoUTF16 nsLiteralString;
+#endif
+
 /**
  * \addtogroup libart_renderer Libart Rendering Engine
  * @{
@@ -112,7 +119,7 @@
   nsCOMPtr<nsISVGGlyphMetricsSource> mSource;
     
 public:
-  static nsDataHashtable<nsStringHashKey,nsDependentString*> sFontAliases;  
+  static nsDataHashtable<nsStringHashKey,nsLiteralString*> sFontAliases;  
 };
 
 /** @} */
@@ -120,7 +127,7 @@
 //----------------------------------------------------------------------
 // nsSVGLibartGlyphMetricsFT implementation:
 
-nsDataHashtable<nsStringHashKey,nsDependentString*>
+nsDataHashtable<nsStringHashKey,nsLiteralString*>
 nsSVGLibartGlyphMetricsFT::sFontAliases;
 
 
@@ -155,15 +162,15 @@
 
   static NS_NAMED_LITERAL_STRING(arial, "arial");
   nsSVGLibartGlyphMetricsFT::sFontAliases.Put(NS_LITERAL_STRING("helvetica"),
-                                              &arial);
+                                              (nsLiteralString *)&arial);
 
   static NS_NAMED_LITERAL_STRING(courier, "courier new");
   nsSVGLibartGlyphMetricsFT::sFontAliases.Put(NS_LITERAL_STRING("courier"),
-                                              &courier);
+                                              (nsLiteralString *)&courier);
 
   static NS_NAMED_LITERAL_STRING(times, "times new roman");
   nsSVGLibartGlyphMetricsFT::sFontAliases.Put(NS_LITERAL_STRING("times"),
-                                              &times);
+                                              (nsLiteralString *)&times);
 }
 
 void NS_FreeSVGLibartGlyphMetricsFTGlobals()
@@ -406,7 +413,7 @@
   }
   else {
     // try alias if there is one:
-    nsDependentString *alias = nsnull;
+    nsLiteralString *alias = nsnull;
     nsSVGLibartGlyphMetricsFT::sFontAliases.Get(NS_ConvertUTF8toUCS2(family_name),
                                                 &alias);
     if (alias) {
@@ -440,19 +447,19 @@
     return;
   }
 
-  FTC_Image_Desc imageDesc;
-  imageDesc.font.face_id=(void*)font_data.font_entry.get(); // XXX do we need to addref?
+  FTC_ImageType imageDesc;
+  imageDesc->face_id = (FTC_FaceID)font_data.font_entry.get(); // XXX do we need to addref?
   float twipstopixel = GetTwipsToPixels();
   float scale = GetPixelScale();
-  imageDesc.font.pix_width = (int)((float)(font_data.font.size)*twipstopixel/scale);
-  imageDesc.font.pix_height = (int)((float)(font_data.font.size)*twipstopixel/scale);
-  imageDesc.image_type |= ftc_image_grays;
+  imageDesc->width = (int)((float)(font_data.font.size)*twipstopixel/scale);
+  imageDesc->height = (int)((float)(font_data.font.size)*twipstopixel/scale);
+  imageDesc->flags = 0;
 
   // get the face
   nsresult rv;
   FTC_Manager mgr;
   nsSVGLibartFreetype::ft2->GetFTCacheManager(&mgr);
-  rv = nsSVGLibartFreetype::ft2->ManagerLookupSize(mgr, &imageDesc.font, &mFace, nsnull);
+  rv = nsSVGLibartFreetype::ft2->ManagerLookupFace(mgr, imageDesc->face_id, &mFace);
   NS_ASSERTION(mFace, "failed to get face/size");
 }
 
