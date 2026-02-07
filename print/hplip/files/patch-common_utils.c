--- common/utils.c.orig	2022-02-23 07:41:04 UTC
+++ common/utils.c
@@ -311,7 +311,7 @@ int getHPLogLevel()
     char    *p;
     int iLogLevel = 0;
 
-    fp = fopen ("/etc/cups/cupsd.conf", "r");
+    fp = fopen ("/usr/local/etc/cups/cupsd.conf", "r");
     if (fp == NULL)
         return 0;
     while (!feof (fp))
