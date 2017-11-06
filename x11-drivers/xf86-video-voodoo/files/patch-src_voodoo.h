From 9172ae566a0e85313fc80ab62b4455393eefe593 Mon Sep 17 00:00:00 2001
From: Dave Airlie <airlied@redhat.com>
Date: Mon, 22 Sep 2014 10:56:02 +1000
Subject: don't use PCITAG in struct anymore


--- src/voodoo.h.orig	2012-07-17 05:21:17 UTC
+++ src/voodoo.h
@@ -23,7 +23,9 @@ typedef struct {
   
   Bool		      Voodoo2;		/* Set if Voodoo2 */
   pciVideoPtr	      PciInfo;		/* PCI data */
+#ifndef XSERVER_LIBPCIACCESS
   PCITAG	      PciTag;
+#endif
   CARD32	      PhysBase;
   
   CARD32	      Width;		/* Current width */
