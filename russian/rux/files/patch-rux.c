--- rux.c.orig	2009-05-21 20:46:40.000000000 +0400
+++ rux.c	2009-05-22 01:11:14.000000000 +0400
@@ -436,9 +436,16 @@
 
 #ifndef DEBUG
 	if (strcmp(i_cp->cp_name, "utf-8") == 0) {
+		char hook[4];
+	       	hook[0] = o_cp->cp_data[6];
+		hook[1] = o_cp->cp_data[34];
+		hook[2] = o_cp->cp_data[18];
+		hook[3] = o_cp->cp_data[39];
+
 		while ((c = getc(in)) != EOF) {
 			if (c == (u_char)0xd0 || c == (u_char)0xd1) {
-				;
+				conv_tab[0x91] = c == 0xd1 ? hook[0] : hook[1];
+				conv_tab[0x81] = c == 0xd1 ? hook[2] : hook[3];
 			} else {
 				putc(conv_tab[(u_char) c], out);
 			}
@@ -484,8 +491,16 @@
 recode_buf(u_char *conv_tab, u_char *buf, int len, FILE *out)
 {
 	if (strcmp(i_cp->cp_name, "utf-8") == 0) {
+		char hook[4];
+	       	hook[0] = o_cp->cp_data[6];
+		hook[1] = o_cp->cp_data[34];
+		hook[2] = o_cp->cp_data[18];
+		hook[3] = o_cp->cp_data[39];
+
 		while (len--) {
 			if (*buf == (u_char)0xd0 || *buf == (u_char)0xd1) {
+				conv_tab[0x91] = *buf == 0xd1 ? hook[0] : hook[1];
+				conv_tab[0x81] = *buf == 0xd1 ? hook[2] : hook[3];
 				++buf;
 			} else {
 				putc(conv_tab[*buf++], out);
