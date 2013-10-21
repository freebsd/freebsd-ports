--- ./src/compat/setproctitle.c.orig	2011-12-20 05:11:03.000000000 -0800
+++ ./src/compat/setproctitle.c	2013-10-20 23:21:24.000000000 -0700
@@ -144,7 +144,7 @@
 			vsnprintf(buf + len, sizeof(buf) - len , fmt, ap);
 	}
 	va_end(ap);
-	strnvis(ptitle, buf, sizeof(ptitle),
+	strnvis(ptitle, sizeof(ptitle), buf,
 	    VIS_CSTYLE|VIS_NL|VIS_TAB|VIS_OCTAL);
 
 #if SPT_TYPE == SPT_PSTAT
