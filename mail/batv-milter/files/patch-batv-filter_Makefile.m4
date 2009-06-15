--- ./batv-filter/Makefile.m4.orig	2009-04-24 06:11:09.000000000 +0900
+++ ./batv-filter/Makefile.m4	2009-06-04 07:30:43.000000000 +0900
@@ -3,6 +3,7 @@
 
 define(`confMT', `TRUE')
 define(`confREQUIRE_LIBSM', `true')
+define(`confENVDEF', `-DWITHOUT_SMSTRING ')
 
 APPENDDEF(`confLIBS', `-lssl -lcrypto')
 dnl Enable and edit these paths as needed:
@@ -20,7 +21,7 @@
 bldPRODUCT_START(`executable', `batv-filter')
 define(`bldSOURCES', `batv-filter.c config.c util.c ')
 dnl PREPENDDEF(`confLIBS', ifelse(index(confENVDEF, `-DCOMMERCIAL'), -1, `-lmilter ', `../libmilter/libmilter.a '))
-PREPENDDEF(`confLIBS', `../libmilter/libmilter.a ')
+PREPENDDEF(`confLIBS', `-lmilter ')
 bldPRODUCT_END
 
 bldPRODUCT_START(`manpage', `batv-filter')
