--- unixlib/dboxpath.h.orig	Thu May 17 01:39:49 2001
+++ unixlib/dboxpath.h	Mon Aug  6 02:52:11 2001
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
+#define GLOBALMAILDIR _PATH_MAILDIR "/"
+#endif
 
 //#define DBOXSYSTEMDIR "%s" "system" DIRCHAR
 //#define DBOXCLIENTDIR DBOXSYSTEMDIR "clients" DIRCHAR "%s" DIRCHAR
