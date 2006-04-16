$NetBSD: patch-by,v 1.2 2004/07/05 14:22:42 taya Exp $

diff -ru ../Orig/mozilla/layout/svg/renderer/src/libart/nsSVGLibartGlyphMetricsFT.cpp ./layout/svg/renderer/src/libart/nsSVGLibartGlyphMetricsFT.cpp
--- ../Orig/mozilla/layout/svg/renderer/src/libart/nsSVGLibartGlyphMetricsFT.cpp	2004-03-19 10:36:16.000000000 +0900
+++ ./layout/svg/renderer/src/libart/nsSVGLibartGlyphMetricsFT.cpp	2004-07-04 22:59:19.000000000 +0900
@@ -155,15 +155,15 @@
 
   static NS_NAMED_LITERAL_STRING(arial, "arial");
   nsSVGLibartGlyphMetricsFT::sFontAliases.Put(NS_LITERAL_STRING("helvetica"),
-                                              &arial);
+                                              (nsDependentString *)&arial);
 
   static NS_NAMED_LITERAL_STRING(courier, "courier new");
   nsSVGLibartGlyphMetricsFT::sFontAliases.Put(NS_LITERAL_STRING("courier"),
-                                              &courier);
+                                              (nsDependentString *)&courier);
 
   static NS_NAMED_LITERAL_STRING(times, "times new roman");
   nsSVGLibartGlyphMetricsFT::sFontAliases.Put(NS_LITERAL_STRING("times"),
-                                              &times);
+                                              (nsDependentString *)&times);
 }
 
 void NS_FreeSVGLibartGlyphMetricsFTGlobals()
@@ -440,19 +440,19 @@
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
 
