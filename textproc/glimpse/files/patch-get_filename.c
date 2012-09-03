--- get_filename.c.orig	2012-09-03 00:16:47.000000000 +0000
+++ get_filename.c	2012-09-03 00:16:59.000000000 +0000
@@ -481,7 +481,7 @@
 	return 0;
 }
 
-get_filenames(index_vect, argc, argv, dummylen, dummypat, file_num)
+void get_filenames(index_vect, argc, argv, dummylen, dummypat, file_num)
 int  *index_vect;
 int argc; /* the arguments to agrep for -F */
 char *argv[];
