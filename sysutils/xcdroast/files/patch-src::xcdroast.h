--- src/xcdroast.h.orig	Fri Dec 27 18:57:24 2002
+++ src/xcdroast.h	Fri Dec 27 18:59:40 2002
@@ -99,11 +99,11 @@
    then in $PREFIX (e.g. /usr/bin/cdrecord instead of 
    /usr/local/lib/xcdroast-0.98/bin/cdrecord) */
 
-#define CDRECORD "bin/cdrecord" 
-#define CDRECORDPRODVD "bin/cdrecord.prodvd" 
-#define CDDA2WAV "bin/cdda2wav"
-#define READCD "bin/readcd"
-#define MKISOFS "bin/mkisofs"
+#define CDRECORD "%%LOCALBASE%%/bin/cdrecord" 
+#define CDRECORDPRODVD "%%LOCALBASE%%/bin/cdrecord.prodvd" 
+#define CDDA2WAV "%%LOCALBASE%%/bin/cdda2wav"
+#define READCD "%%LOCALBASE%%/bin/readcd"
+#define MKISOFS "%%LOCALBASE%%/bin/mkisofs"
 
 /* MINIMUM required versions. Greater versions are now silently
    accepted. 
