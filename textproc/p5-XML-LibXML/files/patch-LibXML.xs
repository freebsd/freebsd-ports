--- LibXML.xs.orig	2003-12-22 10:38:06.000000000 -0500
+++ LibXML.xs	2003-12-22 10:38:12.000000000 -0500
@@ -64,20 +64,6 @@
 }
 #endif
 
-#ifdef VMS
-extern int xmlDoValidityCheckingDefaultVal;
-#define xmlDoValidityCheckingDefaultValue xmlDoValidityCheckingDefaultVal
-extern int xmlSubstituteEntitiesDefaultVal;
-#define xmlSubstituteEntitiesDefaultValue xmlSubstituteEntitiesDefaultVal
-#else
-LIBXML_DLL_IMPORT extern int xmlDoValidityCheckingDefaultValue;
-LIBXML_DLL_IMPORT extern int xmlSubstituteEntitiesDefaultValue;
-#endif
-LIBXML_DLL_IMPORT extern int xmlGetWarningsDefaultValue;
-LIBXML_DLL_IMPORT extern int xmlKeepBlanksDefaultValue;
-LIBXML_DLL_IMPORT extern int xmlLoadExtDtdDefaultValue;
-LIBXML_DLL_IMPORT extern int xmlPedanticParserDefaultValue;
-
 #define TEST_PERL_FLAG(flag) \
     SvTRUE(perl_get_sv(flag, FALSE)) ? 1 : 0
 
