--- core/DesktopEditor/graphics/Graphics.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/graphics/Graphics.cpp
@@ -61,7 +61,7 @@ namespace Aggplus
         m_bSwapRGB = false;
         m_bIsDarkMode = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
         m_bSwapRGB = true;
 #endif
 
@@ -94,7 +94,7 @@ namespace Aggplus
 
         m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
         m_bSwapRGB = true;
 #endif
 
@@ -132,7 +132,7 @@ namespace Aggplus
 
         m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
         m_bSwapRGB = true;
 #endif
 
