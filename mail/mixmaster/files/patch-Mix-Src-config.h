--- Mix/Src/config.h.orig	2014-06-01 23:03:49.000000000 +0200
+++ Mix/Src/config.h	2014-06-01 23:04:46.000000000 +0200
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
