--- Makefile.PL.orig	Sun Aug 20 20:37:18 2000
+++ Makefile.PL	Thu Mar  1 17:42:51 2001
@@ -7,7 +7,6 @@
 
 WriteMakefile (
                  NAME      =>   "CGI::Lite",
-                 MAN3PODS  =>   ' ',  
                  VERSION   =>   "$VERSION",
                  'dist'    =>   {
 				    COMPRESS => 'gzip -9f', 
