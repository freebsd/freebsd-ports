--- daemon/vc-utils.c.orig	2016-12-03 06:02:47 UTC
+++ daemon/vc-utils.c
@@ -736,7 +736,7 @@ checkout_entry (struct cache_entry *ce,
     gboolean force_conflict = FALSE;
 
     path_in = g_build_path ("/", o->base, ce->name, NULL);
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
     path = build_case_conflict_free_path (o->base, ce->name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict,
