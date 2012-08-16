--- lib/Publican/WebSite.pm.orig	2012-08-16 13:35:06.489393365 -0400
+++ lib/Publican/WebSite.pm	2012-08-16 13:35:47.792392091 -0400
@@ -23,9 +23,9 @@
 
 my $DB_NAME             = 'books';
 my $DEFAULT_LANG        = 'en-US';
-my $DEFAULT_TMPL_PATH   = '/usr/share/publican/templates';
-my $DEFAULT_CONFIG_FILE = '/etc/publican-website.cfg';
-my $DEFAULT_DUMP_FILE   = '/var/www/html/DUMP.xml';
+my $DEFAULT_TMPL_PATH   = '%%DATADIR%%/templates';
+my $DEFAULT_CONFIG_FILE = '%%PREFIX%%/etc/publican-website.cfg';
+my $DEFAULT_DUMP_FILE   = '/var/tmp/DUMP.xml';
 
 my %LANG_NAME = (
     'ar-SA'      => 'العربية',
