--- plugins/imfile/imfile.c.orig	2015-06-30 12:26:24 UTC
+++ plugins/imfile/imfile.c
@@ -1869,12 +1869,14 @@ CODESTARTmodExit
 	objRelease(errmsg, CORE_COMPONENT);
 	objRelease(prop, CORE_COMPONENT);
 	objRelease(ruleset, CORE_COMPONENT);
+#ifdef HAVE_SYS_INOTIFY_H
 	if(dirs != NULL) {
 		free(dirs->active.listeners);
 		free(dirs->configured.listeners);
 		free(dirs);
 	}
 	free(wdmap);
+#endif
 ENDmodExit
 
 
