--- plugins/imuxsock/imuxsock.c.orig	2012-06-18 02:13:18.000000000 -0600
+++ plugins/imuxsock/imuxsock.c	2012-08-16 16:37:27.000000000 -0600
@@ -81,7 +81,7 @@
 
 /* emulate struct ucred for platforms that do not have it */
 #ifndef HAVE_SCM_CREDENTIALS
-struct ucred { int pid; };
+struct ucred { int pid; uid_t uid; gid_t gid; };
 #endif
 
 /* handle some defines missing on more than one platform */
@@ -891,9 +891,7 @@
 	int iMaxLine;
 	struct msghdr msgh;
 	struct iovec msgiov;
-#	if HAVE_SCM_CREDENTIALS
 	struct cmsghdr *cm;
-#	endif
 	struct ucred *cred;
 	struct timeval *ts;
 	uchar bufRcv[4096+1];
