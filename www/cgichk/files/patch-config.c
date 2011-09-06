--- config.c.orig	2011-09-06 11:18:17.000000000 +0800
+++ config.c	2011-09-06 11:18:33.000000000 +0800
@@ -30,14 +30,14 @@ result_t *open_config(char *fn)
 	}
 
 	// ...try defaults, current dir...
-	if (r->F = fopen("./cgichk.cfg", "rb"))
+	if ((r->F = fopen("./cgichk.cfg", "rb")))
 	{
 		resultfile = (char *) strdup("./cgichk.cfg");
 		return r;
 	}
 
 	// ...and then config dir
-	if (r->F = fopen(CONFIG_PATH, "rb"))
+	if ((r->F = fopen(CONFIG_PATH, "rb")))
 	{
 		resultfile = (char *) strdup(CONFIG_PATH);
 		return r;
