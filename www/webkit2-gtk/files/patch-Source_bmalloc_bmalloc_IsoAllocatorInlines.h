--- Source/bmalloc/bmalloc/IsoAllocatorInlines.h.orig	2024-08-19 06:28:40 UTC
+++ Source/bmalloc/bmalloc/IsoAllocatorInlines.h
@@ -76,7 +76,7 @@ BNO_INLINE void* IsoAllocator<Config>::allocateSlow(Is
     BASSERT(allocationMode == AllocationMode::Fast);
     
     EligibilityResult<Config> result = heap.takeFirstEligible(locker);
-    if (result.kind != EligibilityKind::Success) {
+    if (result.kind != EligibilityKind::BmSuccess) {
         RELEASE_BASSERT(result.kind == EligibilityKind::OutOfMemory);
         RELEASE_BASSERT(!abortOnFailure);
         return nullptr;
