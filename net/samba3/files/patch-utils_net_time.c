--- ./utils/net_time.c.orig	Thu Mar  1 05:54:59 2007
+++ ./utils/net_time.c	Tue Apr 17 02:06:59 2007
@@ -83,9 +83,16 @@
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
 
