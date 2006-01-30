--- lib/Math/Vec.pm.orig	Sun Jan  8 07:40:51 2006
+++ lib/Math/Vec.pm	Mon Jan 30 23:36:57 2006
@@ -1,5 +1,6 @@
 package Math::Vec;
-our $VERSION   = '0.031';
+use vars qw($VERSION);
+$VERSION   = '0.031';
 
 =pod
 
