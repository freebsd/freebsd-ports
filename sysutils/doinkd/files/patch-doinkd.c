--- doinkd.c.orig	2006-05-30 00:17:44.000000000 -0700
+++ doinkd.c	2012-01-04 12:28:11.183448967 -0800
@@ -651,7 +651,7 @@
    int grpcnt = 0;
    int tgrpcnt = 0;
    
-   if (user->mgroup != 0) {
+   if (user != NULL && user->mgroup != 0) {
      for (i = 0; i < n_users; i++) {
 	   if ( (*pusers[i]).uid == user->uid)
           who = i;
