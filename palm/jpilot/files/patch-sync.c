Index: sync.c
diff -u sync.c:1.1.1.1 sync.c:1.1.1.1.4.1
--- sync.c:1.1.1.1	Sun Feb  4 12:58:55 2001
+++ sync.c	Sat Feb 17 17:07:51 2001
@@ -105,10 +105,6 @@
 
 int pdb_file_delete_record_by_id(char *DB_name, pi_uid_t uid_in);
 
-
-void recode_packed_record(char *DB_name, void *record, int rec_len, long char_seet);
-
-
 void sig_handler(int sig)
 {
    jpilot_logf(LOG_DEBUG, "caught signal SIGCHLD\n");
@@ -624,10 +620,8 @@
       return 0;
    }
    get_pref(PREF_CHAR_SET, &char_set, NULL);
-   if (char_set == CHAR_SET_JAPANESE) Euc2Sjis(buf, 1023);
-   if (char_set == CHAR_SET_1250) Lat2Win(buf, 1023);
-   if (char_set == CHAR_SET_1251) koi8_to_win1251(buf, 1023);
-   if (char_set == CHAR_SET_1251_B) win1251_to_koi8(buf, 1023);
+   charset_j2p(buf,1023,char_set);
+
    dlp_AddSyncLogEntry(sd, buf);
    dlp_AddSyncLogEntry(sd, "\n\r");
 
@@ -751,15 +745,6 @@
 	    }
 	 }
 
-	 get_pref(PREF_CHAR_SET, &char_set, NULL);
-	 if (char_set==CHAR_SET_JAPANESE ||
-	     char_set==CHAR_SET_1250 ||
-	     char_set==CHAR_SET_1251 ||
-	     char_set==CHAR_SET_1251_B
-	     ) {
-	    recode_packed_record(DB_name, record, rec_len, char_set);
-	 }
-
 	 ret = dlp_WriteRecord(sd, db, header.attrib & dlpRecAttrSecret,
 			       0, header.attrib & 0x0F,
 			       record, rec_len, &new_id);
@@ -1469,61 +1454,6 @@
    return 0;
 }
 
-void recode_packed_record(char *DB_name, void *record, int rec_len, long char_set)
-{
-   /*todo move this to before the record is written out?*/
-   /* Convert to SJIS Japanese Kanji code (Palm use this code) */
-   /* or convert to different encoding */
-   /*Write the record to the Palm Pilot */
-   if (!strcmp(DB_name, "DatebookDB")) {
-      struct Appointment a;
-      unpack_Appointment(&a, record, rec_len);
-      if (char_set == CHAR_SET_JAPANESE) Euc2Sjis(a.description, 65536);
-      if (char_set == CHAR_SET_1250) Lat2Win(a.description, 65536);
-      if (char_set == CHAR_SET_1251) koi8_to_win1251(a.description, 65536);
-      if (char_set == CHAR_SET_1251_B) win1251_to_koi8(a.description, 65536);
-      if (char_set == CHAR_SET_JAPANESE) Euc2Sjis(a.note, 65536);
-      if (char_set == CHAR_SET_1250) Lat2Win(a.note, 65536);
-      if (char_set == CHAR_SET_1251) koi8_to_win1251(a.note, 65536);
-      if (char_set == CHAR_SET_1251_B) win1251_to_koi8(a.note, 65536);
-      rec_len = pack_Appointment(&a, record, 65535);
-   }
-   if (!strcmp(DB_name, "AddressDB")) {
-      struct Address a;
-      int i;
-      unpack_Address(&a, record, rec_len);
-      for (i = 0; i < 19; i++) {
-	 if (char_set == CHAR_SET_JAPANESE) Euc2Sjis(a.entry[i], 65536);
-	 if (char_set == CHAR_SET_1250) Lat2Win(a.entry[i], 65536);
-	 if (char_set == CHAR_SET_1251) koi8_to_win1251(a.entry[i], 65536);
-	 if (char_set == CHAR_SET_1251_B) win1251_to_koi8(a.entry[i], 65536);
-      }
-      rec_len = pack_Address(&a, record, 65535);
-   }
-   if (!strcmp(DB_name, "ToDoDB")) {
-      struct ToDo t;
-      unpack_ToDo(&t, record, rec_len);
-      if (char_set == CHAR_SET_JAPANESE) Euc2Sjis(t.description, 65536);
-      if (char_set == CHAR_SET_1250) Lat2Win(t.description, 65536);
-      if (char_set == CHAR_SET_1251) koi8_to_win1251(t.description, 65536);
-      if (char_set == CHAR_SET_1251_B) win1251_to_koi8(t.description, 65536);
-      if (char_set == CHAR_SET_JAPANESE) Euc2Sjis(t.note, 65536);
-      if (char_set == CHAR_SET_1250) Lat2Win(t.note, 65536);
-      if (char_set == CHAR_SET_1251) koi8_to_win1251(t.note, 65536);
-      if (char_set == CHAR_SET_1251_B) win1251_to_koi8(t.note, 65536);
-      rec_len = pack_ToDo(&t, record, 65535);
-   }
-   if (!strcmp(DB_name, "MemoDB")) {
-      struct Memo m;
-      unpack_Memo(&m, record, rec_len);
-      if (char_set == CHAR_SET_JAPANESE) Euc2Sjis(m.text, 65536);
-      if (char_set == CHAR_SET_1250) Lat2Win(m.text, 65536);
-      if (char_set == CHAR_SET_1251) koi8_to_win1251(m.text, 65536);
-      if (char_set == CHAR_SET_1251_B) win1251_to_koi8(m.text, 65536);
-      rec_len = pack_Memo(&m, record, 65535);
-   }
-}
-
 int fast_sync_local_recs(char *DB_name, int sd, int db)
 {
    unsigned long new_id;
@@ -1541,7 +1471,6 @@
    char error_log_message_d[256];
    char delete_log_message[256];
    int index, size, attr, category;
-   long char_set;
 
    jpilot_logf(LOG_DEBUG, "fast_sync_local_recs\n");
 
@@ -1599,14 +1528,6 @@
 	    if (ferror(pc_in)) {
 	       break;
 	    }
-	 }
-	 get_pref(PREF_CHAR_SET, &char_set, NULL);
-	 if (char_set==CHAR_SET_JAPANESE ||
-	     char_set==CHAR_SET_1250 ||
-	     char_set==CHAR_SET_1251 ||
-	     char_set==CHAR_SET_1251_B
-	     ) {
-	    recode_packed_record(DB_name, record, rec_len, char_set);
 	 }
 
 	 jpilot_logf(LOG_DEBUG, "Writing PC record to palm\n");
Index: todo.c
diff -u todo.c:1.1.1.1 todo.c:1.1.1.1.4.3
--- todo.c:1.1.1.1	Sun Feb  4 12:58:55 2001
+++ todo.c	Sat Feb 17 20:37:52 2001
@@ -31,10 +31,6 @@
 #include "libplugin.h"
 #include "password.h"
 
-#include "japanese.h"
-#include "cp1250.h"
-#include "russian.h"
-
 #define TODO_EOF 7
 
 static struct ToDoAppInfo *glob_Ptodo_app_info;
@@ -241,6 +237,13 @@
    char record[65536];
    int rec_len;
    buf_rec br;
+   long char_set;
+
+   get_pref(PREF_CHAR_SET, &char_set, NULL);
+   if (char_set != CHAR_SET_ENGLISH) {
+      if (todo->description) charset_j2p(todo->description, strlen(todo->description)+1, char_set);
+      if (todo->note) charset_j2p(todo->note, strlen(todo->note)+1, char_set);
+   }
