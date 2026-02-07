--- lsdvd.c.orig	Wed Apr 13 23:34:34 2005
+++ lsdvd.c	Fri Nov 11 11:41:05 2005
@@ -124,19 +124,26 @@
 		return -1;
 	}
 
-	if ( fseek(filehandle, 32808, SEEK_SET )) {
+	if ( fseek(filehandle, 32768, SEEK_SET )) {
 		fclose(filehandle);
 		fprintf(stderr, "Couldn't seek in %s for title\n", dvd_device);
 		strcpy(title, "unknown");
 		return -1;
 	}
 
-	if ( 32 != (i = fread(title, 1, 32, filehandle)) ) {
+	{
+	#define DVD_SEC_SIZ 2048
+	char tempBuf[ DVD_SEC_SIZ ];
+
+	if ( DVD_SEC_SIZ != fread(tempBuf, 1, DVD_SEC_SIZ, filehandle) ) {
 		fclose(filehandle);
 		fprintf(stderr, "Couldn't read enough bytes for title.\n");
 		strcpy(title, "unknown");
 		return -1;
 	}
+	snprintf( title, 32, "%s", tempBuf + 40 );
+	i=32;
+	}
 
 	fclose (filehandle);
 
