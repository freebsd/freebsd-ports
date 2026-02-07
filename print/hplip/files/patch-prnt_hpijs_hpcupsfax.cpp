--- prnt/hpijs/hpcupsfax.cpp.orig	2022-02-23 07:41:05 UTC
+++ prnt/hpijs/hpcupsfax.cpp
@@ -94,7 +94,7 @@ static void GetLogLevel ()
     FILE    *fp;
     char    str[258];
     char    *p;
-    fp = fopen ("/etc/cups/cupsd.conf", "r");
+    fp = fopen ("/usr/local/etc/cups/cupsd.conf", "r");
     if (fp == NULL)
         return;
     while (!feof (fp))
@@ -687,7 +687,7 @@ int main (int argc, char **argv)
          return 1;
     }
     else
-        chmod(hpFileName, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP );
+        chmod(hpFileName, S_IRUSR | S_IWUSR | S_IRGRP | 0 );
 
     /*********** MAIN ***********/
 
