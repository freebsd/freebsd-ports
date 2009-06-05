--- ./libar/Makefile.m4.orig	2009-04-27 05:59:32.000000000 +0900
+++ ./libar/Makefile.m4	2009-04-27 05:59:57.000000000 +0900
@@ -11,6 +11,7 @@
 
 bldPRODUCT_START(`library', `libar')
 define(`bldSOURCES', `ar.c manual.c ')
+%%ARLIB%%define(`bldINSTALLABLE', `true')
 bldPRODUCT_END
 
 bldPRODUCT_START(`manpage', `ar')
