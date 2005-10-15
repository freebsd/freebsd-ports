--- plugins/check_snmp.c.orig	Sat Oct 15 09:41:06 2005
+++ plugins/check_snmp.c	Sat Oct 15 09:48:43 2005
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

