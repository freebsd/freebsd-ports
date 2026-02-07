--- ./ldapvi.c.orig	2012-07-09 23:43:28.000000000 +0200
+++ ./ldapvi.c	2012-07-09 23:43:50.000000000 +0200
@@ -1465,7 +1465,7 @@
 	int line = 0;
 	int c;
 
-	if (lstat(sasl, &st) == -1) return;
+	if (lstat(sasl, &st) == -1) return 0;
 	if ( !(in = fopen(sasl, "r"))) syserr();
 
 	if (st.st_size > 0) {
