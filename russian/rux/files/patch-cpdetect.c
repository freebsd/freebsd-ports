--- cpdetect.c.orig	Sat Dec 24 18:32:27 2005
+++ cpdetect.c	Sun Jan  1 15:57:17 2006
@@ -64,6 +64,8 @@
 	struct cpinfo *in_cp = def_cp;
 
 	for (cur_cp = cp; cur_cp->cp_name; cur_cp++) {
+		u_char *p;
+		float cur_exp = .0;     /* an expectancy of current code page */
 		memset(tab, 255, sizeof(tab));
 		memset(freq, 0, sizeof(freq));
 
@@ -71,13 +73,11 @@
 			tab[cur_cp->cp_data[i]] = i;
 		}
 
-		u_char *p = buf + len - 1;
+		p = buf + len - 1;
 
 		while ((p - buf) >= 0) {
 			++freq[tab[*p--]];	/* freq[0xff] is a heap :) */
 		}
-
-		float cur_exp = .0;	/* an expectancy of current code page */
 
 		for (i = 0; i < cp_size; i++) {
 			float freq_factor = freq[i] / (float)len;
