--- dmarcts-report-parser.pl.orig	2023-06-25 14:23:56 UTC
+++ dmarcts-report-parser.pl
@@ -88,7 +88,7 @@ sub show_usage {
 	print "    ./dmarcts-report-parser.pl [OPTIONS] [PATH] \n";
 	print "\n";
 	print " This script needs a configuration file called <dmarcts-report-parser.conf> in \n";
-	print " the current working directory, which defines a database server with credentials \n";
+	print " %%PREFIX%%/etc, which defines a database server with credentials \n";
 	print " and (if used) an IMAP server with credentials. \n";
 	print "\n";
 	print " Additionaly, one of the following source options must be provided: \n";
@@ -171,7 +171,7 @@ use constant ALLOWED_SPFRESULT => qw(
 
 # Load script configuration options from local config file. The file is expected
 # to be in the current working directory.
-my $conf_file = 'dmarcts-report-parser.conf';
+my $conf_file = '%%PREFIX%%/etc/dmarcts-report-parser.conf';
 
 # Get command line options.
 my %options = ();
@@ -265,7 +265,7 @@ if (exists $options{info}) {$processInfo = 1;}
 
 # Setup connection to database server.
 our %dbx;
-my $dbx_file = File::Basename::dirname($0) . "/dbx_$dbtype.pl";
+my $dbx_file = "%%DATADIR%%/dbx_$dbtype.pl";
 my $dbx_return = do $dbx_file;
 die "$scriptname: couldn't load DB definition for type $dbtype: $@" if $@;
 die "$scriptname: couldn't load DB definition for type $dbtype: $!" unless defined $dbx_return;
