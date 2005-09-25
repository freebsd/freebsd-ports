--- src/lib/ewl_config.c.orig	Mon Mar 28 22:32:26 2005
+++ src/lib/ewl_config.c	Sun Sep 25 11:20:04 2005
@@ -210,8 +210,8 @@
 
 		cc = ewl_config_int_get("/ewl/theme/color_classes/count");
 		prop = ecore_config_get("/ewl/theme/color_classes/count");
-		prop->flags &= ~PF_MODIFIED;
-		prop->flags |= PF_SYSTEM;
+		prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+		prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 		for (i = 0; i < cc; i++) {
 			char *name;
@@ -221,8 +221,8 @@
 					"/ewl/theme/color_classes/%d/name", i);
 			name = ewl_config_str_get(key);
 			prop = ecore_config_get(key);
-			prop->flags &= ~PF_MODIFIED;
-			prop->flags |= PF_SYSTEM;
+			prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+			prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 			if (name) {
 				int r, g, b, a;
@@ -233,85 +233,85 @@
 						"/ewl/theme/color_classes/%d/r", i);
 				r = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/g", i);
 				g = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/b", i);
 				b = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/a", i);
 				a = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/r2", i);
 				r2 = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/g2", i);
 				g2 = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/b2", i);
 				b2 = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/a2", i);
 				a2 = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/r3", i);
 				r3 = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/g3", i);
 				g3 = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/b3", i);
 				b3 = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				snprintf(key, PATH_MAX,
 						"/ewl/theme/color_classes/%d/a3", i);
 				a3 = ewl_config_int_get(key);
 				prop = ecore_config_get(key);
-				prop->flags &= ~PF_MODIFIED;
-				prop->flags |= PF_SYSTEM;
+				prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+				prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 
 				edje_color_class_set(name, r, g, b, a,
 						r2, g2, b2, a2,
@@ -389,8 +389,8 @@
 
 		for(i = 0; keys[i] != NULL; i++) {
 			prop = ecore_config_get(keys[i]);
-			prop->flags &= ~PF_MODIFIED;
-			prop->flags |= PF_SYSTEM;
+			prop->flags &= ~ECORE_CONFIG_FLAG_MODIFIED;
+			prop->flags |= ECORE_CONFIG_FLAG_SYSTEM;
 		}
 
 		ecore_config_listen("ewl_debug_enable", "/ewl/debug/enable",
