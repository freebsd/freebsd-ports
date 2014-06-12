--- Mix/Src/mix.c.orig	2014-06-01 23:05:54.000000000 +0200
+++ Mix/Src/mix.c	2014-06-01 23:06:14.000000000 +0200
@@ -430,7 +430,7 @@
 #ifdef WIN32
 	strnncpy(SENDMAIL     , "outfile");
 #else /* end of WIN32 */
-	strnncpy(SENDMAIL     , "/usr/lib/sendmail -t");
+	strnncpy(SENDMAIL     , "/usr/sbin/sendmail -t");
 #endif /* else if not WIN32 */
 	strnncpy(SENDANONMAIL , "");
 	strnncpy(NEWS         , "");
