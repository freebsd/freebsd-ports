#!/usr/bin/perl -w
# 
# by Frank Reppin <frank.reppin@boerde.de>
# 

use strict;

my $current_apache_version = `/usr/local/sbin/httpd -v|head -1`;
my @version = split / /, $current_apache_version;
my $version;
my $runs_with;

$version = $version[2];
$version =~ s/^Apache\///g;
chomp $version;

if ( ! -e '/compat/linux/opt/opengroupware.org/OpenGroupware.org.apacheinclude' ) {
	print "OpenGroupware.org.apacheinclude is not present! I'll deal with this issue!\n";
	open (AI, "> /compat/linux/opt/opengroupware.org/OpenGroupware.org.apacheinclude") || die "Arrr! This won't work, because: $!\n";
		print AI "# This loads the mod_ngobjweb module which is the binding part between\n";
		print AI "# the Apache web server and the OGo application.\n";
		print AI "#\n";
	print AI "LoadModule ngobjweb_module\t/compat/linux/opt/opengroupware.org/ngobjweb_$version.so\n";
	print AI "\n";
		print AI "<LocationMatch \"^/OpenGroupware*\">\n";
	print AI "\tSetHandler ngobjweb-adaptor\n";
		print AI "\tSetAppPort 19999\n";
		print AI "</LocationMatch>\n";
		print AI "\n";
		print AI "<LocationMatch \"^/evolution*\">\n";
		print AI "\tSetHandler ngobjweb-adaptor\n";
		print AI "\tSetAppPort 20001\n";
		print AI "</LocationMatch>\n";
		print AI "\n";
		print AI "<LocationMatch \"^/zidestore/*\">\n";
		print AI "\tSetHandler ngobjweb-adaptor\n";
		print AI "\tSetAppPort 20001\n";
	print AI "</LocationMatch>\n";
	print AI "\n";
	print AI "Alias /OpenGroupware.woa/WebServerResources/ \"/compat/linux/opt/opengroupware.org/WebServerResources/\"\n";
		print AI "Alias /ArticleImages \"/compat/linux/opt/opengroupware.org/news\"\n";
	close(AI);
} else {
		print "\n";
	print "OpenGroupware.org.apacheinclude is already present and will not be changed!\n";
		open(OI, "/compat/linux/opt/opengroupware.org/OpenGroupware.org.apacheinclude");
			while(<OI>) {
				if (/ngobjweb_\d+.*\.so$/) {
					$runs_with = $&;
					$runs_with =~ s/^ngobjweb_//g;
					$runs_with =~ s/\.so$//g;
				}
			}
		close(OI);
		if ( $runs_with eq $version ) {
			print "The OpenGroupware.org.apacheinclude seems to be fine.\n";
			print "It's configured for Apache $runs_with and we have Apache $version\n";
		} else {
			print "\n";
			print "But! Chances are, that your OpenGroupware.org.apacheinclude is broken.\n";
			print "This isn't necessarily an error - as it might be a result of a special\n";
			print "configuration you're using.\n";
			print "It's also very likely that you've updated your Apache from ports in between.\n";
			print "\n";
			print "Here are the results:\n";
			print "-------------------------\n";
			print "OpenGroupware.org.apacheinclude is configured to use Apache $runs_with\n";
			print "The version string of your Apache binary indicates that you run $version\n";
			print "Please verify this setting manually and - if needed - update your\n";
			print "OpenGroupware.org.apacheinclude to reflect the recent changes made to your system.\n";
		}
}	
