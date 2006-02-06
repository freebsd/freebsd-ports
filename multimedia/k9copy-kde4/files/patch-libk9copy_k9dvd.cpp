--- libk9copy/k9dvd.cpp.orig   Mon Jan 16 10:40:01 2006
+++ libk9copy/k9dvd.cpp        Mon Jan 16 10:40:33 2006
@@ -199,7 +199,7 @@
         return -1;
     }

-    if ( fseek(filehandle, 32808, SEEK_SET )) {
+    if ( fseek(filehandle, 32768, SEEK_SET )) {
         fclose(filehandle);
         c=i18n("Couldn't seek in %1 for title\n").arg( dvd_device);
         setError(c);
@@ -207,12 +207,19 @@
         return -1;
     }

-    if ( 32 != (i = fread(title, 1, 32, filehandle)) ) {
+    {
+    #define DVD_SEC_SIZ 2048
+    char tempBuf[ DVD_SEC_SIZ ];
+    if ( DVD_SEC_SIZ != fread(tempBuf, 1, DVD_SEC_SIZ, filehandle) ) {
         fclose(filehandle);
 //        c=tr2i18n("Couldn't read enough bytes for title.\n");
 //        setError(c);
         strcpy(title, "unknown");
         return 0;
+    }
+    snprintf( title, 32, "%s", tempBuf + 40 );
+    i=32;
+
     }

     fclose (filehandle);
