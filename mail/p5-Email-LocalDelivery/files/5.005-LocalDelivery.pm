--- LocalDelivery.pm.orig	Tue Jun  1 20:04:19 2004
+++ LocalDelivery.pm	Tue Jun  1 20:05:12 2004
@@ -1,12 +1,10 @@
 package Email::LocalDelivery;
 
-require 5.005_62;
 use strict;
-use warnings;
 use File::Path::Expand qw(expand_filename);
 use Email::FolderType qw(folder_type);
 use Carp;
-our $VERSION = '0.08';
+use vars qw($VERSION); $VERSION = '0.08';
 
 =head1 NAME
 
