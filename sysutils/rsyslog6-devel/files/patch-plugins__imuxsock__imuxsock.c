--- ./plugins/imuxsock/imuxsock.c.orig	2011-09-15 06:01:15.000000000 +0000
+++ ./plugins/imuxsock/imuxsock.c	2012-01-17 01:17:22.085759310 +0000
@@ -727,9 +727,7 @@
 	int iMaxLine;
 	struct msghdr msgh;
 	struct iovec msgiov;
-#	if HAVE_SCM_CREDENTIALS
 	struct cmsghdr *cm;
-#	endif
 	struct ucred *cred;
 	struct timeval *ts;
 	uchar bufRcv[4096+1];
