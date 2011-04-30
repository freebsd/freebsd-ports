--- ui/gfx/image.cc.orig	2011-04-21 23:28:33.509559314 +0300
+++ ui/gfx/image.cc	2011-04-21 23:28:36.737559521 +0300
@@ -9,7 +9,7 @@
 #include "base/logging.h"
 #include "third_party/skia/include/core/SkBitmap.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include <gdk-pixbuf/gdk-pixbuf.h>
 #include <glib-object.h>
 #include "ui/gfx/canvas_skia.h"
@@ -29,7 +29,7 @@
 const SkBitmap* NSImageToSkBitmap(NSImage* image);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 const SkBitmap* GdkPixbufToSkBitmap(GdkPixbuf* pixbuf) {
   gfx::CanvasSkia canvas(gdk_pixbuf_get_width(pixbuf),
                          gdk_pixbuf_get_height(pixbuf),
@@ -61,7 +61,7 @@
     return reinterpret_cast<SkBitmapRep*>(this);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   GdkPixbufRep* AsGdkPixbufRep() {
     CHECK_EQ(type_, Image::kGdkPixbufRep);
     return reinterpret_cast<GdkPixbufRep*>(this);
@@ -102,7 +102,7 @@
   DISALLOW_COPY_AND_ASSIGN(SkBitmapRep);
 };
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 class GdkPixbufRep : public ImageRep {
  public:
   explicit GdkPixbufRep(GdkPixbuf* pixbuf)
@@ -158,7 +158,7 @@
   AddRepresentation(rep);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 Image::Image(GdkPixbuf* pixbuf)
     : default_representation_(Image::kGdkPixbufRep) {
   internal::GdkPixbufRep* rep = new internal::GdkPixbufRep(pixbuf);
@@ -190,7 +190,7 @@
   return *(this->operator const SkBitmap*());
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 Image::operator GdkPixbuf*() {
   internal::ImageRep* rep = GetRepresentation(Image::kGdkPixbufRep);
   return rep->AsGdkPixbufRep()->pixbuf();
@@ -237,7 +237,7 @@
   // Handle native-to-Skia conversion.
   if (rep_type == Image::kSkBitmapRep) {
     internal::SkBitmapRep* rep = NULL;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     if (default_representation_ == Image::kGdkPixbufRep) {
       internal::GdkPixbufRep* pixbuf_rep = default_rep->AsGdkPixbufRep();
       rep = new internal::SkBitmapRep(
@@ -261,7 +261,7 @@
   if (default_rep->type() == Image::kSkBitmapRep) {
     internal::SkBitmapRep* skia_rep = default_rep->AsSkBitmapRep();
     internal::ImageRep* native_rep = NULL;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     if (rep_type == Image::kGdkPixbufRep) {
       GdkPixbuf* pixbuf = gfx::GdkPixbufFromSkBitmap(skia_rep->bitmap());
       native_rep = new internal::GdkPixbufRep(pixbuf);
