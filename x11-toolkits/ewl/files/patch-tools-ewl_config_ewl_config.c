--- tools/ewl_config/ewl_config.c.orig	2009-11-23 20:47:09.000000000 +0100
+++ tools/ewl_config/ewl_config.c	2009-11-23 20:47:42.000000000 +0100
@@ -342,8 +342,8 @@
 		ret = ec_themes_get(rep, list, v);
 		if (ret >= 0)
 			sel = ret;
+		closedir(rep);
 	}
-	closedir(rep);
 
 	home_dir = getenv("HOME");
 	snprintf(path, PATH_MAX, "%s/%s", home_dir, ".ewl/themes");
@@ -355,8 +355,8 @@
 		ret = ec_themes_get(rep, list, v);
 		if (ret >= 0)
 			sel = ret;
+		closedir(rep);
 	}
-	closedir(rep);
 
 	if (sel >= 0)
 		ewl_mvc_selected_set(EWL_MVC(o), NULL, list, sel, 0);
