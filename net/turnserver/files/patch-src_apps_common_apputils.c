--- src/apps/common/apputils.c.orig	2015-09-30 07:05:14 UTC
+++ src/apps/common/apputils.c
@@ -1037,13 +1037,15 @@ static const char* turn_get_method(const
 		if(!method)
 			return mdefault;
 		else {
-
+#ifndef OPENSSL_NO_SSL3
 			if(method == SSLv3_server_method()) {
 				return "SSLv3";
 			} else if(method == SSLv3_client_method()) {
 				return "SSLv3";
-			} else if(method == SSLv23_server_method()) {
-					return "SSLv23";
+			} else 
+#endif
+			if(method == SSLv23_server_method()) {
+			        return "SSLv23";
 			} else if(method == SSLv23_client_method()) {
 					return "SSLv23";
 			} else if(method == TLSv1_server_method()) {
