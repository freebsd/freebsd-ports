--- daemon/vc-utils.c.orig	2016-04-05 08:38:26 UTC
+++ daemon/vc-utils.c
@@ -664,7 +664,7 @@ error:
 
 #endif  /* defined WIN32 || defined __APPLE__ */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 
 char *
 build_checkout_path (const char *worktree, const char *ce_name, int len)
@@ -724,7 +724,7 @@ checkout_entry (struct cache_entry *ce,
     gboolean force_conflict = FALSE;
 
     path_in = g_build_path ("/", o->base, ce->name, NULL);
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
     path = build_case_conflict_free_path (o->base, ce->name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict,
