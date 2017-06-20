--- third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp
@@ -93,7 +93,7 @@ FontPlatformData::FontPlatformData(const FontPlatformD
       synthetic_bold_(source.synthetic_bold_),
       synthetic_italic_(source.synthetic_italic_),
       orientation_(source.orientation_),
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
       style_(source.style_),
 #endif
       harf_buzz_face_(nullptr),
@@ -114,7 +114,7 @@ FontPlatformData::FontPlatformData(const FontPlatformD
       synthetic_bold_(src.synthetic_bold_),
       synthetic_italic_(src.synthetic_italic_),
       orientation_(src.orientation_),
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
       style_(FontRenderStyle::QuerySystem(family_,
                                           text_size_,
                                           typeface_->fontStyle())),
@@ -145,7 +145,7 @@ FontPlatformData::FontPlatformData(sk_sp<SkTypeface> t
       synthetic_bold_(synthetic_bold),
       synthetic_italic_(synthetic_italic),
       orientation_(orientation),
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
       style_(FontRenderStyle::QuerySystem(family_,
                                           text_size_,
                                           typeface_->fontStyle())),
@@ -188,7 +188,7 @@ const FontPlatformData& FontPlatformData::operator=(
   synthetic_italic_ = other.synthetic_italic_;
   harf_buzz_face_ = nullptr;
   orientation_ = other.orientation_;
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
   style_ = other.style_;
 #endif
 
@@ -212,7 +212,7 @@ bool FontPlatformData::operator==(const FontPlatformDa
          is_hash_table_deleted_value_ == a.is_hash_table_deleted_value_ &&
          synthetic_bold_ == a.synthetic_bold_ &&
          synthetic_italic_ == a.synthetic_italic_
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
          && style_ == a.style_
 #endif
          && orientation_ == a.orientation_;
