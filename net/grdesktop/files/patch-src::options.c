--- src/options.c	Tue Feb  3 09:49:48 2004
+++ src/options.c.new	Sun Feb 29 17:23:08 2004
@@ -20,6 +20,7 @@
  */
 
 
+#include "global.h"
 #include "options.h"
 
 void fillRdpProtocols() {
@@ -276,6 +277,9 @@
 		item = g_slist_nth_data(values, i);
 		typ = gconf_entry_get_value(item);
 
+		if (!typ)
+			continue ;
+
 		path = g_strsplit(gconf_entry_get_key(item), "/", 0);
 		while(path[y] != NULL)
 			y++;
@@ -487,6 +491,7 @@
 
 		while((entry = readdir(licence_dir)) != NULL) {
 			gchar *fullname = NULL;
+			gchar *hostname = &entry->d_name[strlen(prefix)];
 			struct stat sts;
 
 			fullname = g_strdup_printf("%s/%s", licence_path,
@@ -500,7 +505,6 @@
 			if(strlen(entry->d_name) <= strlen(prefix))
 				continue;
 
-			gchar *hostname = &entry->d_name[strlen(prefix)];
 			licence_list = g_list_append(licence_list, g_strdup(hostname));
 		}
 		closedir(licence_dir);
