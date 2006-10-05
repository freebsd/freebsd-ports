diff -urN -x .svn ../../../tags/vpopmail-5.4.14-stock/vdeldomain.c ./vdeldomain.c
--- ../../../tags/vpopmail-5.4.14-stock/vdeldomain.c	Mon Oct  2 13:49:02 2006
+++ ./vdeldomain.c	Mon Oct  2 16:36:38 2006
@@ -67,7 +67,7 @@
 		if (strcmp(entry->domain, entry->realdomain) != 0) {
 			aliases[aliascount++] = strdup(entry->domain);
 		} else {
-			strcpy(parent,entry->domain);
+			snprintf(parent,sizeof(parent),"%s",entry->domain);
 		}
 
 		entry = get_domain_entries(NULL);
