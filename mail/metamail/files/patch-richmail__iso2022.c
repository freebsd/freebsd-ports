--- richmail/iso2022.c.orig	1992-12-23 02:50:21.000000000 +0900
+++ richmail/iso2022.c	2012-10-13 08:09:11.000000000 +0900
@@ -84,7 +84,7 @@
     OutCharSet = OUT_ASCII;
     OutAsciiMode = RICH_ENC_US_ASCII;
     if (!name)
-	return;
+	return(0);
     if (!strncmp (name,"iso-2022-jp",11))
 	richtextencoding (RICH_ENC_JP_ASCII);
     else if (!strncmp (name,"iso-2022-kr",11)) {
