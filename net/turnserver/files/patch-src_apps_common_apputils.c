--- src/apps/common/apputils.c.orig	2015-06-28 09:26:54.000000000 +0200
+++ src/apps/common/apputils.c	2015-10-02 15:56:56.044250196 +0200
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
