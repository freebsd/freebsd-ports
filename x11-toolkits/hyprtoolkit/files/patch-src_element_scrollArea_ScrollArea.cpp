--- src/element/scrollArea/ScrollArea.cpp.orig	2025-11-12 08:23:14 UTC
+++ src/element/scrollArea/ScrollArea.cpp
@@ -118,7 +118,7 @@ void SScrollAreaImpl::clampMaxScroll() {
                                   data.scrollX ? 99999999999 : self->impl->position.w,
                                   data.scrollY ? 99999999999 : self->impl->position.h,
                               })
-                              .value_or({99999999, 99999999}) -
+                              .value_or(Vector2D{99999999, 99999999}) -
                           self->impl->position.size())
                              .clamp({0, 0});
 
