--- plugins/sudoers/match.c.orig	2018-04-24 10:49:39 UTC
+++ plugins/sudoers/match.c
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 1996, 1998-2005, 2007-2017
+ * Copyright (c) 1996, 1998-2005, 2007-2018
  *	Todd C. Miller <Todd.Miller@sudo.ws>
  *
  * Permission to use, copy, modify, and distribute this software for any
@@ -446,32 +446,22 @@ do_stat(int fd, const char *path, struct stat *sb)
     debug_return_bool(stat(path, sb) == 0);
 }
 
+#ifdef HAVE_FEXECVE
 /*
- * On systems with fexecve(2), set the close-on-exec flag on the file
- * descriptor only if the file is not a script.  Because scripts need
- * to be executed by an interpreter the fd must remain open for the
- * interpreter to use.
+ * Check whether the fd refers to a shell script with a "#!" shebang.
  */
-static void
-set_cloexec(int fd)
+static bool
+is_script(int fd)
 {
-    bool is_script = false;
-#ifdef HAVE_FEXECVE
+    bool ret = false;
     char magic[2];
 
-    /* Check for #! cookie and set is_script. */
     if (read(fd, magic, 2) == 2) {
 	if (magic[0] == '#' && magic[1] == '!')
-	    is_script = true;
+	    ret = true;
     }
     (void) lseek(fd, (off_t)0, SEEK_SET);
-#endif /* HAVE_FEXECVE */
-    /*
-     * Shell scripts go through namei twice and so we can't set the close
-     * on exec flag on the fd for fexecve(2).
-     */
-    if (!is_script)
-	(void)fcntl(fd, F_SETFD, FD_CLOEXEC);
+    return ret;
 }
 
 /*
@@ -500,10 +490,36 @@ open_cmnd(const char *path, const struct sudo_digest *
     if (fd == -1)
 	debug_return_bool(false);
 
-    set_cloexec(fd);
+    if (is_script(fd)) {
+	char fdpath[PATH_MAX];
+	struct stat sb;
+
+	/* We can only use fexecve() on a script if /dev/fd/N exists. */
+	snprintf(fdpath, sizeof(fdpath), "/dev/fd/%d", fd);
+	if (stat(fdpath, &sb) != 0) {
+	    close(fd);
+	    debug_return_bool(true);
+	}
+
+	/*
+	 * Shell scripts go through namei twice so we can't set the
+	 * close on exec flag on the fd for fexecve(2).
+	 */
+    } else {
+	/* Not a script, close on exec is safe. */
+	(void)fcntl(fd, F_SETFD, FD_CLOEXEC);
+    }
+
     *fdp = fd;
     debug_return_bool(true);
 }
+#else /* HAVE_FEXECVE */
+static bool
+open_cmnd(const char *path, const struct sudo_digest *digest, int *fdp)
+{
+    return true;
+}
+#endif /* HAVE_FEXECVE */
 
 static bool
 command_matches_fnmatch(const char *sudoers_cmnd, const char *sudoers_args,
@@ -728,6 +744,7 @@ digest_matches(int fd, const char *file, const struct 
     debug_decl(digest_matches, SUDOERS_DEBUG_MATCH)
 
     file_digest = sudo_filedigest(fd, file, sd->digest_type, &digest_len);
+    lseek(fd, SEEK_SET, (off_t)0);
     if (file_digest == NULL) {
 	/* Warning (if any) printed by sudo_filedigest() */
 	goto done;
