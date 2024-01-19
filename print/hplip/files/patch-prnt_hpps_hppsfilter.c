--- prnt/hpps/hppsfilter.c.orig	2022-02-23 07:41:05 UTC
+++ prnt/hpps/hppsfilter.c
@@ -53,7 +53,7 @@ static void get_LogLevel ()
     FILE    *fp;
     char    str[258];
     char    *p;
-    fp = fopen ("/etc/cups/cupsd.conf", "r");
+    fp = fopen ("/usr/local/etc/cups/cupsd.conf", "r");
     if (fp == NULL)
         return;
     while (!feof (fp))
