--- ./utils/net_time.c.orig	2008-09-18 06:49:02.000000000 +0000
+++ ./utils/net_time.c	2008-10-10 00:42:10.000000000 +0000
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
 
