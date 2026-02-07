From 9db92ede5e52f50b8a45556c173343f9967c36ad Mon Sep 17 00:00:00 2001
From: Lorenzo Zolfanelli <dev@zolfa.nl>
Date: Fri, 22 Dec 2023 13:52:19 +0100
Subject: [PATCH] fix: compatibility with new PFIL version

Since FreeBSD 14 a new PFIL_VERSION has been introduced with a slight
different data structure definition for `pfil_hook_args`.

See https://github.com/freebsd/freebsd-src/commit/caf32b260ad46b17a4c1a8ce6383e37ac489f023
for details of the new PFIL_VERSION implementation.

With this fix is possible to compile against FreeBSD 14 kernel, and the
pre-processor instruction should assure backwards compatibility.
--- ndproxy.c.orig	2019-02-19 09:43:44 UTC
+++ ndproxy.c
@@ -54,7 +54,7 @@ static pfil_hook_t pfh_hook;
 
 static pfil_hook_t pfh_hook;
 
-static void register_hook() {
+static void register_hook(void) {
   struct pfil_hook_args pha;
   struct pfil_link_args pla;
 
@@ -66,7 +66,11 @@ static void register_hook() {
   pha.pa_modname = "ndproxy";
   pha.pa_ruleset = NULL;
   pha.pa_rulname = "default-in6";
+#if PFIL_VERSION > 1
+  pha.pa_mbuf_chk = packet;
+#else
   pha.pa_func = packet;
+#endif
   pfh_hook = pfil_add_hook(&pha);
 
   pla.pa_version = PFIL_VERSION;
@@ -78,7 +82,7 @@ static void register_hook() {
   hook_added = true;
 }
 
-static void unregister_hook() {
+static void unregister_hook(void) {
   if (!hook_added) return;
   pfil_remove_hook(pfh_hook);
 }
