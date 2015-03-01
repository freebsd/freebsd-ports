--- daemon/repo-mgr.c.orig	2015-01-28 02:18:05.000000000 -0500
+++ daemon/repo-mgr.c	2015-01-28 02:22:10.000000000 -0500
@@ -2514,13 +2514,13 @@
     gboolean force_conflict = FALSE;
     gboolean update_mode_only = FALSE;
 
-#ifndef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    path = build_checkout_path (worktree, name, strlen(name));
+#else
     path = build_case_conflict_free_path (worktree, name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict,
                                           FALSE);
-#else
-    path = build_checkout_path (worktree, name, strlen(name));
 #endif
 
     if (!path)
@@ -2675,13 +2675,13 @@
     char *path;
     gboolean case_conflict = FALSE;
 
-#ifndef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    path = build_checkout_path (worktree, name, strlen(name));
+#else
     path = build_case_conflict_free_path (worktree, name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict,
                                           FALSE);
-#else
-    path = build_checkout_path (worktree, name, strlen(name));
 #endif
 
     if (!path)
@@ -2839,13 +2839,13 @@
     old_path = g_build_filename (worktree, de->name, NULL);
 
     if (seaf_util_exists (old_path)) {
-#ifndef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+        new_path = build_checkout_path (worktree, de->new_name, strlen(de->new_name));
+#else
         new_path = build_case_conflict_free_path (worktree, de->new_name,
                                                   conflict_hash, no_conflict_hash,
                                                   &case_conflict,
                                                   TRUE);
-#else
-        new_path = build_checkout_path (worktree, de->new_name, strlen(de->new_name));
 #endif
 
         if (seaf_util_rename (old_path, new_path) < 0) {
