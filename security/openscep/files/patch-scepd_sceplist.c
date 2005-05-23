--- scepd/sceplist.c.orig	Thu May 19 16:59:02 2005
+++ scepd/sceplist.c	Thu May 19 17:02:22 2005
@@ -96,7 +96,6 @@
 /*
  * convert ASN1 time string to a struct tm
  */
-extern time_t	timezone; /* compiler does not like it inside func */
 #ifdef HAVE_ALTZONE
 extern time_t	altzone;
 #endif /* HAVE_ALTZONE */
@@ -124,19 +123,15 @@
 	rtm.tm_year = atoi(work);
 	if (rtm.tm_year < 70)
 		rtm.tm_year += 100;
+	rtm.tm_zone = 0;
 
-	/* set the time zone to GMT, as mktime uses the local time zone	*/
-	timezone = 0;
 #ifdef HAVE_ALTZONE
 	altzone = 0;
 #endif /* HAVE_ALTZONE */
 
 	/* use mktime to normalize the structure and t convert to a	*/
 	/* time_t value							*/
-	rt = mktime(&rtm);
-
-	/* reset the time zone to local settings			*/
-	tzset();
+	rt = timegm(&rtm);
 
 	return rt;
 }
