--- core/DesktopEditor/graphics/Graphics.cpp.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/graphics/Graphics.cpp
@@ -60,7 +60,7 @@ namespace Aggplus
 		m_dGlobalAlpha		= 1.0;
         m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
         m_bSwapRGB = true;
 #endif
 
@@ -93,7 +93,7 @@ namespace Aggplus
 
         m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(__FreeBSD__)
         m_bSwapRGB = true;
 #endif
 
@@ -131,7 +131,7 @@ namespace Aggplus
 
         m_bSwapRGB = false;
 
-#if defined (_LINUX) || defined (_QT)
+#if defined (_LINUX) || defined (_QT) || defined(_FreeBSD__)
         m_bSwapRGB = true;
 #endif
 
