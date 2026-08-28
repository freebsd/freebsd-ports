--- ntpdate/ntpdate.c.orig	2020-06-23 09:17:30 UTC
+++ ntpdate/ntpdate.c
@@ -299,6 +299,8 @@ main(
 	char *argv[]
 	)
 {
+	msyslog(LOG_NOTICE,"ntpdate is deprecated and "
+	"scheduled for removal in ntp 4.4, use ntpd -q instead");
 	return ntpdatemain (argc, argv);
 }
 #endif /* NO_MAIN_ALLOWED */
