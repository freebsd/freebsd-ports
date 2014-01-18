--- etc/afpd/afp_mdns.c.orig	2013-10-28 06:43:13.000000000 -0700
+++ etc/afpd/afp_mdns.c	2014-01-17 22:10:59.000000000 -0800
@@ -37,17 +37,15 @@
  * Its easier to use asprintf to set the TXT record values
  */
 #define TXTRecordPrintf(rec, key, args, ...) {           \
-        char *str;                                      \
-        asprintf(&str, args);                           \
+        char str[1024];                                      \
+        sprintf(str, args);                           \
         TXTRecordSetValue(rec, key, strlen(str), str);  \
-        free(str);                                      \
     }
 #define TXTRecordKeyPrintf(rec, k, var, args, ...) {     \
-        char *key, *str;                                \
-        asprintf(&key, k, var);                         \
-        asprintf(&str, args);                           \
+        char key[1024], str[1024];                                \
+        sprintf(key, k, var);                         \
+        sprintf(str, args);                           \
         TXTRecordSetValue(rec, key, strlen(str), str);  \
-        free(str); free(key);                           \
     }
 
 static struct pollfd *fds;
@@ -134,7 +132,7 @@
 
     /* Register our service, prepare the TXT record */
     TXTRecordCreate(&txt_adisk, 0, NULL);
-    TXTRecordPrintf(&txt_adisk, "sys", "waMa=0,adVF=0x100");
+    TXTRecordPrintf(&txt_adisk, "sys", "waMa=0,adVF=0x100", NULL);
 
     /* Build AFP volumes list */
     int i = 0;
