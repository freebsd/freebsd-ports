--- daemon/vc-utils.c.orig	2015-01-28 02:24:19.000000000 -0500
+++ daemon/vc-utils.c	2015-01-28 02:30:05.000000000 -0500
@@ -664,7 +664,7 @@
 
 #endif  /* defined WIN32 || defined __APPLE__ */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 
 char *
 build_checkout_path (const char *worktree, const char *ce_name, int len)
@@ -724,13 +724,13 @@
     gboolean force_conflict = FALSE;
 
     path_in = g_build_path ("/", o->base, ce->name, NULL);
-#ifndef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    path = build_checkout_path (o->base, ce->name, ce_namelen(ce));
+#else
     path = build_case_conflict_free_path (o->base, ce->name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict,
                                           FALSE);
-#else
-    path = build_checkout_path (o->base, ce->name, ce_namelen(ce));
 #endif
 
     g_free (path_in);
