--- BitTorrent/BDecode.pm.orig	2016-06-20 14:38:26 UTC
+++ BitTorrent/BDecode.pm
@@ -5,7 +5,6 @@ package BitTorrent::BDecode;
 use Carp;
 use base 'Exporter';
 use strict;
-our @EXPORT_OK = qw(bdecode);
 
 sub bdecode {
   my ($dataref) = @_;
