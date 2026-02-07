--- setaudio.c.orig	1999-04-07 20:06:21 UTC
+++ setaudio.c
@@ -297,7 +297,7 @@ modification follow.
 #include <fcntl.h>
 #include "periodic.h"
 
-FILE *Audio;
+extern FILE *Audio;
 int AudioFiles;
 
 extern char *program_root;
@@ -312,7 +312,7 @@ void setaudio ( void )
 char File_Name[1024];
 char *file_name;
 
-#ifdef VMS
+#if defined(VMS) || defined(__FreeBSD__) || defined(__DragonFly__)
 #else
 
   /* The audio device sometimes does not work if it is left open for a long
