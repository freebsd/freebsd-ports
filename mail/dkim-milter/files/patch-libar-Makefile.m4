--- ./libar/Makefile.m4.orig	Sun Sep 17 08:00:43 2006
+++ ./libar/Makefile.m4	Mon Nov  6 00:28:03 2006
@@ -12,7 +12,6 @@
 
 bldPRODUCT_START(`library', `libar')
 define(`bldSOURCES', `ar.c manual.c ')
-define(`bldINSTALLABLE', `true')
 bldPRODUCT_END
 
 bldPRODUCT_START(`manpage', `ar')
