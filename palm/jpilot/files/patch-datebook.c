Index: datebook.c
diff -u datebook.c:1.1.1.1 datebook.c:1.1.1.1.4.5
--- datebook.c:1.1.1.1	Sun Feb  4 12:58:54 2001
+++ datebook.c	Sat Feb 17 21:51:55 2001
@@ -37,10 +37,6 @@
 #include "libplugin.h"
 #include "password.h"
 
-#include "japanese.h"
-#include "cp1250.h"
-#include "russian.h"
-
 #ifndef FALSE
 #define FALSE 0
 #endif
@@ -205,6 +201,13 @@
    char record[65536];
    int rec_len;
    buf_rec br;
+   long char_set;
+
+   get_pref(PREF_CHAR_SET, &char_set, NULL);
+   if (char_set != CHAR_SET_ENGLISH) {
+       if (a->description) charset_j2p(a->description, strlen(a->description)+1, char_set);
+       if (a->note) charset_j2p(a->note, strlen(a->note)+1, char_set);
+   }
 
    rec_len = pack_Appointment(a, record, 65535);
    if (!rec_len) {
@@ -212,7 +215,7 @@
       jpilot_logf(LOG_WARN, "pack_Appointment %s\n", _("error"));
       return -1;
    }
-   br.rt=rt;
+      br.rt=rt;
    br.attrib = attrib;
    br.buf = record;
    br.size = rec_len;
@@ -535,9 +538,10 @@
 
 int get_datebook_app_info(struct AppointmentAppInfo *ai)
 {
-   int num;
+   int num,i;
    unsigned int rec_size;
    unsigned char *buf;
+   long char_set;
 
    bzero(ai, sizeof(*ai));
 
@@ -550,6 +554,12 @@
       jpilot_logf(LOG_WARN, _("Error reading"), "DatebookDB.pdb");
       return -1;
    }
+   get_pref(PREF_CHAR_SET, &char_set, NULL);
+   if (char_set != CHAR_SET_ENGLISH) {
+      for (i = 0; i < 16; i++) {
+	  if (ai->category.name[i][0] != '\0') charset_p2j(ai->category.name[i], 16, char_set);
+      }
+   }
 	 
    return 0;
 }
@@ -688,14 +698,14 @@
    AppointmentList *temp_a_list;
    long keep_modified, keep_deleted;
    int keep_priv;
-   long char_set;
    buf_rec *br;
 #ifdef USE_DB3
    long use_db3_tags;
    time_t ltime;
    struct tm *today;
 #endif
-   
+   long char_set;
+
 #ifdef USE_DB3
    time(&ltime);
    today = localtime(&ltime);
@@ -763,22 +773,8 @@
       }
 
       get_pref(PREF_CHAR_SET, &char_set, NULL);
-      if (char_set==CHAR_SET_JAPANESE) {
-	 Sjis2Euc(a.description, 65536);
-	 Sjis2Euc(a.note, 65536);
-      }
-      if (char_set==CHAR_SET_1250) {
-	 Win2Lat(a.description, 65536);
-	 Win2Lat(a.note, 65536);
-      }
-      if (char_set==CHAR_SET_1251) {
-	 win1251_to_koi8(a.description, 65536);
-	 win1251_to_koi8(a.note, 65536);
-      }
-      if (char_set==CHAR_SET_1251_B) {
-	 koi8_to_win1251(a.description, 65536);
-	 koi8_to_win1251(a.note, 65536);
-      }
+      if (a.description) charset_p2j(a.description, strlen(a.description)+1, char_set);
+      if (a.note) charset_p2j(a.note, strlen(a.note)+1, char_set);
 
       temp_a_list = malloc(sizeof(AppointmentList));
       if (!temp_a_list) {
@@ -793,6 +789,8 @@
       temp_a_list->next = *appointment_list;
       *appointment_list = temp_a_list;
       recs_returned++;
+
+
    }
 
    jp_free_DB_records(&records);
@@ -803,3 +801,5 @@
 
    return recs_returned;
 }
+
+
