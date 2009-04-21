--- Makefile.inc.orig	2009-04-21 09:52:03.000000000 +0100
+++ Makefile.inc	2009-04-21 09:54:50.000000000 +0100
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
