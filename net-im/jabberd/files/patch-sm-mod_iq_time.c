--- sm/mod_iq_time.c.orig	2007-09-25 22:34:24.000000000 +0200
+++ sm/mod_iq_time.c	2007-10-04 09:20:14.000000000 +0200
@@ -77,7 +77,7 @@
 
     datetime_out(t, dt_DATETIME, buf, 64);
     nad_insert_elem(pkt->nad, 2, NAD_ENS(pkt->nad, 1), "utc", buf);
-#ifdef HAVE_TZSET
+#ifdef HAVE_TZNAME
     snprintf(buf, 64, "%+03d:%02d", (int) -timezone/(60*60), (int) -timezone%(60*60));
 #else
     snprintf(buf, 64, "%+03d:%02d", (int) tm->tm_gmtoff/(60*60), (int) tm->tm_gmtoff%(60*60));
