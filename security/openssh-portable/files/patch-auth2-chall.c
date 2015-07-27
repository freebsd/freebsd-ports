From 5b64f85bb811246c59ebab70aed331f26ba37b18 Mon Sep 17 00:00:00 2001
From: "djm@openbsd.org" <djm@openbsd.org>
Date: Sat, 18 Jul 2015 07:57:14 +0000
Subject: upstream commit

only query each keyboard-interactive device once per
 authentication request regardless of how many times it is listed; ok markus@

Upstream-ID: d73fafba6e86030436ff673656ec1f33d9ffeda1
---
 auth2-chall.c | 11 ++++++++---
 1 file changed, 8 insertions(+), 3 deletions(-)

diff --git a/auth2-chall.c b/auth2-chall.c
index ddabe1a..4aff09d 100644
--- auth2-chall.c
+++ auth2-chall.c
@@ -1,4 +1,4 @@
-/* $OpenBSD: auth2-chall.c,v 1.42 2015/01/19 20:07:45 markus Exp $ */
+/* $OpenBSD: auth2-chall.c,v 1.43 2015/07/18 07:57:14 djm Exp $ */
 /*
  * Copyright (c) 2001 Markus Friedl.  All rights reserved.
  * Copyright (c) 2001 Per Allansson.  All rights reserved.
@@ -83,6 +83,7 @@ struct KbdintAuthctxt
 	void *ctxt;
 	KbdintDevice *device;
 	u_int nreq;
+	u_int devices_done;
 };
 
 #ifdef USE_PAM
@@ -169,11 +170,15 @@ kbdint_next_device(Authctxt *authctxt, KbdintAuthctxt *kbdintctxt)
 		if (len == 0)
 			break;
 		for (i = 0; devices[i]; i++) {
-			if (!auth2_method_allowed(authctxt,
+			if ((kbdintctxt->devices_done & (1 << i)) != 0 ||
+			    !auth2_method_allowed(authctxt,
 			    "keyboard-interactive", devices[i]->name))
 				continue;
-			if (strncmp(kbdintctxt->devices, devices[i]->name, len) == 0)
+			if (strncmp(kbdintctxt->devices, devices[i]->name,
+			    len) == 0) {
 				kbdintctxt->device = devices[i];
+				kbdintctxt->devices_done |= 1 << i;
+			}
 		}
 		t = kbdintctxt->devices;
 		kbdintctxt->devices = t[len] ? xstrdup(t+len+1) : NULL;
-- 
cgit v0.11.2

