--- ./setup.sh.orig	Wed Sep 27 21:23:59 2006
+++ ./setup.sh	Wed Sep 27 21:24:43 2006
@@ -33,7 +33,7 @@
 pb=$(realpath $(dirname $pb))
 pb=${pb%%/scripts}
 
-MAN_PREREQS="lang/perl5.8 net/p5-Net security/p5-Digest-MD5"
+MAN_PREREQS="lang/perl5.8"
 OPT_PREREQS="lang/php[45] databases/pear-DB www/php[45]-session"
 PREF_FILES="rawenv tinderbox.ph"
 README="${pb}/scripts/README"
