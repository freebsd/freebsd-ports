--- utils/net_time.c.orig	Fri Feb 25 18:59:42 2005
+++ utils/net_time.c	Sun Mar 20 01:41:20 2005
@@ -76,9 +76,16 @@
 
 	tm = localtime(&t);
 	
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
 
