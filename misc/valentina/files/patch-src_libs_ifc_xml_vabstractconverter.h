--- src/libs/ifc/xml/vabstractconverter.h.orig	2018-08-11 23:31:52 UTC
+++ src/libs/ifc/xml/vabstractconverter.h
@@ -31,7 +31,7 @@
 
 #include <qcompilerdetection.h>
 
-#if !defined(Q_OS_OSX) && !defined(Q_OS_WIN) && defined(Q_CC_GNU)
+#if !defined(Q_OS_OSX) && !defined(Q_OS_WIN) && !defined(Q_OS_FREEBSD) && defined(Q_CC_GNU)
 #include <sys/sysmacros.h>
 #endif
 
