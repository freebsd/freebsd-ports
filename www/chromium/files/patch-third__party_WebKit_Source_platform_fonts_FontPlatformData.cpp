--- third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp	2017-09-06 21:40:15.799533000 +0200
@@ -92,7 +92,7 @@
       synthetic_bold_(source.synthetic_bold_),
       synthetic_italic_(source.synthetic_italic_),
       orientation_(source.orientation_),
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       style_(source.style_),
 #endif
       harf_buzz_face_(nullptr),
@@ -113,7 +113,7 @@
       synthetic_bold_(src.synthetic_bold_),
       synthetic_italic_(src.synthetic_italic_),
       orientation_(src.orientation_),
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       style_(FontRenderStyle::QuerySystem(family_,
                                           text_size_,
                                           typeface_->fontStyle())),
@@ -144,7 +144,7 @@
       synthetic_bold_(synthetic_bold),
       synthetic_italic_(synthetic_italic),
       orientation_(orientation),
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       style_(FontRenderStyle::QuerySystem(family_,
                                           text_size_,
                                           typeface_->fontStyle())),
@@ -189,7 +189,7 @@
   synthetic_italic_ = other.synthetic_italic_;
   harf_buzz_face_ = nullptr;
   orientation_ = other.orientation_;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   style_ = other.style_;
 #endif
 
@@ -213,7 +213,7 @@
          is_hash_table_deleted_value_ == a.is_hash_table_deleted_value_ &&
          synthetic_bold_ == a.synthetic_bold_ &&
          synthetic_italic_ == a.synthetic_italic_
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
          && style_ == a.style_
 #endif
          && orientation_ == a.orientation_;
