--- Makefile.PL	Tue Dec  9 03:46:48 2003
+++ Makefile.PL.patched	Wed Nov 10 17:53:26 2004
@@ -11,4 +11,4 @@
 
 &Meta->write;
 &Build->write if lc($0) eq 'build.pl';
-&Makefile->write if lc($0) eq 'makefile.pl';
+&Makefile->write if ((lc($0) eq 'makefile.pl') || (lc($0) eq './makefile.pl'));
