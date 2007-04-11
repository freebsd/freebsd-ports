--- libar/Makefile.m4.orig	Sun Sep 17 01:00:43 2006
+++ libar/Makefile.m4	Wed Apr 11 16:24:39 2007
@@ -12,7 +12,6 @@
 
 bldPRODUCT_START(`library', `libar')
 define(`bldSOURCES', `ar.c manual.c ')
-define(`bldINSTALLABLE', `true')
 bldPRODUCT_END
 
 bldPRODUCT_START(`manpage', `ar')
