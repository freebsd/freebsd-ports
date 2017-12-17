--- source3/utils/net_time.c.orig	2017-01-11 07:55:15 UTC
+++ source3/utils/net_time.c
@@ -75,10 +75,15 @@ static const char *systime(time_t t)
 	if (!tm) {
 		return "unknown";
 	}
-
+#if defined(FREEBSD)
+	return talloc_asprintf(talloc_tos(), "%02d%02d%02d%02d%02d.%02d",
+				tm->tm_year + 1900, tm->tm_mon+1, tm->tm_mday,
+				tm->tm_hour, tm->tm_min, tm->tm_sec);
+#else
 	return talloc_asprintf(talloc_tos(), "%02d%02d%02d%02d%04d.%02d",
 			       tm->tm_mon+1, tm->tm_mday, tm->tm_hour,
 			       tm->tm_min, tm->tm_year + 1900, tm->tm_sec);
+#endif
 }
 
 int net_time_usage(struct net_context *c, int argc, const char **argv)
