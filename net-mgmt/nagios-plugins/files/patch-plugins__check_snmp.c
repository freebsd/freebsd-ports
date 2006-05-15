--- plugins/check_snmp.c.orig	Tue Nov  1 06:33:19 2005
+++ plugins/check_snmp.c	Fri May 12 23:29:24 2006
@@ -206,6 +206,7 @@
 	strcat(perfstr, "| ");
 	while (ptr) {
 		char *foo;
+		char *str[MAX_INPUT_BUFFER];
 
 		foo = strstr (ptr, delimiter);
 		strncat(perfstr, ptr, foo-ptr);
@@ -338,7 +339,6 @@
 
 		i++;
 
-		char *str[MAX_INPUT_BUFFER];
 		asprintf(str, "=%s%s;;;; ", show, type ? type : "");
 		strcat(perfstr, *str);
 
