--- ./dkim-filter/Makefile.m4.orig	2008-03-06 02:58:40.000000000 +0900
+++ ./dkim-filter/Makefile.m4	2008-03-22 02:05:26.000000000 +0900
@@ -12,7 +12,7 @@
 ifelse(index(confENVDEF, `-DQUERY_CACHE'), -1, `', `
 define(`confUSE_DB', `TRUE')
 ')
-ifelse(index(confENVDEF, `-DPOPAUTH'), -1, `', `
+ifelse(index(conf_dkim_filter_ENVDEF, `-DPOPAUTH'), -1, `', `
 define(`confUSE_DB', `TRUE')
 ')
 ifelse(index(confENVDEF, `-D_FFR_BODYLENGTH_DB'), -1, `', `
