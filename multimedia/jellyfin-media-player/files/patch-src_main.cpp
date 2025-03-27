--- src/main.cpp.orig	2025-03-18 16:40:48 UTC
+++ src/main.cpp
@@ -83,7 +83,7 @@ QStringList g_qtFlags = {
 QStringList g_qtFlags = {
   "--disable-web-security",
   "--enable-gpu-rasterization",
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
   "--disable-gpu"
 #endif
 };
