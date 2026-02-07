--- base/utils.c.orig	2003-04-23 15:33:23 UTC
+++ base/utils.c
@@ -43,7 +43,7 @@ file_entry * file_entry_free(file_entry 
 	return NULL;
 }
 
-Buff * getline(Buff *buff, FILE *file){
+Buff * get_line(Buff *buff, FILE *file){
 	char c = fgetc(file);
 	buff = buff_free(buff);
 	while(TRUE){
