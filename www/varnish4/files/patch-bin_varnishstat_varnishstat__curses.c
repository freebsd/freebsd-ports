--- bin/varnishstat/varnishstat_curses.c.orig	2016-01-28 10:30:41 UTC
+++ bin/varnishstat/varnishstat_curses.c
@@ -540,8 +540,9 @@ static void
 print_duration(WINDOW *w, time_t t)
 {
 
-	wprintw(w, "%4lu+%02lu:%02lu:%02lu",
-	    t / 86400, (t % 86400) / 3600, (t % 3600) / 60, t % 60);
+	wprintw(w, "%4jd+%02jd:%02jd:%02jd",
+	    (intmax_t)t / 86400, (intmax_t)(t % 86400) / 3600,
+	    (intmax_t)(t % 3600) / 60, (intmax_t)t % 60);
 }
 
 static void
