From 9f2aa8d47f835ea155aaf635f618c0fc1ca87012 Mon Sep 17 00:00:00 2001
From: Matthias Clasen <mclasen@redhat.com>
Date: Thu, 9 Aug 2012 08:35:23 +0100
Subject: v4l2: fix build with recent kernels, the v4l2_buffer input field was
 removed

This was unused apparently and removed in the kernel in commit:

 From 2b719d7baf490e24ce7d817c6337b7c87fda84c1 Mon Sep 17 00:00:00 2001
 From: Sakari Ailus <sakari.ailus@iki.fi>
 Date: Wed, 2 May 2012 09:40:03 -0300
 Subject: [PATCH] [media] v4l: drop v4l2_buffer.input and V4L2_BUF_FLAG_INPUT

 Remove input field in struct v4l2_buffer and flag V4L2_BUF_FLAG_INPUT which
 tells the former is valid. The flag is used by no driver currently.

https://bugzilla.gnome.org/show_bug.cgi?id=681491

Conflicts:
	sys/v4l2/gstv4l2bufferpool.c

--- sys/v4l2/gstv4l2bufferpool.c.orig	2011-12-30 14:59:13.000000000 +0100
+++ sys/v4l2/gstv4l2bufferpool.c	2015-01-25 00:40:42.521756686 +0100
@@ -181,7 +181,6 @@ gst_v4l2_buffer_new (GstV4l2BufferPool *
     GST_LOG_OBJECT (pool->v4l2elem, "  MMAP offset:  %u",
         ret->vbuffer.m.offset);
   GST_LOG_OBJECT (pool->v4l2elem, "  length:    %u", ret->vbuffer.length);
-  GST_LOG_OBJECT (pool->v4l2elem, "  input:     %u", ret->vbuffer.input);
 
   data = (guint8 *) v4l2_mmap (0, ret->vbuffer.length,
       PROT_READ | PROT_WRITE, MAP_SHARED, pool->video_fd,
