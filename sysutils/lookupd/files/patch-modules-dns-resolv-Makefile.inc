--- modules/dns/resolv/Makefile.inc.orig	Tue Aug  1 18:10:57 2006
+++ modules/dns/resolv/Makefile.inc	Tue Aug  1 18:11:07 2006
@@ -1,6 +1,4 @@
 # $FreeBSD$
 
 .PATH: ${.CURDIR}/resolv
-SRCS+=getaddrinfo.c	res_comp.c res_mkquery.c res_send.c herror.c \
-			res_data.c res_mkupdate.c res_update.c \
-			name6.c res_init.c res_query.c
+SRCS+=getaddrinfo.c name6.c
