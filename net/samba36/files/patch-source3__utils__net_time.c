--- ./source3/utils/net_time.c.orig	2010-04-01 15:26:22.000000000 +0200
+++ ./source3/utils/net_time.c	2010-04-23 01:08:35.000000000 +0200
@@ -85,10 +85,15 @@
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
