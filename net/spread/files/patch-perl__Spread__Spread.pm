# This patch updates the included perl module to the latest version.
# Original Spread.pm plus included test script can be found here:
# https://cpan.metacpan.org/authors/id/J/JE/JESUS/Spread-3.17.4.4.tar.gz
===========================================================================
--- ./perl/Spread/Spread.pm.orig	2002-09-26 15:54:46.000000000 +0200
+++ ./perl/Spread/Spread.pm	2012-08-25 20:16:53.000000000 +0200
@@ -1,9 +1,8 @@
 # Filename: Spread.pm
 # Author:   Theo Schlossnagle <jesus@cnds.jhu.edu>
 # Created:  12th October 1999
-# Version:  1.03152
 #
-# Copyright (c) 1999-2001 Theo Schlossnagle. All rights reserved.
+# Copyright (c) 1999-2006,2008 Theo Schlossnagle. All rights reserved.
 #   This program is free software; you can redistribute it and/or
 #   modify it under the same terms as Perl itself.
 #
@@ -20,7 +19,7 @@
 use strict;
 use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS $AUTOLOAD);
 
-$VERSION = "3.17.0-1.04" ;
+$VERSION = "3.17.4.4" ;
 
 *SP_connect = \&Spread::connect;
 *SP_disconnect = \&Spread::disconnect;
@@ -52,7 +51,8 @@
 			     CAUSED_BY_LEAVE
 			     CAUSED_BY_DISCONNECT
 			     CAUSED_BY_NETWORK
-			     MEMBERSHIP_MESS) ],
+			     MEMBERSHIP_MESS
+			     REJECT_MESS) ],
 		ERROR => [ qw($sperrno
 			      ACCEPT_SESSION
 			      ILLEGAL_GROUP
@@ -71,7 +71,7 @@
 			      REJECT_QUOTA
 			      REJECT_VERSION) ],
 		SP => [ qw(SP_connect
-			   SP_disconnecct
+			   SP_disconnect
 			   SP_join
 			   SP_leave
 			   SP_receive
@@ -101,6 +101,7 @@
 	     CAUSED_BY_DISCONNECT
 	     CAUSED_BY_NETWORK
 	     MEMBERSHIP_MESS
+	     REJECT_MESS
 	     
 	     ACCEPT_SESSION
 	     ILLEGAL_GROUP
@@ -120,7 +121,7 @@
 	     REJECT_VERSION
 	     
 	     SP_connect
-	     SP_disconnecct
+	     SP_disconnect
 	     SP_join
 	     SP_leave
 	     SP_receive
@@ -165,8 +166,6 @@
 1;
 __END__
 
-# Below is the stub of documentation for your module. You better edit it!
-
 =head1 NAME
 
 Spread - Perl extension for the Spread group communication system
@@ -176,15 +175,21 @@
   use Spread;
 
   # Connect
-  my($mailbox, $private_group) = Spread::connect(
+  my($mbox, $private_group) = Spread::connect( {
 	spread_name => '4444@host.domain.com',
 	private_name => 'mrcool',
-	);
+	} );
+
+  # If you don't give a private name, you'll get a unique name from the spread daemon.
+  my($mailbox, $private_group) = Spread::connect(
+    spread_name => '4444@host.domain.com',
+  );
+
 
   # Join and leave groups
   my(@group_to_join) = ( 'GroupA', 'GroupB', 'GroupC' );
   my(@joined_groups) = grep( Spread::join($mbox, $_), @group_to_join );
-  print "Spread::join -- $sperrorno"
+  print "Spread::join -- $sperrno"
   	unless (Spread::leave($mbox, 'GroupC'));
 
   # Multicast to group(s)
@@ -204,7 +209,7 @@
 
   # Disconnect
   if(Spread::disconnect($mbox)) { print "Successful disconnect\n"; }
-  else { print "Spread::disconnect -- $sperrorno\n"; }
+  else { print "Spread::disconnect -- $sperrno\n"; }
 
 =head1 DESCRIPTION
 
@@ -213,8 +218,8 @@
 See man pages for SP_connect, SP_join, SP_multicast, SP_receive,
 SP_poll, SP_error, SP_leave, SP_disconnect.
 
-$sperror holds either the integer spread error or a descriptive string
-depending on the context in which $sperror is used.
+$sperrno holds either the integer spread error or a descriptive string
+depending on the context in which $sperrno is used.
 
 =head1 Exported constants
 
@@ -268,6 +273,7 @@
   REGULAR_MESS
   REG_MEMB_MESS
   REJECT_ILLEGAL_NAME
+  REJECT_MESS
   REJECT_NOT_UNIQUE
   REJECT_NO_NAME
   REJECT_QUOTA
