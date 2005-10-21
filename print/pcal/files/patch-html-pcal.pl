--- html/pcal.pl.orig	Thu Oct 20 16:16:41 2005
+++ html/pcal.pl	Thu Oct 20 16:18:11 2005
@@ -28,7 +28,7 @@
 use vars qw(%category %form);
 use strict;
 use CGI;
-$ENV{PATH} = '/usr/bin:/usr/local/bin';
+$ENV{PATH} = '/usr/bin:/usr/local/bin:@@PREFIX@@';
 
 # set DEBUG=1 to echo debugging output as HTML text
 my $DEBUG=0;
@@ -43,8 +43,8 @@
 # common calendar file on your system (note that the user can't use his/her
 # own calendar file since most servers will execute pcal.cgi as 'nobody')
 
-my $PCAL = '/usr/local/bin/pcal';
-my $FILE = '/usr/local/bin/calendar';
+my $PCAL = '@@PREFIX@@/bin/pcal';
+my $FILE = '@@PREFIX@@/bin/calendar';
 #
 my $THECAL;
 my @NOWTIME  = localtime(time()) ;
