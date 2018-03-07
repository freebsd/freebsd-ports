--- third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp.orig	2018-02-24 16:25:34.000000000 +0100
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp	2018-03-04 03:59:33.369885000 +0100
@@ -93,7 +93,7 @@
       synthetic_italic_(source.synthetic_italic_),
       avoid_embedded_bitmaps_(source.avoid_embedded_bitmaps_),
       orientation_(source.orientation_),
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       style_(source.style_),
 #endif
       harf_buzz_face_(nullptr),
@@ -115,7 +115,7 @@
       synthetic_italic_(src.synthetic_italic_),
       avoid_embedded_bitmaps_(false),
       orientation_(src.orientation_),
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       style_(FontRenderStyle::QuerySystem(
           family_,
           text_size_,
@@ -148,7 +148,7 @@
       synthetic_italic_(synthetic_italic),
       avoid_embedded_bitmaps_(false),
       orientation_(orientation),
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       style_(FontRenderStyle::QuerySystem(
           family_,
           text_size_,
@@ -195,7 +195,7 @@
   avoid_embedded_bitmaps_ = other.avoid_embedded_bitmaps_;
   harf_buzz_face_ = nullptr;
   orientation_ = other.orientation_;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   style_ = other.style_;
 #endif
 
@@ -220,7 +220,7 @@
          synthetic_bold_ == a.synthetic_bold_ &&
          synthetic_italic_ == a.synthetic_italic_ &&
          avoid_embedded_bitmaps_ == a.avoid_embedded_bitmaps_
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
          && style_ == a.style_
 #endif
          && orientation_ == a.orientation_;
