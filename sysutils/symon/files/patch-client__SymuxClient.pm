--- ./client/SymuxClient.pm.orig	2014-09-20 01:14:36.791963224 +0400
+++ ./client/SymuxClient.pm	2014-09-20 01:14:52.651148220 +0400
@@ -267,6 +267,8 @@
 
 =head2 METHODS
 
+=over 4
+
 =item getitem (host, stream, item)
 
 Refresh the measured data and get an item from a stream for a particular
@@ -304,4 +306,6 @@
     # which hosts packets_out was that?
     print $sc->getsource();
 
+=back
+
 =cut
