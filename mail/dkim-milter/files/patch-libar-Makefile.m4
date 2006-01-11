--- libar/Makefile.m4.orig	Tue Jul 19 06:18:09 2005
+++ libar/Makefile.m4	Tue Jan 10 14:57:04 2006
@@ -11,7 +11,6 @@
 
 bldPRODUCT_START(`library', `libar')
 define(`bldSOURCES', `ar.c fix.c ')
-define(`bldINSTALLABLE', `true')
 bldPRODUCT_END
 
 bldPRODUCT_START(`manpage', `ar')
