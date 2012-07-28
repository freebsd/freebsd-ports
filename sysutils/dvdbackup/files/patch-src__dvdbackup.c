--- ./src/dvdbackup.c.orig	2012-06-24 03:10:29.000000000 +0200
+++ ./src/dvdbackup.c	2012-07-28 13:57:54.000000000 +0200
@@ -1546,7 +1546,6 @@
 
 	title_set_info = DVDGetFileSet(_dvd);
 	if (!title_set_info) {
-		DVDClose(_dvd);
 		return(1);
 	}
 
@@ -1573,7 +1572,6 @@
 	title_set_info = DVDGetFileSet(_dvd);
 
 	if (!title_set_info) {
-		DVDClose(_dvd);
 		return(1);
 	}
 
