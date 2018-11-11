--- Source/WebCore/platform/network/soup/SoupNetworkSession.h.orig	2018-09-06 11:51:34 UTC
+++ Source/WebCore/platform/network/soup/SoupNetworkSession.h
@@ -34,6 +34,8 @@
 #include <wtf/glib/GRefPtr.h>
 #include <wtf/text/WTFString.h>
 
+#include "URL.h"
+
 typedef struct _SoupCache SoupCache;
 typedef struct _SoupCookieJar SoupCookieJar;
 typedef struct _SoupMessage SoupMessage;
