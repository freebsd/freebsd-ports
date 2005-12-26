--- src/kdvd.cpp.orig  Sun Dec 18 23:50:47 2005
+++ src/kdvd.cpp       Mon Dec 19 00:19:47 2005
@@ -409,7 +409,7 @@
         return -1;
     }

-    if ( fseek(filehandle, 32808, SEEK_SET )) {
+    if ( fseek(filehandle, 32768, SEEK_SET )) {
         fclose(filehandle);
         c.sprintf(tr2i18n("Couldn't seek in %s for title\n"), dvd_device);
         setError(c);
@@ -417,14 +417,20 @@
         return -1;
     }

-    if ( 32 != (i = fread(title, 1, 32, filehandle)) ) {
+    {
+    #define DVD_SEC_SIZ 2048
+    char tempBuf[ DVD_SEC_SIZ ];
+    if ( DVD_SEC_SIZ != fread(tempBuf, 1, DVD_SEC_SIZ, filehandle) ) {
         fclose(filehandle);
         c=tr2i18n("Couldn't read enough bytes for title.\n");
         setError(c);
         strcpy(title, "unknown");
         return -1;
     }
-
+    snprintf( title, 32, "%s", tempBuf + 40 );
+    i=32;
+    }
+
     fclose (filehandle);

     title[32] = '\0';
