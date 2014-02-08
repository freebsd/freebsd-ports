--- etc/afpd/afp_mdns.c.orig	2014-01-21 15:12:49.465373000 +0000
+++ etc/afpd/afp_mdns.c	2014-01-21 15:15:03.618213000 +0000
@@ -36,18 +36,16 @@ static pthread_t       poller;
 /*
  * Its easier to use asprintf to set the TXT record values
  */
-#define TXTRecordPrintf(rec, key, args, ...) {           \
-        char *str;                                      \
-        asprintf(&str, args);                           \
+#define TXTRecordPrintf(rec, key, args...) {           \
+        char str[1024];                                      \
+        sprintf(str, args);                           \
         TXTRecordSetValue(rec, key, strlen(str), str);  \
-        free(str);                                      \
     }
-#define TXTRecordKeyPrintf(rec, k, var, args, ...) {     \
-        char *key, *str;                                \
-        asprintf(&key, k, var);                         \
-        asprintf(&str, args);                           \
+#define TXTRecordKeyPrintf(rec, k, var, args...) {     \
+        char key[1024], str[1024];                                \
+        sprintf(key, k, var);                         \
+        sprintf(str, args);                           \
         TXTRecordSetValue(rec, key, strlen(str), str);  \
-        free(str); free(key);                           \
     }
 
 static struct pollfd *fds;
