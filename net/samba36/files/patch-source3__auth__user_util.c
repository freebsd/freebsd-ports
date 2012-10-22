--- ./source3/auth/user_util.c.orig	2012-09-14 08:12:09.000000000 +0000
+++ ./source3/auth/user_util.c	2012-10-18 20:58:57.065810414 +0000
@@ -425,12 +425,14 @@
 	x_fclose(f);
 
 	/*
-	 * Setup the last_from and last_to as an optimization so
-	 * that we don't scan the file again for the same user.
+	 * If mapping failed setup the last_from and last_to as
+	 * an optimization so that we don't scan the file again
+	 * for the same user.
 	 */
-
-	set_last_from_to(user_in, user_in);
-	store_map_in_gencache(ctx, user_in, user_in);
+	if(!mapped_user) {
+		set_last_from_to(user_in, user_in);
+		store_map_in_gencache(ctx, user_in, user_in);
+	}
 
 	return mapped_user;
 }
