Index: Source/bmalloc/bmalloc/AvailableMemory.h
--- Source/bmalloc/bmalloc/AvailableMemory.h.orig
+++ Source/bmalloc/bmalloc/AvailableMemory.h
@@ -32,7 +32,7 @@ namespace bmalloc {
 
 BEXPORT size_t availableMemory();
 
-#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD)
+#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD) || BOS(OPENBSD)
 struct MemoryStatus {
     MemoryStatus(size_t memoryFootprint, double percentAvailableMemoryInUse)
         : memoryFootprint(memoryFootprint)
@@ -61,7 +61,7 @@ inline double percentAvailableMemoryInUse()
 
 inline bool isUnderMemoryPressure()
 {
-#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD)
+#if BPLATFORM(IOS_FAMILY) || BOS(LINUX) || BOS(FREEBSD) || BOS(OPENBSD)
     return percentAvailableMemoryInUse() > memoryPressureThreshold;
 #else
     return false;
