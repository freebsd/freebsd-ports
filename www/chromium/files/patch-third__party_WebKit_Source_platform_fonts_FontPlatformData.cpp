--- third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp.orig	2017-12-15 02:04:47.000000000 +0100
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp	2017-12-24 18:18:08.481217000 +0100
@@ -96,7 +96,7 @@
       synthetic_italic_(source.synthetic_italic_),
       avoid_embedded_bitmaps_(source.avoid_embedded_bitmaps_),
       orientation_(source.orientation_),
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       style_(source.style_),
 #endif
       harf_buzz_face_(nullptr),
@@ -118,7 +118,7 @@
       synthetic_italic_(src.synthetic_italic_),
       avoid_embedded_bitmaps_(false),
       orientation_(src.orientation_),
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       style_(FontRenderStyle::QuerySystem(family_,
                                           text_size_,
                                           typeface_->fontStyle())),
@@ -150,7 +150,7 @@
       synthetic_italic_(synthetic_italic),
       avoid_embedded_bitmaps_(false),
       orientation_(orientation),
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       style_(FontRenderStyle::QuerySystem(family_,
                                           text_size_,
                                           typeface_->fontStyle())),
@@ -196,7 +196,7 @@
   avoid_embedded_bitmaps_ = other.avoid_embedded_bitmaps_;
   harf_buzz_face_ = nullptr;
   orientation_ = other.orientation_;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   style_ = other.style_;
 #endif
 
@@ -221,7 +221,7 @@
          synthetic_bold_ == a.synthetic_bold_ &&
          synthetic_italic_ == a.synthetic_italic_ &&
          avoid_embedded_bitmaps_ == a.avoid_embedded_bitmaps_
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
          && style_ == a.style_
 #endif
          && orientation_ == a.orientation_;
