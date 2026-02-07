--- src/3rdparty/chromium/base/threading/hang_watcher.h.orig	2023-11-09 11:32:20 UTC
+++ src/3rdparty/chromium/base/threading/hang_watcher.h
@@ -420,7 +420,8 @@ class BASE_EXPORT HangWatchDeadline {
 
  private:
   using TimeTicksInternalRepresentation =
-      std::result_of<decltype (&TimeTicks::ToInternalValue)(TimeTicks)>::type;
+      std::invoke_result<decltype(&TimeTicks::ToInternalValue),
+                         TimeTicks>::type;
   static_assert(std::is_same<TimeTicksInternalRepresentation, int64_t>::value,
                 "Bit manipulations made by HangWatchDeadline need to be"
                 "adapted if internal representation of TimeTicks changes.");
