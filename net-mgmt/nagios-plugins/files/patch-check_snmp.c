--- plugins/check_snmp.c.orig	Wed Sep  7 12:35:57 2005
+++ plugins/check_snmp.c	Wed Sep  7 12:43:03 2005
@@ -141,6 +141,7 @@
 	char *p2 = NULL;
 	char *show = NULL;
 	char type[8];
+	char *str[MAX_INPUT_BUFFER];
 
 	setlocale (LC_ALL, ""); setlocale(LC_NUMERIC, "C");
 	bindtextdomain (PACKAGE, LOCALEDIR);
@@ -338,7 +339,6 @@
 
 		i++;
 
-		char *str[MAX_INPUT_BUFFER];
 		asprintf(str, "=%s%s;;;; ", show, type ? type : "");
 		strcat(perfstr, *str);
 
