Index: address.c
diff -u address.c:1.1.1.1 address.c:1.1.1.1.4.3
--- address.c:1.1.1.1	Sun Feb  4 12:58:54 2001
+++ address.c	Sat Feb 17 20:37:52 2001
@@ -31,10 +31,6 @@
 #include "libplugin.h"
 #include "password.h"
 
-#include "japanese.h"
-#include "cp1250.h"
-#include "russian.h"
-
 #define ADDRESS_EOF 7
 
 static int glob_sort_by_company;
@@ -224,8 +220,16 @@
 		     unsigned int *unique_id)
 {
    char record[65536];
-   int rec_len;
+   int rec_len,i;
    buf_rec br;
+   long char_set;
+
+   get_pref(PREF_CHAR_SET, &char_set, NULL);
+   if (char_set != CHAR_SET_ENGLISH) {
+      for (i = 0; i < 19; i++) {
+	  if (a->entry[i]) charset_j2p(a->entry[i], strlen(a->entry[i])+1, char_set);
+      }
+   }
 
    rec_len = pack_Address(a, record, 65535);
    if (!rec_len) {
@@ -275,36 +279,22 @@
       return -1;
    }
 	 
-   get_pref(PREF_CHAR_SET, &char_set, NULL);
-   if (char_set==CHAR_SET_JAPANESE || 
-       char_set==CHAR_SET_1250 ||
-       char_set==CHAR_SET_1251 ||
-       char_set==CHAR_SET_1251_B
-       ) {
+   get_pref(PREF_CHAR_SET, &char_set, NULL); 
+   if (char_set != CHAR_SET_ENGLISH) {
       /* Convert to character set */
-	{
 	   int i;
 	   for (i = 0; i < 16; i++)
 	     if (ai->category.name[i][0] != '\0') {
-   		if (char_set==CHAR_SET_JAPANESE) Sjis2Euc(ai->category.name[i], 16);
-   		if (char_set==CHAR_SET_1250) Win2Lat(ai->category.name[i], 16);
-   		if (char_set==CHAR_SET_1251) win1251_to_koi8(ai->category.name[i], 16);
+		charset_p2j(ai->category.name[i], 16, char_set);
 	     }
 	   for (i = 0; i < 19 + 3; i++)
 	     if (ai->labels[i][0] != '\0') {
-   		if (char_set==CHAR_SET_JAPANESE) Sjis2Euc(ai->labels[i], 16);
-   		if (char_set==CHAR_SET_1250) Win2Lat(ai->labels[i], 16);
-   		if (char_set==CHAR_SET_1251) win1251_to_koi8(ai->labels[i], 16);
-   		if (char_set==CHAR_SET_1251_B) koi8_to_win1251(ai->labels[i], 16);
+		charset_p2j(ai->labels[i],16, char_set);
 	     }
 	   for (i = 0; i < 8; i++)
 	     if (ai->phoneLabels[i][0] != '\0') {
-   		if (char_set==CHAR_SET_JAPANESE) Sjis2Euc(ai->phoneLabels[i], 16);
-   		if (char_set==CHAR_SET_1250) Win2Lat(ai->phoneLabels[i], 16);
-   		if (char_set==CHAR_SET_1251) win1251_to_koi8(ai->phoneLabels[i], 16);
-   		if (char_set==CHAR_SET_1251_B) koi8_to_win1251(ai->phoneLabels[i], 16);
+		charset_p2j(ai->phoneLabels[i],16, char_set);
 	     }
-	}
    }
 
    return 0;
@@ -386,17 +376,11 @@
       }
 
       get_pref(PREF_CHAR_SET, &char_set, NULL);
-      if (char_set==CHAR_SET_JAPANESE || 
-	  char_set==CHAR_SET_1250 ||
-	  char_set==CHAR_SET_1251 ||
-	  char_set==CHAR_SET_1251_B
-	  ) {
-	 int i;
+      if (char_set != CHAR_SET_ENGLISH) {
 	 for (i = 0; i < 19; i++) {
-	    if (char_set==CHAR_SET_JAPANESE) Sjis2Euc(a.entry[i], 65536);
-	    if (char_set==CHAR_SET_1250) Win2Lat(a.entry[i], 65536);
-	    if (char_set==CHAR_SET_1251) win1251_to_koi8(a.entry[i], 65536);
-	    if (char_set==CHAR_SET_1251_B) koi8_to_win1251(a.entry[i], 65536);
+	     if ((a.entry[i] != NULL) && (a.entry[i][0] != '\0')) {
+		charset_p2j(a.entry[i], strlen(a.entry[i])+1, char_set);
+	     }
 	 }
       }
 
