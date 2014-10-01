--- lib/Smokeping.pm.orig	2014-09-12 08:24:07.080901489 +0000
+++ lib/Smokeping.pm	2014-09-12 08:24:45.049898644 +0000
@@ -2631,7 +2631,7 @@
 The base directory where SmokePing keeps the files related to the DYNAMIC function.
 This directory must be writeable by the WWW server. It is also used for temporary
 storage of slave polling results by the master in 
-L<the master/slave mode|smokeping_master_slave>.
+L<the masterE<sol>slave mode|smokeping_master_slave>.
 
 If this variable is not specified, the value of C<datadir> will be used instead.
 DOC
