--- Source/bmalloc/bmalloc/EligibilityResultInlines.h.orig	2024-08-19 06:28:40 UTC
+++ Source/bmalloc/bmalloc/EligibilityResultInlines.h
@@ -39,7 +39,7 @@ EligibilityResult<Config>::EligibilityResult(IsoPage<C
 
 template<typename Config>
 EligibilityResult<Config>::EligibilityResult(IsoPage<Config>* page)
-    : kind(EligibilityKind::Success)
+    : kind(EligibilityKind::BmSuccess)
     , page(page)
 {
 }
