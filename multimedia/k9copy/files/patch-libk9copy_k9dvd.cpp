--- libk9copy/k9dvd.cpp.orig	2012-05-03 20:44:13.584889344 +0600
+++ libk9copy/k9dvd.cpp	2012-05-03 20:46:39.212894579 +0600
@@ -192,7 +192,7 @@
         return -1;
     }
 
-    if ( fseek(filehandle, 32808, SEEK_SET )) {
+    if ( fseek(filehandle, 32768, SEEK_SET )) {
         fclose(filehandle);
         c=i18n("Couldn't seek in %1 for title\n").arg( dvd_device);
         setError(c);
@@ -200,12 +200,19 @@
         return -1;
     }
 
-    if ( 32 != (i = fread(title, 1, 32, filehandle)) ) {
+    {
+	#define DVD_SEC_SIZ 2048
+	char tempBuf[ DVD_SEC_SIZ ];
+	if ( DVD_SEC_SIZ != fread(tempBuf, 1, DVD_SEC_SIZ, filehandle) ) {
         fclose(filehandle);
         //        c=tr2i18n("Couldn't read enough bytes for title.\n");
         //        setError(c);
         strcpy(title, i18n("unknown").latin1());
         return 0;
+	}
+	snprintf( title, 32, "%s", tempBuf + 40 );
+	i=32;
+
     }
 
     fclose (filehandle);
