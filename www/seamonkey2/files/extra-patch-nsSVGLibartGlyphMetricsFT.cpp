--- layout/svg/renderer/src/libart/nsSVGLibartGlyphMetricsFT.cpp.orig	Sat Jul 24 23:59:16 2004
+++ layout/svg/renderer/src/libart/nsSVGLibartGlyphMetricsFT.cpp	Sun Jul 25 00:04:20 2004
@@ -56,6 +56,12 @@
 #include "nsArray.h"
 #include "nsDataHashtable.h"
 
+#ifdef HAVE_CPP_2BYTE_WCHAR_T
+  typedef nsDependentString nsLiteralString;
+#else
+  typedef NS_ConvertASCIItoUTF16 nsLiteralString;
+#endif
+
 /**
  * \addtogroup libart_renderer Libart Rendering Engine
  * @{
@@ -112,7 +118,7 @@
   nsCOMPtr<nsISVGGlyphMetricsSource> mSource;
     
 public:
-  static nsDataHashtable<nsStringHashKey,const nsDependentString*> sFontAliases;  
+  static nsDataHashtable<nsStringHashKey,const nsLiteralString*> sFontAliases;  
 };
 
 /** @} */
@@ -120,7 +126,7 @@
 //----------------------------------------------------------------------
 // nsSVGLibartGlyphMetricsFT implementation:
 
-nsDataHashtable<nsStringHashKey,const nsDependentString*>
+nsDataHashtable<nsStringHashKey,const nsLiteralString*>
 nsSVGLibartGlyphMetricsFT::sFontAliases;
 
 
@@ -406,7 +412,7 @@
   }
   else {
     // try alias if there is one:
-    const nsDependentString *alias = nsnull;
+    const nsLiteralString *alias = nsnull;
     nsSVGLibartGlyphMetricsFT::sFontAliases.Get(NS_ConvertUTF8toUCS2(family_name),
                                                 &alias);
     if (alias) {
