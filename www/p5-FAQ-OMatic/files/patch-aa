--- fom.PL-orig	Fri May 30 09:42:46 2003
+++ fom.PL	Fri May 30 09:43:19 2003
@@ -51,7 +51,8 @@
 close THECGI;
 chmod 0755, "fom";
 
-print <<"__EOF__";
+open( F, ">install.notes" );
+print F <<"__EOF__";
 
 If this is a new FAQ-O-Matic, you will need the following
 temporary password to complete the installation. (This helps
@@ -68,7 +69,6 @@
 Finally, you may get this error at the end of make install:
 /bin/sh: .../user_perl/lib/sun4-solaris/5.00401/perllocal.pod: cannot create
 You can ignore it.
-
-Press enter to continue.
 __EOF__
-my $dummy = <STDIN>;
+
+close( F );
