--- modules/server/hep3_capture.cpp.orig	2024-05-11 20:44:43 UTC
+++ modules/server/hep3_capture.cpp
@@ -421,7 +421,7 @@ static const TokenDict s_ipTypes[] = {
     {"unspecified", AF_UNSPEC},
     {"local", AF_LOCAL},
     {"unix", AF_UNIX},
-    {"file", AF_FILE},
+    {"file", AF_LOCAL},
     {"ipv4", AF_INET},
     {"IPv4", AF_INET},
     {"ipv6", AF_INET6},
