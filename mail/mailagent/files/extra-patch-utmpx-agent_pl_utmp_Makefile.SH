--- ../mailagent-3.1.77/agent/pl/utmp/Makefile.SH	2006-08-24 22:24:12.354556000 +0900
+++ agent/pl/utmp/Makefile.SH	2012-01-19 17:37:50.697895588 +0900
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
