--- ntfsprogs/Makefile.am.orig	Sat Oct  8 00:35:40 2005
+++ ntfsprogs/Makefile.am	Fri Jan 20 11:26:37 2006
@@ -88,7 +88,7 @@
 ntfsmount_SOURCES	= ntfsmount.c utils.c utils.h
 ntfsmount_LDADD		= $(AM_LIBS) $(FUSE_MODULE_LIBS)
 ntfsmount_LDFLAGS	= $(AM_LFLAGS)
-ntfsmount_CFLAGS	= $(FUSE_MODULE_CFLAGS) -DFUSE_USE_VERSION=22
+ntfsmount_CFLAGS	= $(FUSE_MODULE_CFLAGS) -DFUSE_USE_VERSION=25
 endif
 
 # We don't distribute these
--- ntfsprogs/Makefile.in.orig	Fri Jan 20 11:24:48 2006
+++ ntfsprogs/Makefile.in	Fri Jan 20 11:26:40 2006
@@ -366,7 +366,7 @@
 @ENABLE_FUSE_MODULE_TRUE@ntfsmount_SOURCES = ntfsmount.c utils.c utils.h
 @ENABLE_FUSE_MODULE_TRUE@ntfsmount_LDADD = $(AM_LIBS) $(FUSE_MODULE_LIBS)
 @ENABLE_FUSE_MODULE_TRUE@ntfsmount_LDFLAGS = $(AM_LFLAGS)
-@ENABLE_FUSE_MODULE_TRUE@ntfsmount_CFLAGS = $(FUSE_MODULE_CFLAGS) -DFUSE_USE_VERSION=22
+@ENABLE_FUSE_MODULE_TRUE@ntfsmount_CFLAGS = $(FUSE_MODULE_CFLAGS) -DFUSE_USE_VERSION=25
 
 # We don't distribute these
 ntfsrm_SOURCES = ntfsrm.c ntfsrm.h utils.c utils.h
--- ntfsprogs/ntfsmount.c.orig	Mon Oct 10 14:47:38 2005
+++ ntfsprogs/ntfsmount.c	Fri Jan 20 11:42:09 2006
@@ -81,10 +81,10 @@
 	int state;
 	long free_clusters;
 	long free_mft;
-	uid_t uid;
-	gid_t gid;
-	mode_t fmask;
-	mode_t dmask;
+	unsigned int uid;
+	unsigned int gid;
+	unsigned int fmask;
+	unsigned int dmask;
 	BOOL ro;
 	BOOL show_sys_files;
 	BOOL succeed_chmod;
@@ -196,7 +196,7 @@
  * Return 0 on success or -errno on error.
  */
 static int ntfs_fuse_statfs(const char *path __attribute__((unused)),
-		struct statfs *sfs)
+		struct statvfs *sfs)
 {
 	long size;
 	ntfs_volume *vol;
@@ -204,10 +204,10 @@
 	vol = ctx->vol;
 	if (!vol)
 		return -ENODEV;
-	/* Type of filesystem. */
-	sfs->f_type = NTFS_SB_MAGIC;
 	/* Optimal transfer block size. */
 	sfs->f_bsize = vol->cluster_size;
+	/* XXX This field needs to be filled, I guess it's fine this way... */
+	sfs->f_frsize = vol->cluster_size;
 	/*
 	 * Total data blocks in file system in units of f_bsize and since
 	 * inodes are also stored in data blocs ($MFT is a file) this is just
@@ -228,7 +228,7 @@
 		size = 0;
 	sfs->f_ffree = size;
 	/* Maximum length of filenames. */
-	sfs->f_namelen = NTFS_MAX_NAME_LEN;
+	sfs->f_namemax = NTFS_MAX_NAME_LEN;
 	return 0;
 }
 
@@ -1462,8 +1462,9 @@
 int main(int argc, char *argv[])
 {
 	char *parsed_options;
+	struct fuse_args margs = FUSE_ARGS_INIT(0, NULL);
 	struct fuse *fh;
-	int ffd;
+	int ffd = 0;
 
 	utils_set_locale();
 	signal(SIGINT, signal_handler);
@@ -1491,7 +1492,20 @@
 	}
 	free(opts.device);
 	/* Create filesystem. */
-	ffd = fuse_mount(opts.mnt_point, parsed_options);
+	/*
+	 * XXX Eventually, ntfsmount should drop it's homebrew option parsing
+	 * routines and use stock ones. Here we don't go that far, we just use the
+	 * FUSE opt parsing API to dummily create the structure which satisfies
+	 * fuse_mount's current signature (that is, revert all the work which
+	 * has been accomplished by the homebrew routine... silly, eh?).
+	 */
+	if ((fuse_opt_add_arg(&margs, "") == -1 ||
+	     fuse_opt_add_arg(&margs, "-o") == -1 ||
+	     fuse_opt_add_arg(&margs, parsed_options) == -1))
+		ffd = -1;
+	if (ffd != -1)
+		ffd = fuse_mount(opts.mnt_point, &margs);
+	fuse_opt_free_args(&margs);
 	if (ffd == -1) {
 		Eprintf("fuse_mount failed.\n");
 		ntfs_fuse_destroy();
