--- lib/module.c.orig	Sun Nov 21 00:14:24 2004
+++ lib/module.c	Sun Nov 21 00:38:36 2004
@@ -40,9 +40,11 @@
 	 */
 	handle = sys_dlopen(module_name, RTLD_LAZY);
 
+	/* This call should reset any possible non-fatal errors that 
+	   occured since last call to dl* functions */
+	error = sys_dlerror();
 	if(!handle) {
 		int level = is_probe ? 3 : 0;
-		error = sys_dlerror();
 		DEBUG(level, ("Error loading module '%s': %s\n", module_name, error ? error : ""));
 		return NT_STATUS_UNSUCCESSFUL;
 	}
