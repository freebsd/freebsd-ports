
$FreeBSD$

--- Makefile.PL.orig	Wed Sep 19 12:42:17 2001
+++ Makefile.PL	Tue Apr  1 14:28:44 2003
@@ -5,30 +5,16 @@
 use ExtUtils::MakeMaker;
 use Config;
 
-if ((not $ARGV[0]) or (not $ARGV[1]))
-{
-	print "Usage: perl Makefile.PL <path-to-sendmail-source> <path-to-sendmail-obj.dir>\n";
-	print "(e.g. 'perl Makefile.PL ../sendmail ../sendmail/obj.FreeBSD.4.0-RELEASE.i386')\n";
-	print "\n";
-	exit;
-}
-
 if (not $Config{usethreads})
 {
 	print "To use this module, your perl interpreter must have been compiled with\n";
 	print "\t-Dusethreads.\n";
 	print "\n";
-	exit;
+	exit 1;
 }
 
-my $SENDMAIL_PATH = MM->canonpath($ARGV[0]);
-my $SENDMAIL_OBJ_PATH = MM->canonpath($ARGV[1]);
-
-my $MILTER_LIB = MM->catdir($SENDMAIL_OBJ_PATH, "libmilter");
-my $SMUTIL_LIB = MM->catdir($SENDMAIL_OBJ_PATH, "libsmutil");
-my $SM_LIB = MM->catdir($SENDMAIL_OBJ_PATH, "libsm");
-my $MILTER_INCLUDE = MM->catdir($SENDMAIL_PATH, "include");
-my $SENDMAIL_INCLUDE = MM->catdir($SENDMAIL_PATH, "sendmail");
+my $MILTER_LIB = "/usr/lib";
+my $MILTER_INCLUDE = "/usr/include/libmilter";
 
 sub milter_configure
 {
@@ -37,7 +23,7 @@
 	my $ccflags;
 
 	# Standard milter libraries
-	$libs = "-L$MILTER_LIB -L$SMUTIL_LIB -L$SM_LIB -lmilter -lsmutil -lsm";
+	$libs = "-L$MILTER_LIB -lmilter";
 
 	# POSIX threads support.
 	if ($Config{libs} =~ /-lpthread/)
@@ -82,6 +68,6 @@
     'CONFIGURE'		=> \&milter_configure,
     'OBJECT'		=> '$(BASEEXT)$(OBJ_EXT) intpools$(OBJ_EXT) callbacks$(OBJ_EXT)',
     'DEFINE'		=> '',
-    'INC'		=> "-I$SENDMAIL_INCLUDE -I$MILTER_INCLUDE",
+    'INC'		=> "-I$MILTER_INCLUDE",
 );
 
