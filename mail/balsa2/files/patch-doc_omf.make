--- doc/omf.make.orig	Mon Sep 16 02:46:07 2002
+++ doc/omf.make	Mon Sep 16 02:46:37 2002
@@ -27,7 +27,7 @@
 #
 
 omf_dest_dir=$(datadir)/omf/@PACKAGE@
-scrollkeeper_localstate_dir = $(localstatedir)/scrollkeeper
+scrollkeeper_localstate_dir = /var/db/scrollkeeper
 
 omf: omf_timestamp
 
