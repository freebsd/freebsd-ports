--- Makefile.PL.orig	Thu May 10 01:43:18 2001
+++ Makefile.PL	Thu May 10 01:43:42 2001
@@ -7,44 +7,3 @@
     'clean' 		=> {	FILES 	=> 'test.txt'	}
 
 );
-
-&set_test_data;
-
-sub set_test_data {
-	unless (-f "./IMAPClient.pm") { warn "ERROR: not in installation directory\n"; return }
-	return if -f "./test.txt";
-	print 	"You have the option of running an extended suite of tests during\n",
-		"'make test'. This requires an IMAP server name, user account, and ",
-		"password to test with.","\n","\n",
-		"Do you want to run the extended tests? (n/y) ==> ";
-	my $yes = <STDIN>;
-	return unless $yes =~ /^[Yy](?:[Ee]:[Ss]?)?$/ ;
-	unless (open TST,">./test.txt") { warn "ERROR: couldn't open ./test.txt: $!\n"; return }
-	print "\nPlease provide the hostname of a host running an IMAP server \n",
-		"(or QUIT to skip the extended tests) ==> ";
-	my $server = <STDIN>;
-	chomp $server;
-	return if $server =~ /^\s+$|^quit$/i ;
-	print TST "server=$server\n";
-	print "\nPlease provide the username of an account\non $server (or QUIT) ==> ";
-	my $user = <STDIN>;
-	chomp $user;
-	return if $user =~ /^\s+$|^quit$/i ;
-	print TST "user=$user\n";
-	print "\nPlease provide the password for $user\n(or QUIT) ==> ";
-	my $passed = <STDIN>;
-	chomp $passed;
-	return if $passed =~ /^\s+$|^quit$/i ;
-	print TST "passed=$passed\n";
-	print "\nPlease provide the port to connect to on $server to run the test \n",
-		"(default is 143) ==> ";
-	my $port = <STDIN>;
-	chomp $port;
-	$port ||= 143; 
-	print TST "port=$port\n";
-	close TST;
-	print "\nGracias! The information you provided (including the \n",
-		" password!) has been stored in ",cwd,"/test.txt and should be\n",
-		" removed (either by hand or by 'make clean') after testing.\n";
-}
-
