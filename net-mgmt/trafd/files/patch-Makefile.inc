--- Makefile.inc.orig	2002-11-27 08:40:39.000000000 -0500
+++ Makefile.inc	2009-05-29 14:09:06.000000000 -0400
@@ -18,11 +18,11 @@
 
 PREFIX?=/usr/local
 BINDIR?=${PREFIX}/bin
-MANDIR?=${PREFIX}/man/man1
-SAVEDIR?=/var/trafd/
+MANDIR?=${MANPREFIX}/man1
+SAVEDIR?=${PREFIX}/var/trafd/
 
 TRAFSTAT=${BINDIR}/trafstat
-TRAFSTAT_LOG=/var/log/trafstat.log
+TRAFSTAT_LOG=${PREFIX}/var/log/trafstat.log
 TRAFSTAT_PORT=150
 
 TRAFLOG_FMT=${PREFIX}/etc/traflog.format
@@ -40,6 +40,7 @@
 	-DPATH_TRAFSTAT=\"${TRAFSTAT}\" \
 	-DPATH_TRAFSTAT_LOG=\"${TRAFSTAT_LOG}\" \
 	-DPATH_TRAFLOG_FMT=\"${TRAFLOG_FMT}\" \
-	-DTRAFSTAT_PORT=${TRAFSTAT_PORT}
+	-DTRAFSTAT_PORT=${TRAFSTAT_PORT} \
+	-DCSLIP
 
 
