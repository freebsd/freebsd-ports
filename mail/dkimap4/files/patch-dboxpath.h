--- unixlib/dboxpath.h.orig	Wed May 16 18:39:49 2001
+++ unixlib/dboxpath.h	Mon Jun 18 00:08:26 2001
@@ -5,6 +5,7 @@
 #include <string>
 
 #include <libdbox.h>
+#include <paths.h>
 
 #ifdef __MSDOS__
 #define DIRCHAR "\\"
@@ -14,7 +15,9 @@
 
 #define TEMPDIR "/tmp/"
 
-#define DKIMAP4DIR "/var/spool/dkimap/"
+#ifndef GLOBALMAILDIR
+#define GLOBALMAILDIR _PATH_MAILDIR
+#endif
 
 //#define DBOXSYSTEMDIR "%s" "system" DIRCHAR
 //#define DBOXCLIENTDIR DBOXSYSTEMDIR "clients" DIRCHAR "%s" DIRCHAR
