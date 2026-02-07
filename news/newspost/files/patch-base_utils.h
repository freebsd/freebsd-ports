--- base/utils.h.orig	2003-02-08 15:09:41 UTC
+++ base/utils.h
@@ -26,7 +26,7 @@ file_entry;
 file_entry * file_entry_alloc();
 file_entry * file_entry_free(file_entry *fe);
 
-Buff * getline(Buff *buff, FILE *file);
+Buff * get_line(Buff *buff, FILE *file);
 Buff *buff_add(Buff *buff, char *data, ... );
 Buff * buff_free(Buff *buff);
 Buff *buff_create(Buff *buff, char *data, ... );
