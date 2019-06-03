--- src/icon_cache.h.orig	2019-06-03 23:11:44 UTC
+++ src/icon_cache.h
@@ -23,7 +23,7 @@ signals: (private)
 
     QHash<QString, QIcon> mIcons;
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     QMimeDatabase mMimeDatabase;
 #endif
 };
