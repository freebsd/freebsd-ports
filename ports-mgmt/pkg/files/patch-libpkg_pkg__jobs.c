--- libpkg/pkg_jobs.c.orig	2026-07-21 09:50:31 UTC
+++ libpkg/pkg_jobs.c
@@ -925,7 +925,8 @@ pkg_jobs_find_upgrade(struct pkg_jobs *j, const char *
 				"remote repo", pattern);
 		rc = pkg_jobs_universe_add_pkg(j->universe, p, &unit);
 		if (rc == EPKG_END) {
-			pkg_free(p);
+			if (!pkg_in_universe(j->universe, p))
+				pkg_free(p);
 			rc = EPKG_OK;
 		}
 	}
