--- layout/svg/renderer/src/libart/nsSVGLibartGlyphMetricsFT.cpp.orig	Thu Feb 26 02:13:35 2004
+++ layout/svg/renderer/src/libart/nsSVGLibartGlyphMetricsFT.cpp	Thu Feb 26 03:27:56 2004
@@ -56,6 +57,13 @@
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
@@ -112,7 +120,7 @@
   nsCOMPtr<nsISVGGlyphMetricsSource> mSource;
     
 public:
-  static nsDataHashtable<nsStringHashKey,nsDependentString*> sFontAliases;  
+  static nsDataHashtable<nsStringHashKey,nsLiteralString*> sFontAliases;  
 };
 
 /** @} */
@@ -120,7 +128,7 @@
 //----------------------------------------------------------------------
 // nsSVGLibartGlyphMetricsFT implementation:
 
-nsDataHashtable<nsStringHashKey,nsDependentString*>
+nsDataHashtable<nsStringHashKey,nsLiteralString*>
 nsSVGLibartGlyphMetricsFT::sFontAliases;
 
 
@@ -406,7 +414,7 @@
   }
   else {
     // try alias if there is one:
-    nsDependentString *alias = nsnull;
+    nsLiteralString *alias = nsnull;
     nsSVGLibartGlyphMetricsFT::sFontAliases.Get(NS_ConvertUTF8toUCS2(family_name),
                                                 &alias);
     if (alias) {
