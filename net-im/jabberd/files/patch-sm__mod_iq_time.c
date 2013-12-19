--- ./sm/mod_iq_time.c.orig	2013-10-07 16:27:54.000000000 +0100
+++ ./sm/mod_iq_time.c	2013-12-15 10:29:42.308777764 +0000
@@ -77,7 +77,7 @@
 
     datetime_out(t, dt_DATETIME, buf, 64);
     nad_insert_elem(pkt->nad, 2, NAD_ENS(pkt->nad, 1), "utc", buf);
-#ifdef HAVE_TZSET
+#ifdef HAVE_TZNAME
     snprintf(buf, 64, "%+03d:%02d", -((int)timezone)/(60*60), -((int)timezone)%(60*60));
 #else
     snprintf(buf, 64, "%+03d:%02d", (int) tm->tm_gmtoff/(60*60), (int) tm->tm_gmtoff%(60*60));
