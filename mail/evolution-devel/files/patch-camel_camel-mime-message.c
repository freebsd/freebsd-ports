--- camel/camel-mime-message.c.orig	Mon Dec 10 14:54:11 2001
+++ camel/camel-mime-message.c	Fri Apr 26 17:19:59 2002
@@ -209,8 +209,10 @@
 		tz = -local->tm_gmtoff;
 #endif
 		offset = -(((tz/60/60) * 100) + (tz/60 % 60));
+#if defined(HAVE_TIMEZONE)
 		if (local->tm_isdst>0)
 			offset += 100;
+#endif
 	}
 	message->date = date;
 	message->date_offset = offset;
