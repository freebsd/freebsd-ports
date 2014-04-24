From 63c17280408410d799e1c2f2ed49c5ab04cc80ae Mon Sep 17 00:00:00 2001
From: Sebastian Dröge <sebastian@centricular.com>
Date: Sun, 20 Apr 2014 09:59:02 +0000
Subject: basesrc: Make sure to always hold the LIVE_LOCK when going to the flushing label

https://bugzilla.gnome.org/show_bug.cgi?id=728596
---
diff --git a/libs/gst/base/gstbasesrc.c b/libs/gst/base/gstbasesrc.c
index 9f2e52c..fc5a3af 100644
--- libs/gst/base/gstbasesrc.c
+++ libs/gst/base/gstbasesrc.c
@@ -2684,10 +2684,12 @@ gst_base_src_loop (GstPad * pad)
   if (gst_pad_check_reconfigure (pad)) {
     if (!gst_base_src_negotiate (src)) {
       gst_pad_mark_reconfigure (pad);
-      if (GST_PAD_IS_FLUSHING (pad))
+      if (GST_PAD_IS_FLUSHING (pad)) {
+        GST_LIVE_LOCK (src);
         goto flushing;
-      else
+      } else {
         goto negotiate_failed;
+      }
     }
   }
 
--
cgit v0.9.0.2-2-gbebe
