--- utils/net_time.c.orig	Fri Jun 23 15:16:53 2006
+++ utils/net_time.c	Thu Aug 24 01:30:57 2006
@@ -79,9 +79,16 @@
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
+#endif /* defined(FREEBSD) */
+	
 	return s;
 }
 
