--- include/olm/list.hh.orig	2022-10-07 15:00:05 UTC
+++ include/olm/list.hh
@@ -99,7 +99,7 @@ class List { (public)
             return *this;
         }
         T * this_pos = _data;
-        T * const other_pos = other._data;
+        T const * other_pos = other._data;
         while (other_pos != other._end) {
             *this_pos = *other;
             ++this_pos;
