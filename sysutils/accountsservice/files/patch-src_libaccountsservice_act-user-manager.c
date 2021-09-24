Obtained from:
	https://cvsweb.openbsd.org/cgi-bin/cvsweb/~checkout~/ports/sysutils/accountsservice/patches/patch-src_libaccountsservice_act-user-manager_c

$OpenBSD: patch-src_libaccountsservice_act-user-manager_c,v 1.2 2021/08/30 19:15:24 ajacoutot Exp $

REVERT: (breaks listing users in gdm and gnome-cc and unlocking screenshield)
From c7fa612023a163e8b2352e1170c6df3fceb19b27 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Thu, 19 Jul 2018 13:14:09 -0400
Subject: [PATCH] lib: don't set loaded state until seat is fetched

Index: src/libaccountsservice/act-user-manager.c
--- src/libaccountsservice/act-user-manager.c.orig
+++ src/libaccountsservice/act-user-manager.c
@@ -2547,7 +2547,7 @@ maybe_set_is_loaded (ActUserManager *manager)
         /* Don't set is_loaded yet unless the seat is already loaded enough
          * or failed to load.
          */
-        if (priv->seat.state > ACT_USER_MANAGER_SEAT_STATE_GET_ID) {
+        if (priv->seat.state >= ACT_USER_MANAGER_SEAT_STATE_GET_ID) {
                 g_debug ("ActUserManager: Seat loaded, so now setting loaded property");
         } else if (priv->seat.state == ACT_USER_MANAGER_SEAT_STATE_UNLOADED) {
                 g_debug ("ActUserManager: Seat wouldn't load, so giving up on it and setting loaded property");

