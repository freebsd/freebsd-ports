diff --git libpkg/pkg_ports.c libpkg/pkg_ports.c
index 744ad4a..4308196 100644
--- libpkg/pkg_ports.c
+++ libpkg/pkg_ports.c
@@ -1056,7 +1056,8 @@ plist_new(struct pkg *pkg, const char *stage)
 
 	p->pkg = pkg;
 	pkg_get(pkg, PKG_PREFIX, &prefix);
-	strlcpy(p->prefix, prefix, sizeof(p->prefix));
+	if (prefix != NULL)
+		strlcpy(p->prefix, prefix, sizeof(p->prefix));
 	p->slash = p->prefix[strlen(p->prefix) - 1] == '/' ? "" : "/";
 	p->stage = stage;
 	p->uname = strdup("root");
