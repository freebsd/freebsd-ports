diff --git src/version.c src/version.c
index d265776b..92c18060 100644
--- src/version.c
+++ src/version.c
@@ -601,6 +601,8 @@ exec_buf(UT_string *res, char **argv) {
 		if (errno != EINTR)
 			return (-1);
 	}
+	if (WEXITSTATUS(pstat) != 0)
+		return (-1);
 
 	return (utstring_len(res));
 }
@@ -716,11 +718,13 @@ port_version(UT_string *cmd, const char *portsdir, const char *origin,
 		argv[3] = "flavors-package-names";
 		argv[4] = NULL;
 
-		if (exec_buf(cmd, argv) != 0) {
+		if (exec_buf(cmd, argv) > 0) {
 			output = utstring_body(cmd);
 			while ((walk = strsep(&output, "\n")) != NULL) {
 				name = walk;
 				walk = strrchr(walk, '-');
+				if (walk == NULL)
+					continue;
 				walk[0] = '\0';
 				walk++;
 				if (strcmp(name, pkgname) == 0) {
