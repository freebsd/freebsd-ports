--- sm/mod_iq_time.c.orig	2016-02-09 09:47:02 UTC
+++ sm/mod_iq_time.c
@@ -77,7 +77,7 @@ static mod_ret_t _iq_time_pkt_sm(mod_ins
 
     datetime_out(t, dt_DATETIME, buf, 64);
     nad_insert_elem(pkt->nad, 2, NAD_ENS(pkt->nad, 1), "utc", buf);
-#ifdef HAVE_TZSET
+#ifdef HAVE_TZNAME
     snprintf(buf, 64, "%+03d:%02d", -((int)timezone)/(60*60), -((int)timezone)%(60*60));
 #else
     snprintf(buf, 64, "%+03d:%02d", (int) tm->tm_gmtoff/(60*60), (int) tm->tm_gmtoff%(60*60));
