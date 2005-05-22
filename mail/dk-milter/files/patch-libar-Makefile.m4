--- libar/Makefile.m4.bak	Thu Sep  2 03:42:21 2004
+++ libar/Makefile.m4	Sun May 22 13:29:22 2005
@@ -6,7 +6,6 @@
 
 bldPRODUCT_START(`library', `libar')
 define(`bldSOURCES', `ar.c ')
-define(`bldINSTALLABLE', `true')
 bldPRODUCT_END
 
 bldPRODUCT_START(`manpage', `ar')
