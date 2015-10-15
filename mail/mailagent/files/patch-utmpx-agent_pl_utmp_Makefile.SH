--- ./agent/pl/utmp/Makefile.SH.orig	2006-08-24 22:24:12.000000000 +0900
+++ ./agent/pl/utmp/Makefile.SH	2014-08-14 01:59:33.508704927 +0900
@@ -107,7 +107,6 @@
 	cp Makefile.new Makefile
 	$(RM) Makefile.new
 
-all:: utmp_ph
 
 local_realclean::
 	$(RM) utmp_ph
@@ -122,8 +121,7 @@
 local_realclean::
 	$(RM) utmp.pl
 
-utmp.pl: utmp_pl.sh utmp_ph
-	/bin/sh utmp_pl.sh
+utmp.pl:
 
 ########################################################################
 # Common rules for all Makefiles -- do not edit
