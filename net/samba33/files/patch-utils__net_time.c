--- ./utils/net_time.c.orig	2009-04-01 11:48:54.000000000 +0000
+++ ./utils/net_time.c	2009-04-07 01:39:14.000000000 +0000
@@ -84,9 +84,15 @@
 		return "unknown";
 	}
 
+#if defined(FREEBSD)
+	fstr_sprintf(s, "%02d%02d%02d%02d%02d.%02d",
+		 tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,
+		 tm->tm_hour,tm->tm_min,tm->tm_sec);
+#else
 	fstr_sprintf(s, "%02d%02d%02d%02d%04d.%02d",
 		 tm->tm_mon+1, tm->tm_mday, tm->tm_hour,
 		 tm->tm_min, tm->tm_year + 1900, tm->tm_sec);
+#endif /* !FREEBSD */
 	return s;
 }
 
