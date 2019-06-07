--- ntpd/refclock_mx4200.c.orig	2019-06-06 17:17:04.000000000 -0700
+++ ntpd/refclock_mx4200.c	2019-06-07 04:44:07.786152000 -0700
@@ -1572,7 +1572,7 @@
 		 * Print debug message to stdout
 		 * In the future, we may want to get get more creative...
 		 */
-		mvprintf(fmt, ap);
+		vprintf(fmt, ap);
 
 		va_end(ap);
 	}
@@ -1614,14 +1614,14 @@
 #else
 	va_start(ap);
 #endif /* __STDC__ */
-	n = VSNPRINTF((cp, (size_t)(ep - cp), fmt, ap));
+	n = vsnprintf((cp, (size_t)(ep - cp), fmt, ap));
 	va_end(ap);
 	if (n < 0 || (size_t)n >= (size_t)(ep - cp))
 		goto overflow;
 
 	ck = mx4200_cksum(cp, n);
 	cp += n;	    
-	n = SNPRINTF((cp, (size_t)(ep - cp), "*%02X\r\n", ck));
+	n = snprintf((cp, (size_t)(ep - cp), "*%02X\r\n", ck));
 	if (n < 0 || (size_t)n >= (size_t)(ep - cp))
 		goto overflow;
 	cp += n;
