--- setaudio.c.orig	2010-09-01 10:55:30.665968356 +0200
+++ setaudio.c	2010-09-01 10:56:04.763401409 +0200
@@ -312,7 +312,7 @@ void setaudio ( void )
 char File_Name[1024];
 char *file_name;
 
-#ifdef VMS
+#if defined(VMS) || defined(__FreeBSD__) || defined(__DragonFly__)
 #else
 
   /* The audio device sometimes does not work if it is left open for a long
