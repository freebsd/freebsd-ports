--- scripts/radius.cgi.orig	Tue Jun 26 23:44:45 2001
+++ scripts/radius.cgi	Thu Jul  5 18:03:08 2001
@@ -54,8 +54,8 @@
 my $radhost		= 'radius.mydomain.com';				# radius host (if $authentication_type is 2)
 my $radsecret		= '';							# radius secret (if $authentication_type is 2)
 my $highlight		= 'lightblue';						# highlight color of tables
-my $fontname		= 'Comic Sans MS';					# default font
-my $fontsize		= '8';							# default font size
+my $fontname		= 'Helvetica';						# default font
+my $fontsize		= '12';							# default font size
 
 use IC::Radius;
 my $radius = new IC::Radius;
@@ -1613,6 +1613,7 @@
 		print q! selected! if (exists $selected_options->{$option});
 		print qq!>$option\n!;
 	}
+	print "</select>\n";
 	
 	print qq~
 			<tr><td><br></td></tr>
@@ -3007,6 +3008,7 @@
 	}
 
 	my $session = $query->cookie(-name => $cookie_name);
+	$session = "" if ( !defined($session) );
 
 	open SESSIONS, "<$sessions_file" or do {
 		&print_header; terminal_error("Unable to open file $sessions_file: $!\n");
