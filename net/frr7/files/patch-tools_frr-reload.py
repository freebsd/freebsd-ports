From 1c23a0aaa1c5d20af50af75b070e93e1eff21222 Mon Sep 17 00:00:00 2001
From: Paul Manley <paul.manley@wholefoods.com>
Date: Thu, 9 Jul 2020 11:21:16 -0500
Subject: [PATCH] tools: create sub-context for bfd peers

add lines starting with 'peer' to the list of sub-contexts that are handled by frr-reload.py.

https://github.com/FRRouting/frr/issues/6511#issuecomment-655163833

Signed-off-by: Paul Manley <paul.manley@wholefoods.com>
--- tools/frr-reload.py.orig	2020-06-30 11:08:57 UTC
+++ tools/frr-reload.py
@@ -496,6 +496,7 @@ end
                   line.startswith("vnc defaults") or
                   line.startswith("vnc l2-group") or
                   line.startswith("vnc nve-group") or
+                  line.startswith("peer") or
                   line.startswith("member pseudowire")):
                 main_ctx_key = []
 
