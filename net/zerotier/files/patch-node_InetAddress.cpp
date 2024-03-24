--- node/InetAddress.cpp.orig	2023-09-14 19:09:26 UTC
+++ node/InetAddress.cpp
@@ -132,7 +132,20 @@ InetAddress::IpScope InetAddress::ipScope() const
 					return IP_SCOPE_PRIVATE;        // fc00::/7
 				}
 			}
+
+			// :::ffff:127.0.0.1
+			// 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xff, 0xff, 0x7f, 0, 0, 1
 			unsigned int k = 0;
+			while ((!ip[k])&&(k < 9)) {
+				++k;
+			}
+			if (k == 9) {
+				if (ip[10] == 0xff && ip[11] == 0xff && ip[12] == 0x7f) {
+					return IP_SCOPE_LOOPBACK;
+				}
+			}
+
+			k = 0;
 			while ((!ip[k])&&(k < 15)) {
 				++k;
 			}
