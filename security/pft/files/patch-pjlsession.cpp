--- pjlsession.cpp.orig	Sun May 22 14:06:23 2005
+++ pjlsession.cpp	Sun May 22 14:06:52 2005
@@ -871,7 +871,7 @@
 #endif //_DEBUG
 		throw ExInvalid();
 	} else {
-		snprintf(numb,49,"%lu",statbuf.st_size);
+		snprintf(numb,49,"%llu",statbuf.st_size);
 		connection.clear();
 		connection.sendbuf.set(PJL_START);
 		connection.sendbuf.append(PJL_FSDOWNLOAD);
