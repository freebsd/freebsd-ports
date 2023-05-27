--- src/util/pwd.c.orig	2022-08-27 02:05:10 UTC
+++ src/util/pwd.c
@@ -31,6 +31,7 @@
 #include <pwd.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/param.h>
 #include <unistd.h>
 
 
@@ -67,7 +68,7 @@ char * snoopy_util_pwd_convertUidToUsername (uid_t uid
         return NULL;
     }
 
-    username = malloc(LOGIN_NAME_MAX+1);
+    username = malloc(MAXLOGNAME+1);
     if (NULL == username) {
         free(buffpwd_uid);
         return NULL;
@@ -85,11 +86,11 @@ char * snoopy_util_pwd_convertUidToUsername (uid_t uid
 
     // Format the return
     if (NULL == pwd_uid) {
-        snprintf(username, LOGIN_NAME_MAX, "user-%d", (int)uid);
+        snprintf(username, MAXLOGNAME, "user-%d", (int)uid);
     } else {
-        snprintf(username, LOGIN_NAME_MAX, "%s", pwd_uid->pw_name);
+        snprintf(username, MAXLOGNAME, "%s", pwd_uid->pw_name);
     }
-    username[LOGIN_NAME_MAX] = '\0'; // Just in case
+    username[MAXLOGNAME] = '\0'; // Just in case
 
 
     // Return
