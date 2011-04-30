--- ui/gfx/image.h.orig	2011-04-19 23:12:17.508039568 +0300
+++ ui/gfx/image.h	2011-04-19 23:12:44.348038227 +0300
@@ -43,7 +43,7 @@
   // Creates a new image with the default representation. The object will take
   // ownership of the image.
   explicit Image(const SkBitmap* bitmap);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // Does not increase |pixbuf|'s reference count; expects to take ownership.
   explicit Image(GdkPixbuf* pixbuf);
 #elif defined(OS_MACOSX)
@@ -57,7 +57,7 @@
   // Conversion handlers.
   operator const SkBitmap*();
   operator const SkBitmap&();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   operator GdkPixbuf*();
 #elif defined(OS_MACOSX)
   operator NSImage*();
