#!/usr/bin/perl -w
# by frank

use strict;

my $current_apache_version = `/usr/local/sbin/httpd -v|head -1`;
my @version = split / /, $current_apache_version;
my $version;

$version = $version[2];
$version =~ s/^Apache\///g;
chomp $version;

if ( ! -e '/compat/linux/opt/opengroupware.org/OpenGroupware.org.apacheinclude' ) {
	print "OpenGroupware.org.apacheinclude is not present! I'll deal with this issue!\n";
	open (AI, "> /compat/linux/opt/opengroupware.org/OpenGroupware.org.apacheinclude");
	print AI "LoadModule ngobjweb_module\t/compat/linux/opt/opengroupware.org/ngobjweb_$version.so\n";
	print AI "\n";
	print AI "<LocationMatch \"^/OpenGroupware/*\">\n";
	print AI "\tSetHandler ngobjweb-adaptor\n";
	print AI "\tSetAppPort 20000\n";
	print AI "</LocationMatch>\n";
	print AI "\n";
	print AI "Alias /OpenGroupware.woa/WebServerResources/ \"/compat/linux/opt/opengroupware.org/WebServerResources/\"\n";
	close(AI);
} else {
	print "OpenGroupware.org.apacheinclude is already present and will not be changed!\n";
}	
