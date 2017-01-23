# Correct a string that should be const
#
--- src/s3_driver.c.orig	2012-07-17 04:50:05 UTC
+++ src/s3_driver.c
@@ -309,7 +308,7 @@ static Bool S3PreInit(ScrnInfoPtr pScrn,
 	Gamma gzeros = {0.0, 0.0, 0.0};
 	int i, vgaCRIndex, vgaCRReg;
 	unsigned char tmp;
-	char *s;
+	const char *s;
 
         if (flags & PROBE_DETECT)
                 return FALSE;
