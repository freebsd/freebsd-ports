--- src/pmacct.c.orig	2022-12-31 19:17:17 UTC
+++ src/pmacct.c
@@ -2964,7 +2964,7 @@ int main(int argc,char **argv)
 	/* print packets */
 	else if (which_counter == 1) printf("%" PRIu64 "\n", acc_elem->pkt_num); 
 	/* print packets+bytes+flows+num */
-	else if (which_counter == 2) printf("%" PRIu64 " %" PRIu64 " %" PRIu64 " %lu\n", acc_elem->pkt_num, acc_elem->pkt_len, acc_elem->flo_num, acc_elem->time_start.tv_sec);
+	else if (which_counter == 2) printf("%" PRIu64 " %" PRIu64 " %" PRIu64 " %jd\n", acc_elem->pkt_num, acc_elem->pkt_len, acc_elem->flo_num, (intmax_t)acc_elem->time_start.tv_sec);
 	/* print flows */
 	else if (which_counter == 3) printf("%" PRIu64 "\n", acc_elem->flo_num);
       }
@@ -3814,8 +3814,8 @@ void pmc_compose_timestamp(char *buf, int buflen, stru
   struct tm *time2;
 
   if (tstamp_since_epoch) {
-    if (usec) snprintf(buf, buflen, "%ld.%.6ld", tv->tv_sec, (long)tv->tv_usec);
-    else snprintf(buf, buflen, "%ld", tv->tv_sec);
+    if (usec) snprintf(buf, buflen, "%ld.%.6ld", (long)tv->tv_sec, (long)tv->tv_usec);
+    else snprintf(buf, buflen, "%ld", (long)tv->tv_sec);
   }
   else {
     time1 = tv->tv_sec;
