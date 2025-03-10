--- Source/bmalloc/bmalloc/EligibilityResult.h.orig	2024-08-19 06:28:40 UTC
+++ Source/bmalloc/bmalloc/EligibilityResult.h
@@ -32,7 +32,7 @@ enum class EligibilityKind {
 namespace bmalloc {
 
 enum class EligibilityKind {
-    Success,
+    BmSuccess,
     Full,
     OutOfMemory
 };
@@ -44,7 +44,7 @@ struct EligibilityResult {
     EligibilityResult(EligibilityKind);
     EligibilityResult(IsoPage<Config>*);
     
-    EligibilityKind kind { EligibilityKind::Success };
+    EligibilityKind kind { EligibilityKind::BmSuccess };
     IsoPage<Config>* page { nullptr };
 };
 
