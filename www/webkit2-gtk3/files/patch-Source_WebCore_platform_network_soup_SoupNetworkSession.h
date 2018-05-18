--- Source/WebCore/platform/network/soup/SoupNetworkSession.h.orig	2018-05-07 10:56:05.000000000 +0200
+++ Source/WebCore/platform/network/soup/SoupNetworkSession.h	2018-05-14 21:15:28.165991000 +0200
@@ -33,6 +33,8 @@
 #include <wtf/glib/GRefPtr.h>
 #include <wtf/text/WTFString.h>
 
+#include "URL.h"
+
 typedef struct _SoupCache SoupCache;
 typedef struct _SoupCookieJar SoupCookieJar;
 typedef struct _SoupMessage SoupMessage;
