--- Source/GmmLib/inc/External/Common/GmmInfo.h.orig	2023-07-18 11:42:34 UTC
+++ Source/GmmLib/inc/External/Common/GmmInfo.h
@@ -141,7 +141,7 @@ namespace GmmLib
         {
 #if defined(_WIN32)
             return(InterlockedIncrement((LONG *)&RefCount) - 1);  //InterLockedIncrement() returns incremented value
-#elif defined(__linux__)
+#elif defined(__GNUC__)
             return(__sync_fetch_and_add(&RefCount, 1));
 #endif
         }
@@ -163,7 +163,7 @@ namespace GmmLib
                 }
 #if defined(_WIN32)
             } while (!(InterlockedCompareExchange((LONG *)&RefCount, TargetValue, CurrentValue) == CurrentValue));
-#elif defined(__linux__)
+#elif defined(__GNUC__)
             } while (!__sync_bool_compare_and_swap(&RefCount, CurrentValue, TargetValue));
 #endif
 
