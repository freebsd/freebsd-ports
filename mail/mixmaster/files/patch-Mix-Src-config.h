--- Mix/Src/config.h.orig	2014-05-01 10:06:28.000000000 +0200
+++ Mix/Src/config.h	2014-06-16 17:41:37.000000000 +0200
@@ -179,11 +179,11 @@
 #define BUFSIZE 4096
 
 /** if it is a systemwide installation defined GLOBALMIXCONF **********/
-/* #define GLOBALMIXCONF "/etc/mix.cfg" */
+#define GLOBALMIXCONF "%%ETCDIR%%/mix.cfg"
 
 /* The path to append to a user's homedirectory for his local Mix dir */
 #ifndef HOMEMIXDIR
-#define HOMEMIXDIR "Mix"
+#define HOMEMIXDIR ".Mix"
 #endif
 
 /** file names ********************************************************/
@@ -241,7 +241,7 @@
 #define DEFAULT_STAREX "starex.txt"
 #define DEFAULT_ALLPINGERSURL "http://www.noreply.org/allpingers/allpingers.txt"
 #define DEFAULT_ALLPINGERSFILE "allpingers.txt"
-#define DEFAULT_WGET "wget"
+#define DEFAULT_WGET "/usr/bin/fetch"
 
 DLLIMPORT extern char MIXCONF[];
 extern char DISCLAIMFILE[];
