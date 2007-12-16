--- ./dkim-filter/Makefile.m4.orig	2007-11-01 04:00:07.000000000 +0900
+++ ./dkim-filter/Makefile.m4	2007-12-17 03:50:11.000000000 +0900
@@ -31,18 +31,21 @@
 
 
 bldPRODUCT_START(`executable', `dkim-filter')
+define(`bldINSTALL_DIR', `E')
 define(`bldSOURCES', `config.c dkim-ar.c dkim-filter.c stats.c test.c util.c ')
 PREPENDDEF(`confLIBS', `-lmilter ')
 bldPRODUCT_END
 
 ifelse(index(confENVDEF, `-D_FFR_STATS'), -1, `', `
 bldPRODUCT_START(`executable', `dkim-stats')
+define(`bldINSTALL_DIR', `U')
 define(`bldSOURCES', `dkim-stats.c ')
 bldPRODUCT_END
 ')
 
 dnl Install code for dkim-genkey is in here
 bldPRODUCT_START(`executable', `dkim-testkey')
+define(`bldINSTALL_DIR', `U')
 define(`bldSOURCES', `dkim-testkey.c ')
 bldPUSH_INSTALL_TARGET(`install-genkey')
 divert(bldTARGETS_SECTION)
@@ -54,6 +57,7 @@
 bldPRODUCT_END
 
 bldPRODUCT_START(`executable', `dkim-testssp')
+define(`bldINSTALL_DIR', `U')
 define(`bldSOURCES', `dkim-testssp.c ')
 bldPRODUCT_END
 
