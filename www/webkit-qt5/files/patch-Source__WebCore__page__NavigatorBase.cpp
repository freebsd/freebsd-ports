--- ./Source/WebCore/page/NavigatorBase.cpp.orig	2012-12-18 20:04:33.000000000 +0100
+++ ./Source/WebCore/page/NavigatorBase.cpp	2013-01-07 04:01:53.177339022 +0100
@@ -30,7 +30,7 @@
 #include "NetworkStateNotifier.h"
 #include <wtf/text/WTFString.h>
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD)
 #include "sys/utsname.h"
 #include <wtf/StdLibExtras.h>
 #endif
@@ -86,7 +86,7 @@
 
 String NavigatorBase::platform() const
 {
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD)
     if (!String(WEBCORE_NAVIGATOR_PLATFORM).isEmpty())
         return WEBCORE_NAVIGATOR_PLATFORM;
     struct utsname osname;
