--- Makefile.PL_orig	Sun Aug 11 13:52:36 2002
+++ Makefile.PL	Sun Aug 11 13:57:36 2002
@@ -789,17 +796,17 @@
 WriteMakefile(
 	NAME     => "Interchange",
 	MAN3PODS => {
-					'pod/ic_ecommerce.pod'	=> 'blib/man3/ic_ecommerce.8',
-					'pod/ic_howto_cvs.pod'	=> 'blib/man3/ic_howto_cvs.8',
-					'pod/icadvanced.pod'	=> 'blib/man3/icadvanced.8',
-					'pod/iccattut.pod'		=> 'blib/man3/iccattut.8',
-					'pod/icconfig.pod'		=> 'blib/man3/icconfig.8',
-					'pod/icdatabase.pod'	=> 'blib/man3/icdatabase.8',
-					'pod/icfaq.pod'			=> 'blib/man3/icfaq.8',
-					'pod/icfoundation.pod'	=> 'blib/man3/icfoundation.8',
-					'pod/ictags.pod'		=> 'blib/man3/ictags.8',
-					'pod/ictemplates.pod'	=> 'blib/man3/ictemplates.8',
-					'pod/icupgrade.pod'		=> 'blib/man3/icupgrade.8',
+					'pod/ic_ecommerce.pod'	=> 'blib/man3/ic_ecommerce.7',
+					'pod/ic_howto_cvs.pod'	=> 'blib/man3/ic_howto_cvs.7',
+					'pod/icadvanced.pod'	=> 'blib/man3/icadvanced.7',
+					'pod/iccattut.pod'		=> 'blib/man3/iccattut.7',
+					'pod/icconfig.pod'		=> 'blib/man3/icconfig.7',
+					'pod/icdatabase.pod'	=> 'blib/man3/icdatabase.7',
+					'pod/icfaq.pod'			=> 'blib/man3/icfaq.7',
+					'pod/icfoundation.pod'	=> 'blib/man3/icfoundation.7',
+					'pod/ictags.pod'		=> 'blib/man3/ictags.7',
+					'pod/ictemplates.pod'	=> 'blib/man3/ictemplates.7',
+					'pod/icupgrade.pod'		=> 'blib/man3/icupgrade.7',
 					},
 	DISTNAME => "interchange",
 	clean    => {
