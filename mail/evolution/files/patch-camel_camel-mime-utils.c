--- camel/camel-mime-utils.c.orig	Fri May  3 15:47:41 2002
+++ camel/camel-mime-utils.c	Sun May  5 18:09:24 2002
@@ -3388,6 +3388,8 @@
 		}
 		d(printf("named offset = %d\n", offset));
 	}
+
+	tm.tm_isdst = -1;
 
 	t = mktime(&tm);
 #if defined(HAVE_TIMEZONE)
