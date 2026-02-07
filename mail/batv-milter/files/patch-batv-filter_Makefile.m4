--- batv-filter/Makefile.m4.orig	2009-04-23 21:11:09 UTC
+++ batv-filter/Makefile.m4
@@ -3,6 +3,7 @@ include(confBUILDTOOLSDIR`/M4/switch.m4'
 
 define(`confMT', `TRUE')
 define(`confREQUIRE_LIBSM', `true')
+define(`confENVDEF', `-DWITHOUT_SMSTRING ')
 
 APPENDDEF(`confLIBS', `-lssl -lcrypto')
 dnl Enable and edit these paths as needed:
@@ -15,12 +16,12 @@ dnl Enable these next line if needed to 
 dnl and the libmilter include files:
 dnl APPENDDEF(`confINCDIRS', `-I/usr/local/sendmail/include')
 dnl APPENDDEF(`confLIBDIRS', `-L/usr/local/sendmail/lib')
-
+APPENDDEF(`confLIBDIRS', `-L/usr/local/lib')
 
 bldPRODUCT_START(`executable', `batv-filter')
 define(`bldSOURCES', `batv-filter.c config.c util.c ')
 dnl PREPENDDEF(`confLIBS', ifelse(index(confENVDEF, `-DCOMMERCIAL'), -1, `-lmilter ', `../libmilter/libmilter.a '))
-PREPENDDEF(`confLIBS', `../libmilter/libmilter.a ')
+PREPENDDEF(`confLIBS', `-lmilter ')
 bldPRODUCT_END
 
 bldPRODUCT_START(`manpage', `batv-filter')
