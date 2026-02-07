--- util/dvbdate/dvbdate.c.orig	2014-03-21 19:26:36 UTC
+++ util/dvbdate/dvbdate.c
@@ -309,8 +309,8 @@ int atsc_scan_date(time_t *rx_time, unsi
  */
 int set_time(time_t * new_time)
 {
-	if (stime(new_time)) {
-		perror("Unable to set time");
+	if (1) {
+		perror("Unable to set time. stime(2) not supported on FreeBSD");
 		return -1;
 	}
 	return 0;
