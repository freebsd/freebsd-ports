--- src/main/main.cpp.orig	2014-01-26 19:33:25.000000000 +0100
+++ src/main/main.cpp	2014-01-30 21:21:44.272275856 +0100
@@ -21,7 +21,7 @@
 #include <QMessageBox> // For QT_REQUIRE_VERSION
 #include <iostream>
 
-#if defined(Q_OS_LINUX) || defined(__GLIBC__)
+#if defined(Q_OS_LINUX) || defined(__FreeBSD__)
 #include <signal.h>
 #include <execinfo.h>
 
@@ -111,7 +111,7 @@
         break;
     }
 }
-#endif // defined(Q_OS_LINUX) || defined(__GLIBC__)
+#endif // defined(Q_OS_LINUX) || defined(__FreeBSD__)
 
 #ifndef Q_OS_WIN
 #if (QT_VERSION < 0x050000)
@@ -175,7 +175,7 @@
     QApplication::setGraphicsSystem("raster"); // Better overall performance on X11
 #endif
 
-#if defined(Q_OS_LINUX) || defined(__GLIBC__)
+#if defined(Q_OS_LINUX) || defined(__FreeBSD__)
     signal(SIGSEGV, qupzilla_signal_handler);
     signal(SIGPIPE, qupzilla_signal_handler);
 #endif
