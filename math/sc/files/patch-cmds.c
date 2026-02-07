--- cmds.c.orig	2011-07-25 22:13:45.000000000 +0200
+++ cmds.c	2011-07-25 22:13:47.000000000 +0200
@@ -2861,12 +2861,12 @@ writefile(char *fname, int r0, int c0, i
 	if ((plugin = findplugin(p+1, 'w')) != NULL) {
 	    if (!plugin_exists(plugin, strlen(plugin), save + 1)) {
 		error("plugin not found");
-		return;
+		return (-1);
 	    }
 	    *save = '|';
 	    if ((strlen(save) + strlen(fname) + 20) > PATHLEN) {
 		error("Path too long");
-		return;
+		return (-1);
 	    }
 	    sprintf(save + strlen(save), " %s%d:", coltoa(c0), r0);
 	    sprintf(save + strlen(save), "%s%d \"%s\"", coltoa(cn), rn, fname);
@@ -2981,12 +2981,12 @@ readfile(char *fname, int eraseflg)
 	if ((plugin = findplugin(p+1, 'r')) != NULL) {
 	    if (!(plugin_exists(plugin, strlen(plugin), save + 1))) {
 		error("plugin not found");
-		return;
+		return (-1);
 	    }
 	    *save = '|';
 	    if ((strlen(save) + strlen(fname) + 2) > PATHLEN) {
 		error("Path too long");
-		return;
+		return (-1);
 	    }
 	    sprintf(save + strlen(save), " \"%s\"", fname);
 	    eraseflg = 0;
