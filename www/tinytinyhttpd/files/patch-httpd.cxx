diff --git httpd.cxx httpd.cxx
index 98cec3c..958200a 100644
--- httpd.cxx
+++ httpd.cxx
@@ -1734,7 +1734,7 @@ request_done:
 #if defined LINUX_SENDFILE_API
 			sent = sendfile(msgsock, fileno(res_info->read), NULL, total);
 #elif defined FREEBSD_SENDFILE_API
-			sendfile(msgsock, fileno(res_info->read), total, &sent, NULL, 0);
+			if (sendfile(msgsock, fileno(res_info->read), NULL, total, NULL, NULL, 0) == 0) sent = total;
 #elif defined _WIN32
 			if (!res_info->process && lpfnTransmitFile && lpfnTransmitFile(
 				msgsock,
