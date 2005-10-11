--- lib/AmphetaDesk/ChannelsList.pm.orig	Tue Oct 11 01:12:48 2005
+++ lib/AmphetaDesk/ChannelsList.pm	Tue Oct 11 01:35:03 2005
@@ -18,6 +18,7 @@
 use strict; $|++;
 use AmphetaDesk::Settings;
 use AmphetaDesk::Utilities;
+use AmphetaDesk::WWW;
 use XML::Parser;
 require Exporter;
 use vars qw( @ISA @EXPORT );
@@ -103,6 +104,12 @@
    # my logfile is aroused.
    note("Loading our channel list from " .
         get_setting("names_file_services_channels") . ".");
+
+   # fetch updated version if none exists locally
+   if (! -e (get_setting("files_services_channels")) ) {
+     my $l = new AmphetaDesk::WWW;
+     $l->getstore( "http://www.disobey.com/amphetadesk/lists/services-channels-recent.xml", (get_setting("files_services_channels")) );
+   }
 
    # get an new instance of the parser,
    # register handlers, then parse.
