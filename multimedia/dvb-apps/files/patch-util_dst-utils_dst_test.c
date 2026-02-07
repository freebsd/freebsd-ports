From ed58fb83ffaf70423a83866a738978cc273f877b Mon Sep 17 00:00:00 2001
From: Chris Reffett <creffett@gentoo.org>
Date: Thu, 4 Jan 2018 13:13:00 -0500
Subject: media-tv/linuxtv-dvb-apps: Remove references to deleted CA_SET_PID
 syscall

Closes: https://bugs.gentoo.org/643436
Package-Manager: Portage-2.3.19, Repoman-2.3.6
--- util/dst-utils/dst_test.c
+++ util/dst-utils/dst_test.c
@@ -111,16 +111,6 @@
 	return 0;
 }
 
-static int dst_set_pid(int cafd)
-{
-	if ((ioctl(cafd, CA_SET_PID)) < 0) {
-		printf("%s: ioctl failed ..\n", __FUNCTION__);
-		return -1;
-	}
-
-	return 0;
-}
-
 static int dst_get_descr(int cafd)
 {
 	if ((ioctl(cafd, CA_GET_DESCR_INFO)) < 0) {
@@ -229,10 +219,6 @@
 				printf("%s: Reset\n", __FUNCTION__);
 				dst_reset(cafd);
 				break;
-			case 'p':
-				printf("%s: PID\n", __FUNCTION__);
-				dst_set_pid(cafd);
-				break;
 			case 'g':
 				printf("%s: Get Desc\n", __FUNCTION__);
 				dst_get_descr(cafd);
