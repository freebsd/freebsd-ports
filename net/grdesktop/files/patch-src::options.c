--- src/options.c.orig	Mon Feb  2 15:05:53 2004
+++ src/options.c	Thu Feb 26 10:58:47 2004
@@ -20,6 +20,7 @@
  */
 
 
+#include "global.h"
 #include "options.h"
 
 void fillRdpProtocols() {
@@ -275,6 +276,8 @@
 
 		item = g_slist_nth_data(values, i);
 		typ = gconf_entry_get_value(item);
+		if (!typ)
+			continue ;
 
 		path = g_strsplit(gconf_entry_get_key(item), "/", 0);
 		while(path[y] != NULL)
@@ -489,6 +492,7 @@
 
 		while((entry = readdir(licence_dir)) != NULL) {
 			gchar *fullname = NULL;
+			gchar *hostname;
 			struct stat sts;
 
 			fullname = g_strdup_printf("%s/%s", licence_path,
@@ -502,7 +506,7 @@
 			if(strlen(entry->d_name) <= strlen(prefix))
 				continue;
 
-			gchar *hostname = &entry->d_name[strlen(prefix)];
+			hostname = &entry->d_name[strlen(prefix)];
 			licence_list = g_list_append(licence_list, hostname);
 		}
 		closedir(licence_dir);
