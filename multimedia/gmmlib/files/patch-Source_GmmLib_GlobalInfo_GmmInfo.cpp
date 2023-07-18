--- Source/GmmLib/GlobalInfo/GmmInfo.cpp.orig	2023-07-18 11:43:35 UTC
+++ Source/GmmLib/GlobalInfo/GmmInfo.cpp
@@ -937,7 +937,7 @@ int32_t GmmLib::Context::IncrementRefCount()
 {
     int32_t *Ref = &RefCount;
 
-#if defined(__linux__)
+#if defined(__GNUC__)
     // returns 0 only when registering the first client
     return (__sync_fetch_and_add(Ref, 1));
 #endif
@@ -972,7 +972,7 @@ int32_t GmmLib::Context::DecrementRefCount()
         {
             break;
         }
-#if defined(__linux__)
+#if defined(__GNUC__)
     } while(!__sync_bool_compare_and_swap(Ref, CurrentValue, TargetValue));
 #endif
     return TargetValue;
