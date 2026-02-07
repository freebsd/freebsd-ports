--- lib/AmphetaDesk/Settings.pm.orig	Mon Oct 28 14:40:19 2002
+++ lib/AmphetaDesk/Settings.pm	Mon Oct 10 17:05:56 2005
@@ -33,7 +33,6 @@
 
 # where are we?
 use FindBin qw($Bin);
-BEGIN { unshift(@INC, catdir($Bin, "lib")); }
 
 # where we store our
 # in-memory settings.
@@ -105,9 +104,9 @@
    $SETTINGS{app_contact}                     = "Morbus Iff";
    $SETTINGS{app_email}                       = "morbus\@disobey.com";
    $SETTINGS{app_os}                          = $^O;
-   $SETTINGS{dir_data}                        = catdir($Bin, "data");
-   $SETTINGS{dir_docs}                        = catdir($Bin, "docs");
-   $SETTINGS{dir_templates}                   = catdir($Bin, "templates", "default");
+   $SETTINGS{dir_data}                        = catdir($ENV{'HOME'}, ".amphetadesk", "data");
+   $SETTINGS{dir_docs}                        = "%%DOCSDIR%%";
+   $SETTINGS{dir_templates}                   = catdir("%%DATADIR%%", "templates", "default");
    $SETTINGS{dir_gui}                         = catdir($SETTINGS{dir_templates}, "gui");
    $SETTINGS{dir_data_channels}               = catdir($SETTINGS{dir_data}, "channels");
    $SETTINGS{dir_data_lists}                  = catdir($SETTINGS{dir_data}, "lists");
