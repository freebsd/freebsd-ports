commit 9f3e48e5219a09b5ddfd6883d1f0498910eff4b6
Author: Pavel Vasin <pavel@vasin.nl>
Date:   Sun, 23 Aug 2015 23:53:49 +0300

    add support for miniupnpc api version 14

    The value of new arg ttl is set to 2 as it's recommended default.
---
 src/net.cpp | 6 +++++-
 1 file changed, 5 insertions(+), 1 deletion(-)

diff --git a/src/net.cpp b/src/net.cpp
index fb5726a..4c6331f 100644
--- src/net.cpp.orig	2015-07-10 17:23:55 UTC
+++ src/net.cpp
@@ -1120,10 +1120,14 @@ void ThreadMapPort()
 #ifndef UPNPDISCOVER_SUCCESS
     /* miniupnpc 1.5 */
     devlist = upnpDiscover(2000, multicastif, minissdpdpath, 0);
-#else
+#elif MINIUPNPC_API_VERSION < 14
     /* miniupnpc 1.6 */
     int error = 0;
     devlist = upnpDiscover(2000, multicastif, minissdpdpath, 0, 0, &error);
+#else
+    /* miniupnpc 1.9.20150730 */
+    int error = 0;
+    devlist = upnpDiscover(2000, multicastif, minissdpdpath, 0, 0, 2, &error);
 #endif
 
     struct UPNPUrls urls;
