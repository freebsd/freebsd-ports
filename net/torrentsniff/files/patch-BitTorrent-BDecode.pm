--- BitTorrent/BDecode.pm.orig	Sun Jun 15 05:47:46 2003
+++ BitTorrent/BDecode.pm	Fri Nov 14 18:42:44 2003
@@ -5,7 +5,6 @@
 use Carp;
 use base 'Exporter';
 use strict;
-our @EXPORT_OK = qw(bdecode);
 
 sub bdecode {
   my ($dataref) = @_;
