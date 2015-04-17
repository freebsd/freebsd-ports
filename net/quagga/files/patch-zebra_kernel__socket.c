From 3e07588e6c2d11464b458cef3965ae31b5f99181 Mon Sep 17 00:00:00 2001
From: Greg Troxel <gdt@ir.bbn.com>
Date: Mon, 23 Mar 2015 15:16:29 -0400
Subject: [PATCH] Fix alignment assumptions on non-RT_ROUNDUP platforms.

The comment said that apple uses int and BSD traditionally used long,
but the code was backwards.  This fixes apple to be int, and otherwise
long.  That should make FreeBSD, which aligns to long, work correctly,
even without using SA_SIZE.

(cherry picked from commit 941789e470199df4f612368f669ecc0fd096fb9a)
---
 zebra/kernel_socket.c |    4 ++--
 1 files changed, 2 insertions(+), 2 deletions(-)

--- zebra/kernel_socket.c.orig	2015-03-07 06:58:00 UTC
+++ zebra/kernel_socket.c
@@ -78,9 +78,9 @@ extern struct zebra_t zebrad;
 
 /* OS X (Xcode as of 2014-12) is known not to define RT_ROUNDUP */
 #ifdef __APPLE__
-#define ROUNDUP_TYPE	long
-#else
 #define ROUNDUP_TYPE	int
+#else
+#define ROUNDUP_TYPE	long
 #endif
 
 #define ROUNDUP(a) \
