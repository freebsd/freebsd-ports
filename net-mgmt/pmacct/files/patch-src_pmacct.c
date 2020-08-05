--- src/pmacct.c.orig	2020-05-10 13:57:54 UTC
+++ src/pmacct.c
@@ -2898,7 +2898,7 @@ int main(int argc,char **argv)
 	/* print packets */
 	else if (which_counter == 1) printf("%" PRIu64 "\n", acc_elem->pkt_num); 
 	/* print packets+bytes+flows+num */
-	else if (which_counter == 2) printf("%" PRIu64 " %" PRIu64 " %" PRIu64 " %lu\n", acc_elem->pkt_num, acc_elem->pkt_len, acc_elem->flo_num, acc_elem->time_start.tv_sec);
+	else if (which_counter == 2) printf("%" PRIu64 " %" PRIu64 " %" PRIu64 " %zu\n", acc_elem->pkt_num, acc_elem->pkt_len, acc_elem->flo_num, acc_elem->time_start.tv_sec);
 	/* print flows */
 	else if (which_counter == 3) printf("%" PRIu64 "\n", acc_elem->flo_num);
       }
@@ -3725,8 +3725,8 @@ void pmc_compose_timestamp(char *buf, int buflen, stru
   struct tm *time2;
 
   if (tstamp_since_epoch) {
-    if (usec) snprintf(buf, buflen, "%ld.%.6ld", tv->tv_sec, (long)tv->tv_usec);
-    else snprintf(buf, buflen, "%ld", tv->tv_sec);
+    if (usec) snprintf(buf, buflen, "%ld.%.6ld", (long)tv->tv_sec, (long)tv->tv_usec);
+    else snprintf(buf, buflen, "%ld", (long)tv->tv_sec);
   }
   else {
     time1 = tv->tv_sec;
