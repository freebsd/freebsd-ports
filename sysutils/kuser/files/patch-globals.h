error: invalid suffix on literal; C++11 requires a space between literal and identifier 
[-Wreserved-user-defined-literal]
  #define PWMKDB _PATH_PWD_MKDB" -p "PASSWORD_FILE

--- globals.h.orig	2018-01-07 18:03:51 UTC
+++ globals.h
@@ -53,7 +53,7 @@
   #include <pwd.h>
   #define PASSWORD_FILE _PATH_MASTERPASSWD
   #define PASSWORD_FILE_MASK S_IRUSR | S_IWUSR
-  #define PWMKDB _PATH_PWD_MKDB" -p "PASSWORD_FILE
+  #define PWMKDB _PATH_PWD_MKDB " -p " PASSWORD_FILE
   #define SKELDIR "/usr/share/skel"
   #define SKEL_FILE_PREFIX "dot"
   #define CRONTAB_DIR "/var/cron/tabs"
