--- src/mod/applications/mod_ladspa/mod_ladspa.c.orig	2011-07-05 22:23:14.000000000 -0400
+++ src/mod/applications/mod_ladspa/mod_ladspa.c	2011-07-05 22:24:32.000000000 -0400
@@ -634,6 +634,8 @@
 			setenv("LADSPA_PATH", "/usr/lib64/ladspa/:/usr/local/lib/ladspa", 1);
 		} else if (switch_directory_exists("/usr/lib/ladspa/", pool) == SWITCH_STATUS_SUCCESS) {
 			setenv("LADSPA_PATH", "/usr/lib/ladspa/:/usr/local/lib/ladspa", 1);
+		} else if (switch_directory_exists("/usr/local/lib/ladspa/", pool) == SWITCH_STATUS_SUCCESS) {
+			putenv("LADSPA_PATH=/usr/local/lib/ladspa");
 		}
 	}
 
