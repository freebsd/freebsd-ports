Index: utils.h
diff -u utils.h:1.1.1.1 utils.h:1.1.1.1.4.3
--- utils.h:1.1.1.1	Sun Feb  4 12:58:55 2001
+++ utils.h	Sat Feb 17 21:56:24 2001
@@ -303,3 +303,18 @@
 
 void multibyte_safe_strncpy(char *dst, char *src, size_t max_len);
 char *multibyte_safe_memccpy(char *dst, const char *src, int c, size_t len);
+
+/*************************************
+ * convert char code 
+ *************************************/
+#define charset_j2p(buf, max_len, char_set)  {\
+	if (char_set == CHAR_SET_JAPANESE)   Euc2Sjis(buf, max_len);\
+	if (char_set == CHAR_SET_1250) Lat2Win(buf,max_len);\
+	if (char_set == CHAR_SET_1251) koi8_to_win1251(buf, max_len);\
+	if (char_set == CHAR_SET_1251_B) win1251_to_koi8(buf, max_len);}
+#define charset_p2j(buf, max_len, char_set) {\
+        if (char_set == CHAR_SET_JAPANESE) Sjis2Euc(buf, max_len);\
+        if (char_set == CHAR_SET_1250) Win2Lat(buf,max_len);\
+        if (char_set == CHAR_SET_1251) win1251_to_koi8(buf, max_len);\
+        if (char_set == CHAR_SET_1251_B) koi8_to_win1251(buf, max_len);}
+
