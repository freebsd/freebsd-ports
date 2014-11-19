--- daemon/repo-mgr.c.orig	2014-08-30 02:03:22.367472662 -0400
+++ daemon/repo-mgr.c	2014-08-30 02:10:42.071207749 -0400
@@ -1720,12 +1720,12 @@
     gboolean force_conflict = FALSE;
     gboolean update_mode_only = FALSE;
 
-#ifndef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    path = build_checkout_path (worktree, name, strlen(name));
+#else
     path = build_case_conflict_free_path (worktree, name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict);
-#else
-    path = build_checkout_path (worktree, name, strlen(name));
 #endif
 
     if (!path)
@@ -1858,12 +1858,12 @@
     char *path;
     gboolean case_conflict = FALSE;
 
-#ifndef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+    path = build_checkout_path (worktree, name, strlen(name));
+#else
     path = build_case_conflict_free_path (worktree, name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict);
-#else
-    path = build_checkout_path (worktree, name, strlen(name));
 #endif
 
     if (!path)
@@ -2088,12 +2088,12 @@
 
             char *new_path;
             gboolean case_conflict;
-#ifndef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+            new_path = build_checkout_path (worktree, de->new_name, strlen(de->new_name));
+#else
             new_path = build_case_conflict_free_path (worktree, de->new_name,
                                                       conflict_hash, no_conflict_hash,
                                                       &case_conflict);
-#else
-            new_path = build_checkout_path (worktree, de->new_name, strlen(de->new_name));
 #endif
 
             if (g_file_test (old_path, G_FILE_TEST_EXISTS) &&
