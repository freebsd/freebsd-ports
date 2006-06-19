--- src/lib/module-dir.c.orig	5 May 2006 14:21:22 -0000	1.19
+++ src/lib/module-dir.c	16 Jun 2006 10:15:56 -0000	1.20
@@ -24,14 +24,18 @@
 	const char *error;
 	void *ret;
 
+	/* clear out old errors */
+	(void)dlerror();
+
 	/* get our init func */
 	ret = dlsym(module->handle, symbol);
-
-	error = dlerror();
-	if (error != NULL) {
-		i_error("module %s: dlsym(%s) failed: %s",
-			module->path, symbol, error);
-		ret = NULL;
+	if (ret == NULL) {
+		error = dlerror();
+		if (error != NULL) {
+			i_error("module %s: dlsym(%s) failed: %s",
+				module->path, symbol, error);
+			ret = NULL;
+		}
 	}
 
 	return ret;
