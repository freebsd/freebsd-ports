--- plugins/sudoers/match.c	Mon Jan 15 10:31:56 2018 -0700
+++ plugins/sudoers/match.c	Tue Apr 24 09:49:28 2018 -0600
@@ -1,5 +1,5 @@ 
 /*
- * Copyright (c) 1996, 1998-2005, 2007-2017
+ * Copyright (c) 1996, 1998-2005, 2007-2018
  *	Todd C. Miller <Todd.Miller@sudo.ws>
  *
  * Permission to use, copy, modify, and distribute this software for any
@@ -447,31 +447,20 @@ do_stat(int fd, const char *path, struct
 }
 
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
@@ -500,16 +489,57 @@ open_cmnd(const char *path, const struct
     if (fd == -1)
 	debug_return_bool(false);
 
-    set_cloexec(fd);
+    (void)fcntl(fd, F_SETFD, FD_CLOEXEC);
     *fdp = fd;
     debug_return_bool(true);
 }
 
+static void
+set_cmnd_fd(int fd)
+{
+    debug_decl(set_cmnd_fd, SUDOERS_DEBUG_MATCH)
+
+    if (cmnd_fd != -1)
+	close(cmnd_fd);
+
+    if (fd != -1) {
+	if (def_fdexec == never) {
+	    /* Never use fexedcve() */
+	    close(fd);
+	    fd = -1;
+	} else if (is_script(fd)) {
+	    char fdpath[PATH_MAX];
+	    struct stat sb;
+	    int flags;
+
+	    /* We can only use fexecve() on a script if /dev/fd/N exists. */
+	    snprintf(fdpath, sizeof(fdpath), "/dev/fd/%d", fd);
+	    if (stat(fdpath, &sb) != 0) {
+		/* Missing /dev/fd file, can't use fexecve(). */
+		close(fd);
+		fd = -1;
+	    } else {
+		/*
+		 * Shell scripts go through namei twice so we can't have the
+		 * close on exec flag set on the fd for fexecve(2).
+		 */
+		flags = fcntl(fd, F_GETFD) & ~FD_CLOEXEC;
+		(void)fcntl(fd, F_SETFD, flags);
+	    }
+	}
+    }
+
+    cmnd_fd = fd;
+
+    debug_return;
+}
+
 static bool
 command_matches_fnmatch(const char *sudoers_cmnd, const char *sudoers_args,
     const struct sudo_digest *digest)
 {
     struct stat sb; /* XXX - unused */
+    int fd = -1;
     debug_decl(command_matches_fnmatch, SUDOERS_DEBUG_MATCH)
 
     /*
@@ -522,30 +552,22 @@ command_matches_fnmatch(const char *sudo
     if (fnmatch(sudoers_cmnd, user_cmnd, FNM_PATHNAME) != 0)
 	debug_return_bool(false);
     if (command_args_match(sudoers_cmnd, sudoers_args)) {
-	if (cmnd_fd != -1) {
-	    close(cmnd_fd);
-	    cmnd_fd = -1;
-	}
 	/* Open the file for fdexec or for digest matching. */
-	if (!open_cmnd(user_cmnd, digest, &cmnd_fd))
+	if (!open_cmnd(user_cmnd, digest, &fd))
 	    goto bad;
-	if (!do_stat(cmnd_fd, user_cmnd, &sb))
+	if (!do_stat(fd, user_cmnd, &sb))
 	    goto bad;
 	/* Check digest of user_cmnd since sudoers_cmnd is a pattern. */
-	if (digest != NULL) {
-	    if (!digest_matches(cmnd_fd, user_cmnd, digest))
-		goto bad;
-	    if (def_fdexec == never) {
-		close(cmnd_fd);
-		cmnd_fd = -1;
-	    }
-	}
+	if (digest != NULL && !digest_matches(fd, user_cmnd, digest))
+	    goto bad;
+	set_cmnd_fd(fd);
+
 	/* No need to set safe_cmnd since user_cmnd matches sudoers_cmnd */
 	debug_return_bool(true);
 bad:
-	if (cmnd_fd != -1) {
-	    close(cmnd_fd);
-	    cmnd_fd = -1;
+	if (fd != -1) {
+	    close(fd);
+	    fd = -1;
 	}
 	debug_return_bool(false);
     }
@@ -673,16 +695,7 @@ done:
     if (cp != NULL) {
 	if (command_args_match(sudoers_cmnd, sudoers_args)) {
 	    /* safe_cmnd was set above. */
-	    if (cmnd_fd != -1) {
-		close(cmnd_fd);
-		cmnd_fd = -1;
-	    }
-	    if (fd != -1) {
-		if (def_fdexec == never)
-		    close(fd);
-		else
-		    cmnd_fd = fd;
-	    }
+	    set_cmnd_fd(fd);
 	    debug_return_bool(true);
 	}
     }
@@ -728,6 +741,7 @@ digest_matches(int fd, const char *file,
     debug_decl(digest_matches, SUDOERS_DEBUG_MATCH)
 
     file_digest = sudo_filedigest(fd, file, sd->digest_type, &digest_len);
+    lseek(fd, SEEK_SET, (off_t)0);
     if (file_digest == NULL) {
 	/* Warning (if any) printed by sudo_filedigest() */
 	goto done;
@@ -826,16 +840,7 @@ command_matches_normal(const char *sudoe
 	sudo_warnx(U_("%s: %s"), __func__, U_("unable to allocate memory"));
 	goto bad;
     }
-    if (cmnd_fd != -1) {
-	close(cmnd_fd);
-	cmnd_fd = -1;
-    }
-    if (fd != -1) {
-	if (def_fdexec == never)
-	    close(fd);
-	else
-	    cmnd_fd = fd;
-    }
+    set_cmnd_fd(fd);
     debug_return_bool(true);
 bad:
     if (fd != -1)
@@ -921,16 +926,7 @@ command_matches_dir(const char *sudoers_
     closedir(dirp);
 
     if (dent != NULL) {
-	if (cmnd_fd != -1) {
-	    close(cmnd_fd);
-	    cmnd_fd = -1;
-	}
-	if (fd != -1) {
-	    if (def_fdexec == never)
-		close(fd);
-	    else
-		cmnd_fd = fd;
-	}
+	set_cmnd_fd(fd);
 	debug_return_bool(true);
     }
     if (fd != -1)
