--- src/common/timecode.h.orig	2015-07-18 11:39:41 UTC
+++ src/common/timecode.h
@@ -147,7 +147,7 @@ public:
   }
 
   basic_timecode_c<T> abs() const {
-    return basic_timecode_c<T>{std::abs(m_timecode), m_valid};
+    return basic_timecode_c<T>{(T)std::abs(m_timecode), m_valid};
   }
 
   basic_timecode_c<T> value_or_min() const {
