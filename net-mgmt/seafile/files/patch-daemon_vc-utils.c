--- daemon/vc-utils.c.orig	2014-06-05 02:25:50.000000000 -0400
+++ daemon/vc-utils.c	2014-07-27 01:10:00.000000000 -0400
@@ -489,7 +489,7 @@
 
 #endif  /* defined WIN32 || defined __APPLE__ */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 
 static char *
 build_checkout_path (const char *worktree, const char *ce_name, int len)
@@ -549,12 +549,12 @@
     gboolean force_conflict = FALSE;
 
     path_in = g_build_path ("/", o->base, ce->name, NULL);
-#ifndef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    path = build_checkout_path (o->base, ce->name, ce_namelen(ce));
+#else
     path = build_case_conflict_free_path (o->base, ce->name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict);
-#else
-    path = build_checkout_path (o->base, ce->name, ce_namelen(ce));
 #endif
 
     g_free (path_in);
