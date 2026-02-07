From ed58fb83ffaf70423a83866a738978cc273f877b Mon Sep 17 00:00:00 2001
From: Chris Reffett <creffett@gentoo.org>
Date: Thu, 4 Jan 2018 13:13:00 -0500
Subject: media-tv/linuxtv-dvb-apps: Remove references to deleted CA_SET_PID
 syscall

Closes: https://bugs.gentoo.org/643436
Package-Manager: Portage-2.3.19, Repoman-2.3.6
--- include/ca.h
+++ include/ca.h
@@ -85,6 +85,5 @@
 #define CA_GET_MSG        _IOR('o', 132, ca_msg_t)
 #define CA_SEND_MSG       _IOW('o', 133, ca_msg_t)
 #define CA_SET_DESCR      _IOW('o', 134, ca_descr_t)
-#define CA_SET_PID        _IOW('o', 135, ca_pid_t)
 
 #endif
