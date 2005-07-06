--- lxdvdrip.c.orig	Tue May 31 23:26:37 2005
+++ lxdvdrip.c	Wed Jul  6 18:34:10 2005
@@ -763,6 +763,9 @@
   FILE *filehandle = 0;
   int i;
 
+#define	DVD_SEC_SIZ	2048
+  char	tempBuf[DVD_SEC_SIZ];
+
   if (!(filehandle = fopen (dvd_device, "r")))
     {
       switch (lSprache)
@@ -782,7 +785,7 @@
       return -1;
     }
 
-  if (fseek (filehandle, 32808, SEEK_SET))
+  if (fseek (filehandle, 32768, SEEK_SET))
     {
       fclose (filehandle);
       switch (lSprache)
@@ -802,7 +805,7 @@
       return -1;
     }
 
-  if (32 != (i = fread (title, 1, 32, filehandle)))
+  if (DVD_SEC_SIZ != fread (tempBuf, 1, DVD_SEC_SIZ, filehandle))
     {
       fclose (filehandle);
       switch (lSprache)
@@ -820,7 +823,8 @@
       strcpy (title, "unknown");
       return -1;
     }
-
+  snprintf( title, 32, "%s", tempBuf + 40 );
+  i=32;
   fclose (filehandle);
 
   title[32] = '\0';
