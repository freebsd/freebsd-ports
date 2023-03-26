--- core/DesktopEditor/graphics/Graphics.cpp.orig	2023-02-13 11:23:51 UTC
+++ core/DesktopEditor/graphics/Graphics.cpp
@@ -61,7 +61,7 @@ namespace Aggplus
 		m_bSwapRGB = false;
 		m_bIsDarkMode = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
 		m_bSwapRGB = true;
 #endif
 
@@ -95,7 +95,7 @@ namespace Aggplus
 
 		m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
 		m_bSwapRGB = true;
 #endif
 
@@ -134,7 +134,7 @@ namespace Aggplus
 
 		m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
 		m_bSwapRGB = true;
 #endif
 
