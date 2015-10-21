--- compat/imsg.c.orig	2015-10-14 13:20:40 UTC
+++ compat/imsg.c
@@ -54,8 +54,12 @@ available_fds(unsigned int n)
 	for (i = 0; i < n; i++) {
 		fds[i] = -1;
 		if ((fds[i] = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
-			ret = 1;
-			break;
+			if (errno == EAFNOSUPPORT || errno == EPROTONOSUPPORT)
+				fds[i] = socket(AF_INET6, SOCK_DGRAM, 0);
+			if (fds[i] < 0) {
+				ret = 1;
+				break;
+			}
 		}
 	}
 
