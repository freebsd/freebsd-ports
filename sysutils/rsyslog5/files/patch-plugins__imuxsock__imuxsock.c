--- plugins/imuxsock/imuxsock.c.orig	2012-08-22 09:13:32.000000000 -0600
+++ plugins/imuxsock/imuxsock.c	2012-09-09 15:43:48.000000000 -0600
@@ -77,7 +77,7 @@
 
 /* emulate struct ucred for platforms that do not have it */
 #ifndef HAVE_SCM_CREDENTIALS
-struct ucred { int pid; };
+struct ucred { int pid; uid_t uid; gid_t gid; };
 #endif
 
 /* handle some defines missing on more than one platform */
@@ -802,9 +802,7 @@
 	int iMaxLine;
 	struct msghdr msgh;
 	struct iovec msgiov;
-#	if HAVE_SCM_CREDENTIALS
 	struct cmsghdr *cm;
-#	endif
 	struct ucred *cred;
 	struct timeval *ts;
 	uchar bufRcv[4096+1];
