--- lib/AmphetaDesk/Settings.pm.orig	Sun Oct  9 20:54:43 2005
+++ lib/AmphetaDesk/Settings.pm	Sun Oct  9 20:56:03 2005
@@ -105,9 +105,9 @@
    $SETTINGS{app_contact}                     = "Morbus Iff";
    $SETTINGS{app_email}                       = "morbus\@disobey.com";
    $SETTINGS{app_os}                          = $^O;
-   $SETTINGS{dir_data}                        = catdir($Bin, "data");
-   $SETTINGS{dir_docs}                        = catdir($Bin, "docs");
-   $SETTINGS{dir_templates}                   = catdir($Bin, "templates", "default");
+   $SETTINGS{dir_data}                        = catdir(".", "data");
+   $SETTINGS{dir_docs}                        = "%%DOCSDIR%%";
+   $SETTINGS{dir_templates}                   = catdir("%%DATADIR%%", "templates", "default");
    $SETTINGS{dir_gui}                         = catdir($SETTINGS{dir_templates}, "gui");
    $SETTINGS{dir_data_channels}               = catdir($SETTINGS{dir_data}, "channels");
    $SETTINGS{dir_data_lists}                  = catdir($SETTINGS{dir_data}, "lists");
