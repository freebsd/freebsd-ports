Index: Source/WebCore/page/NavigatorBase.cpp
--- Source/WebCore/page/NavigatorBase.cpp.orig
+++ Source/WebCore/page/NavigatorBase.cpp
@@ -40,7 +40,7 @@
 #include <wtf/UniqueRef.h>
 #include <wtf/text/WTFString.h>
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(OPENBSD)
 #include "sys/utsname.h"
 #include <wtf/StdLibExtras.h>
 #endif
@@ -88,7 +88,7 @@ String NavigatorBase::appVersion() const
 
 String NavigatorBase::platform() const
 {
-#if OS(LINUX)
+#if OS(LINUX) || OS(OPENBSD)
     static LazyNeverDestroyed<String> platformName;
     static std::once_flag onceKey;
     std::call_once(onceKey, [] {
