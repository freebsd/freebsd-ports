--- src/common/timecode.h.orig	2012-09-22 22:31:07.000000000 +0800
+++ src/common/timecode.h	2012-09-22 22:31:19.000000000 +0800
@@ -139,7 +139,7 @@
   }
 
   basic_timecode_c<T> abs() const {
-    return basic_timecode_c<T>{std::abs(m_timecode), m_valid};
+    return basic_timecode_c<T>{(T)std::abs(m_timecode), m_valid};
   }
 
   // comparison
