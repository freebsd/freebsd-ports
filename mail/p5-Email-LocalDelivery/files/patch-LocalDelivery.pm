--- LocalDelivery.pm.orig       Mon Sep  1 20:36:31 2003
+++ LocalDelivery.pm    Mon Sep  1 20:30:45 2003
@@ -1,11 +1,10 @@
 package Email::LocalDelivery;

-require 5.005_62;
 use strict;
-use warnings;
 use Email::FolderType qw(folder_type);
 use Carp;
-our $VERSION = '0.05';
+use vars qw($VERSION);
+$VERSION = '0.05';

 =head1 NAME
