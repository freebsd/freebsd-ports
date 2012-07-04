diff --git libpkg/pkg_repo.c libpkg/pkg_repo.c
index d2ef999..d628850 100644
--- libpkg/pkg_repo.c
+++ libpkg/pkg_repo.c
@@ -605,8 +605,7 @@ pkg_create_repo(char *path, bool force, void (progress)(struct pkg *pkg, void *d
 	while ((ent = fts_read(fts)) != NULL) {
 		const char *name, *version, *origin, *comment, *desc;
 		const char *arch, *maintainer, *www, *prefix;
-		int64_t flatsize;
-		lic_t licenselogic;
+		int64_t flatsize, licenselogic;
 
 		/* skip everything that is not a file */
 		if (ent->fts_info != FTS_F)
