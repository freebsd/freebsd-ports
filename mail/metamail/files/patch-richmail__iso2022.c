--- richmail/iso2022.c.orig	1992-12-22 17:50:21 UTC
+++ richmail/iso2022.c
@@ -84,7 +84,7 @@ char	*name;
     OutCharSet = OUT_ASCII;
     OutAsciiMode = RICH_ENC_US_ASCII;
     if (!name)
-	return;
+	return(0);
     if (!strncmp (name,"iso-2022-jp",11))
 	richtextencoding (RICH_ENC_JP_ASCII);
     else if (!strncmp (name,"iso-2022-kr",11)) {
