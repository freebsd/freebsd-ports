--- third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp.orig	2016-12-13 00:46:20 UTC
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp
@@ -99,7 +99,7 @@ FontPlatformData::FontPlatformData(const
       m_syntheticBold(source.m_syntheticBold),
       m_syntheticItalic(source.m_syntheticItalic),
       m_orientation(source.m_orientation),
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
       m_style(source.m_style),
 #endif
       m_harfBuzzFace(nullptr),
@@ -122,7 +122,7 @@ FontPlatformData::FontPlatformData(const
       m_syntheticBold(src.m_syntheticBold),
       m_syntheticItalic(src.m_syntheticItalic),
       m_orientation(src.m_orientation),
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
       m_style(FontRenderStyle::querySystem(m_family,
                                            m_textSize,
                                            m_typeface->style())),
@@ -155,7 +155,7 @@ FontPlatformData::FontPlatformData(sk_sp
       m_syntheticBold(syntheticBold),
       m_syntheticItalic(syntheticItalic),
       m_orientation(orientation),
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) | OS(BSD)
       m_style(FontRenderStyle::querySystem(m_family,
                                            m_textSize,
                                            m_typeface->style())),
@@ -200,7 +200,7 @@ const FontPlatformData& FontPlatformData
   m_syntheticItalic = other.m_syntheticItalic;
   m_harfBuzzFace = nullptr;
   m_orientation = other.m_orientation;
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) | OS(BSD)
   m_style = other.m_style;
 #endif
 
@@ -226,7 +226,7 @@ bool FontPlatformData::operator==(const 
          m_isHashTableDeletedValue == a.m_isHashTableDeletedValue &&
          m_syntheticBold == a.m_syntheticBold &&
          m_syntheticItalic == a.m_syntheticItalic
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
          && m_style == a.m_style
 #endif
          && m_orientation == a.m_orientation;
