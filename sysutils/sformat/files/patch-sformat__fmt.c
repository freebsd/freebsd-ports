--- sformat/fmt.c.orig	Mon Dec 16 16:26:00 2002
+++ sformat/fmt.c	Mon Dec 16 16:27:51 2002
@@ -482,7 +482,7 @@
 	}
 
 	printf("sformat SCSI format/analysis/repair utilities\n");
-	printf("Release 3.4, Copyright J. Schilling\n\n");
+	printf("Release %s, Copyright J. Schilling\n\n", fmt_version);
 
 	if (!datfile_chk) {
 		if (datfile_present)
