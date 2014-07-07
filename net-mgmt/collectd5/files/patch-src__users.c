--- ./src/users.c.orig	2014-06-02 22:12:33.650261000 -0700
+++ ./src/users.c	2014-06-11 00:10:39.000000000 -0700
@@ -101,12 +101,13 @@
 
 #elif HAVE_LIBSTATGRAB
 	sg_user_stats *us;
+	size_t num_entries;
 
-	us = sg_get_user_stats ();
+	us = sg_get_user_stats (&num_entries);
 	if (us == NULL)
 		return (-1);   
 
-	users_submit ((gauge_t) us->num_entries);
+	users_submit ((gauge_t) num_entries);
 /* #endif HAVE_LIBSTATGRAB */
 
 #else
