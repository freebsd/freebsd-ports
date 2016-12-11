From f5dbe2c9a5fe050c1d7e014d3c1529befb8eea3b Mon Sep 17 00:00:00 2001
From: ivan-83 <rozhuk.im@gmail.com>
Date: Tue, 10 Mar 2015 04:40:47 +0300
Subject: [PATCH] * FreeBSD timezone detection patch

--- libfreerdp/locale/timezone.c.orig	2014-09-11 22:46:32 UTC
+++ libfreerdp/locale/timezone.c
@@ -1507,8 +1507,11 @@ char* freerdp_get_unix_timezone_identifi
 		return tzid;
 	}
 
+#ifdef __FreeBSD__
+	fp = fopen("/var/db/zoneinfo", "r");
+#else
 	fp = fopen("/etc/timezone", "r");
-
+#endif
 	if (fp != NULL)
 	{
 		fseek(fp, 0, SEEK_END);
@@ -1664,8 +1667,10 @@ void freerdp_time_zone_detect(TIME_ZONE_
 
 #ifdef HAVE_TM_GMTOFF
 	#if defined(__FreeBSD__)
-		/*not the best solution, but could not get the right tyepcast*/
-		clientTimeZone->bias = 0;
+		if (local_time->tm_gmtoff >= 0)
+			clientTimeZone->bias = (UINT32) (local_time->tm_gmtoff / 60);
+		else
+			clientTimeZone->bias = (UINT32) (1440 + (INT32) (local_time->tm_gmtoff / 60));
 	#else
 		clientTimeZone->bias = timezone / 60;
 	#endif
