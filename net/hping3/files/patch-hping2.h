--- hping2.h.orig	2004-06-04 15:22:38.000000000 +0800
+++ hping2.h	2020-08-20 15:19:32.827593000 +0700
@@ -353,7 +353,7 @@ struct delaytable_element {
 	int status;
 };
 
-volatile struct delaytable_element delaytable[TABLESIZE];
+extern volatile struct delaytable_element delaytable[TABLESIZE];
 
 /* protos */
 void	nop(void);				/* nop */
