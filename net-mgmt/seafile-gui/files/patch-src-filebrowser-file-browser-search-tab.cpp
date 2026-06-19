--- src/filebrowser/file-browser-search-tab.cpp.orig	2026-04-08 09:07:55 UTC
+++ src/filebrowser/file-browser-search-tab.cpp
@@ -158,7 +158,7 @@
     horizontalHeader()->setStretchLastSection(true);
     horizontalHeader()->setHighlightSections(false);
     horizontalHeader()->setSortIndicatorShown(true);
-#ifndef Q_OS_LINUX
+#if !defined(Q_OS_LINUX) && !defined(Q_OS_FREEBSD)
     horizontalHeader()->setSortIndicatorClearable(true);
 #endif
     horizontalHeader()->setSortIndicator(-1, Qt::AscendingOrder);
