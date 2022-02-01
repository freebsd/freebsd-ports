--- third_party/blink/renderer/platform/geometry/int_rect.h.orig	2022-01-24 16:04:48 UTC
+++ third_party/blink/renderer/platform/geometry/int_rect.h
@@ -244,11 +244,11 @@ constexpr IntRect SaturatedRect(const IntRect& r) {
                  base::ClampAdd(r.y(), r.height()) - r.y());
 }
 
-constexpr bool operator==(const IntRect& a, const IntRect& b) {
+inline bool operator==(const IntRect& a, const IntRect& b) {
   return a.origin() == b.origin() && a.size() == b.size();
 }
 
-constexpr bool operator!=(const IntRect& a, const IntRect& b) {
+inline bool operator!=(const IntRect& a, const IntRect& b) {
   return !(a == b);
 }
 
