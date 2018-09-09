httpd.cxx:1019:21: error: assigning to 'int' from incompatible type 'nullptr_t'
                res_info->write = NULL;
                                  ^~~~
/usr/include/sys/_null.h:37:14: note: expanded from macro 'NULL'
#define NULL    nullptr
                ^~~~~~~
httpd.cxx:1734:8: error: no matching function for call to 'sendfile'
                        if (sendfile(msgsock, res_info->read, NULL, total, NULL, NULL, 0) == 0) sent = total;
                            ^~~~~~~~
/usr/include/sys/socket.h:684:5: note: candidate function not viable: no known conversion from 'nullptr_t' to 'off_t' (aka 'long long') for 3rd argument
int     sendfile(int, int, off_t, size_t, struct sf_hdtr *, off_t *, int);
        ^

--- httpd.cxx.orig	2018-08-25 14:11:36 UTC
+++ httpd.cxx
@@ -1016,7 +1016,7 @@ static RES_INFO* res_popen(std::vector<std::string>& a
 static void res_closewriter(RES_INFO* res_info) {
 	if (res_info && res_info->write) {
 		close(res_info->write);
-		res_info->write = NULL;
+		res_info->write = 0;
 	}
 }
 
@@ -1731,7 +1731,7 @@ request_done:
 #if defined LINUX_SENDFILE_API
 			sent = sendfile(msgsock, res_info->read, NULL, total);
 #elif defined FREEBSD_SENDFILE_API
-			if (sendfile(msgsock, res_info->read, NULL, total, NULL, NULL, 0) == 0) sent = total;
+			if (sendfile(msgsock, res_info->read, 0, total, NULL, NULL, 0) == 0) sent = total;
 #elif defined _WIN32
 			if (!res_info->process && lpfnTransmitFile && lpfnTransmitFile(
 				msgsock,
