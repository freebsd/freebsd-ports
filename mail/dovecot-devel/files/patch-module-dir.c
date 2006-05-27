--- src/lib/module-dir.c.orig	Sat May  6 10:00:05 2006
+++ src/lib/module-dir.c	Sun May 28 06:22:06 2006
@@ -24,6 +24,9 @@
 	const char *error;
 	void *ret;
 
+	/* reset dlerror */
+	(void)dlerror();
+
 	/* get our init func */
 	ret = dlsym(module->handle, symbol);
 
