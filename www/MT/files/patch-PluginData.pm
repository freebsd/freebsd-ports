--- lib/MT/PluginData.pm.orig	Sun Nov  7 21:06:34 2004
+++ lib/MT/PluginData.pm	Sun Nov  7 21:07:27 2004
@@ -7,7 +7,7 @@
 use strict;
 
 use Storable qw( freeze thaw );
-
+$Storable::interwork_56_64bit = 1;
 use MT::Object;
 @MT::PluginData::ISA = qw( MT::Object );
 __PACKAGE__->install_properties ({
