--- ntpd/refclock_ripencc.c.orig	2014-12-18 18:42:01.000000000 -0800
+++ ntpd/refclock_ripencc.c	2017-11-23 19:41:57.473988000 -0800
@@ -1517,7 +1517,7 @@
 
 	record_clock_stats(&peer->srcadr, logbuf);
 
-	if (!utcflags & UTCF_UTC_AVAIL)
+	if (!(utcflags & UTCF_UTC_AVAIL))
 		return(-1);
 
 	/* poll for UTC parameters once and then if UTC flag changed */
@@ -3442,7 +3442,7 @@
 	    status1, status2;
 	const char
 	    *text;
-	static const char const
+	static const char
 	    *sc_text[] = {
 		"Doing position fixes",
 		"Don't have GPS time yet",
@@ -4442,8 +4442,6 @@
 		known = TRUE;
 	}
 	if (known == FALSE) pbuf += sprintf(pbuf, "No known");
-	reserved = reserved;
-
 }
 
 /* 0x8F */
@@ -5059,7 +5057,7 @@
 	{
 		for (i=0; i<8; i++)
 		{
-			if (Flags&(1<<i)) pbuf += sprintf(pbuf, LeapStatusText[i]);
+			if (Flags&(1<<i)) pbuf += sprintf(pbuf, " %s", LeapStatusText[i]);
 		}
 	}
 	else
