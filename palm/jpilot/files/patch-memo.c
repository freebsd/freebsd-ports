Index: memo.c
diff -u memo.c:1.1.1.1 memo.c:1.1.1.1.4.4
--- memo.c:1.1.1.1	Sun Feb  4 12:58:54 2001
+++ memo.c	Sat Feb 17 21:47:54 2001
@@ -32,10 +32,6 @@
 #include "libplugin.h"
 #include "password.h"
 
-#include "japanese.h"
-#include "cp1250.h"
-#include "russian.h"
-
 #define MEMO_EOF 7
 
 int memo_compare(const void *v1, const void *v2)
@@ -133,6 +129,12 @@
    char record[65536];
    int rec_len;
    buf_rec br;
+   long char_set;
+
+   get_pref(PREF_CHAR_SET, &char_set, NULL);
+   if (char_set != CHAR_SET_ENGLISH) {
+      if (memo->text) charset_j2p(memo->text, strlen(memo->text)+1, char_set);
+   }
 
    rec_len = pack_Memo(memo, record, 65535);
    if (!rec_len) {
@@ -165,7 +167,7 @@
 
 int get_memo_app_info(struct MemoAppInfo *ai)
 {
-   int num;
+   int num,i;
    unsigned int rec_size;
    unsigned char *buf;
    long char_set;
@@ -183,18 +185,12 @@
    }
 	 
    get_pref(PREF_CHAR_SET, &char_set, NULL);
-   if (char_set==CHAR_SET_JAPANESE ||
-       char_set==CHAR_SET_1250 ||
-       char_set==CHAR_SET_1251 ||
-       char_set==CHAR_SET_1251_B) {
-      int i;
-      for (i = 0; i < 16; i++)
-	if (ai->category.name[i][0] != '\0') {
-   	  if (char_set==CHAR_SET_JAPANESE) Sjis2Euc(ai->category.name[i], 16);
-	  if (char_set==CHAR_SET_1250) Win2Lat(ai->category.name[i], 16);
-	  if (char_set==CHAR_SET_1251) win1251_to_koi8(ai->category.name[i], 16);
-	  if (char_set==CHAR_SET_1251_B) koi8_to_win1251(ai->category.name[i], 16);
-	}
+   if (char_set != CHAR_SET_ENGLISH) {
+      for (i = 0; i < 16; i++) {
+	 if (ai->category.name[i][0] != '\0') {
+	    charset_p2j(ai->category.name[i], 16, char_set);
+	 }
+      }
    }
 
    return 0;
@@ -218,8 +214,8 @@
    MemoList *temp_memo_list;
    long keep_modified, keep_deleted;
    int keep_priv;
-   long char_set;
    buf_rec *br;
+   long char_set;
   
    jpilot_logf(LOG_DEBUG, "get_memos2()\n");
    if (modified==2) {
@@ -274,12 +270,8 @@
       if ( ((br->attrib & 0x0F) != category) && category != CATEGORY_ALL) {
 	 continue;
       }
-
       get_pref(PREF_CHAR_SET, &char_set, NULL);
-      if (char_set==CHAR_SET_JAPANESE) Sjis2Euc(memo.text, 65536);
-      if (char_set==CHAR_SET_1250) Win2Lat(memo.text, 65536);
-      if (char_set==CHAR_SET_1251) win1251_to_koi8(memo.text, 65536);
-      if (char_set==CHAR_SET_1251_B) koi8_to_win1251(memo.text, 65536);
+      if (memo.text) charset_p2j(memo.text, strlen(memo.text)+1, char_set);
 
       temp_memo_list = malloc(sizeof(MemoList));
       if (!temp_memo_list) {
