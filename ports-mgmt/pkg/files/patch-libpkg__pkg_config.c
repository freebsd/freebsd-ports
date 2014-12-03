commit 67751707406b7da5ff85978f755d4e68bab3d38d
Author: Bryan Drewery <bryan@shatow.net>
Date:   Wed Sep 24 13:30:29 2014 -0500

    Fix repo override crashing when URL is not defined.
    
    Only override URL if one is provided.
    
    Issue:	#1024

diff --git libpkg/pkg_config.c libpkg/pkg_config.c
index ec96883..83e2f5d 100644
--- libpkg/pkg_config.c
+++ libpkg/pkg_config.c
@@ -1065,9 +1065,11 @@ pkg_repo_overwrite(struct pkg_repo *r, const char *name, const char *url,
 {
 
 	free(r->name);
-	free(r->url);
 	r->name = strdup(name);
-	r->url = strdup(url);
+	if (url != NULL) {
+		free(r->url);
+		r->url = strdup(url);
+	}
 	r->ops = pkg_repo_find_type(type);
 	HASH_DEL(repos, r);
 	HASH_ADD_KEYPTR(hh, repos, r->name, strlen(r->name), r);
