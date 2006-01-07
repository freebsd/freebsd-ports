--- libk9copy/k9dvd.cpp.orig   Fri Dec  9 19:18:03 2005
+++ libk9copy/k9dvd.cpp        Thu Jan  5 06:12:30 2006
@@ -27,7 +27,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
-#include <stdint.h>
+#ifdef HAVE_STDINT_H
+       #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+       #include <inttypes.h>
+#endif

 #include "k9dvd.h"
 #include "k9dvdtitle.h"
@@ -196,7 +200,7 @@
         return -1;
     }

-    if ( fseek(filehandle, 32808, SEEK_SET )) {
+    if ( fseek(filehandle, 32768, SEEK_SET )) {
         fclose(filehandle);
         c.sprintf(tr2i18n("Couldn't seek in %s for title\n"), dvd_device);
         setError(c);
@@ -204,12 +208,18 @@
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
     }

     fclose (filehandle);
