--- daemon/repo-mgr.c.orig	2016-05-10 12:25:35 UTC
+++ daemon/repo-mgr.c
@@ -4441,7 +4441,7 @@ checkout_file (const char *repo_id,
     gboolean force_conflict = FALSE;
     gboolean update_mode_only = FALSE;
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
     path = build_case_conflict_free_path (worktree, name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict,
@@ -4617,7 +4617,7 @@ checkout_empty_dir (const char *worktree
     char *path;
     gboolean case_conflict = FALSE;
 
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
     path = build_case_conflict_free_path (worktree, name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict,
@@ -5038,7 +5038,7 @@ schedule_file_fetch (GThreadPool *tpool,
     }
 
     if (!skip_fetch) {
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
         gboolean case_conflict = FALSE;
         path = build_case_conflict_free_path (worktree, de->name,
                                               conflict_hash, no_conflict_hash,
@@ -5185,7 +5185,7 @@ checkout_file_http (FileTxData *data,
      * A.txt to checkout, we can only detect case conflict after one file is checkecd
      * out. So we need to generate a new one here.
      */
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
     path = build_case_conflict_free_path (worktree, de->name,
                                           conflict_hash, no_conflict_hash,
                                           &case_conflict,
@@ -5567,7 +5567,7 @@ do_rename_in_worktree (DiffEntry *de, co
     old_path = g_build_filename (worktree, de->name, NULL);
 
     if (seaf_util_exists (old_path)) {
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__) && !defined(__DragonFly__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
         gboolean case_conflict;
         new_path = build_case_conflict_free_path (worktree, de->new_name,
                                                   conflict_hash, no_conflict_hash,
