--- dvdbackup/dvdbackup_lxdvdrip.c.orig	Sat Dec 16 13:51:34 2006
+++ dvdbackup/dvdbackup_lxdvdrip.c	Sat Dec 16 13:51:54 2006
@@ -2382,9 +2382,9 @@
 
 	/* Switches */
 	int title_set = 0;
-	int titles;
-	int start_chapter;
-	int end_chapter;
+	int titles = 0;
+	int start_chapter = 0;
+	int end_chapter = 0;
 
 	int do_mirror = 0;
 	int do_title_set = 0;
