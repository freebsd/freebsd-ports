--- libpkg/pkg_jobs.c.orig	2021-11-12 08:57:25 UTC
+++ libpkg/pkg_jobs.c
@@ -79,7 +79,7 @@ struct pkg_jobs_locked {
 	int (*locked_pkg_cb)(struct pkg *, void *);
 	void *context;
 };
-static __thread struct pkg_jobs_locked *pkgs_job_lockedpkg;
+static struct pkg_jobs_locked *pkgs_job_lockedpkg;
 
 #define IS_DELETE(j) ((j)->type == PKG_JOBS_DEINSTALL || (j)->type == PKG_JOBS_AUTOREMOVE)
 
