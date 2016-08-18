--- third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp.orig	2016-08-04 11:20:01.382167000 -0400
+++ third_party/WebKit/Source/platform/fonts/FontPlatformData.cpp	2016-08-04 11:21:00.605035000 -0400
@@ -93,7 +93,7 @@
     , m_syntheticBold(source.m_syntheticBold)
     , m_syntheticItalic(source.m_syntheticItalic)
     , m_orientation(source.m_orientation)
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD)
     , m_style(source.m_style)
 #endif
     , m_harfBuzzFace(nullptr)
@@ -115,7 +115,7 @@
     , m_syntheticBold(src.m_syntheticBold)
     , m_syntheticItalic(src.m_syntheticItalic)
     , m_orientation(src.m_orientation)
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD)
     , m_style(FontRenderStyle::querySystem(m_family, m_textSize, m_typeface->style()))
 #endif
     , m_harfBuzzFace(nullptr)
@@ -142,7 +142,7 @@
     , m_syntheticBold(syntheticBold)
     , m_syntheticItalic(syntheticItalic)
     , m_orientation(orientation)
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD)
     , m_style(FontRenderStyle::querySystem(m_family, m_textSize, m_typeface->style()))
 #endif
     , m_isHashTableDeletedValue(false)
@@ -188,7 +188,7 @@
     m_syntheticItalic = other.m_syntheticItalic;
     m_harfBuzzFace = nullptr;
     m_orientation = other.m_orientation;
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD)
     m_style = other.m_style;
 #endif
 
@@ -216,7 +216,7 @@
         && m_isHashTableDeletedValue == a.m_isHashTableDeletedValue
         && m_syntheticBold == a.m_syntheticBold
         && m_syntheticItalic == a.m_syntheticItalic
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD)
         && m_style == a.m_style
 #endif
         && m_orientation == a.m_orientation;
