--- ./utils/net_time.c.orig	2008-12-19 13:57:33.000000000 +0000
+++ ./utils/net_time.c	2009-01-06 17:10:53.000000000 +0000
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
 
