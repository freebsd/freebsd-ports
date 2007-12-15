--- ./lib/Sys/Filesystem.pm.orig	Thu Jun  1 14:10:48 2006
+++ ./lib/Sys/Filesystem.pm	Fri Nov 30 11:39:17 2007
@@ -30,6 +30,8 @@
 use vars qw($VERSION $AUTOLOAD);
 $VERSION = '1.22' || sprintf('%d', q$Revision: 574 $ =~ /(\d+)/g);
 
+our @special_fs = qw(swap proc tmpfs nfs autofs);
+
 sub new {
 	# Check we're being called correctly with a class name
 	ref(my $class = shift) && croak 'Class name required';
