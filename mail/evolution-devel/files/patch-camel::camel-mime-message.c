
$FreeBSD$

--- camel/camel-mime-message.c	2001/12/07 18:58:45	1.1
+++ camel/camel-mime-message.c	2001/12/07 18:59:18
@@ -206,7 +206,7 @@
 #if defined(HAVE_TIMEZONE)
 		tz = timezone;
 #elif defined(HAVE_TM_GMTOFF)
-		tz = local->tm_gmtoff;
+		tz = -local->tm_gmtoff;
 #endif
 		offset = -(((tz/60/60) * 100) + (tz/60 % 60));
 		if (local->tm_isdst>0)
