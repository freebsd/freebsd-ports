--- extconf.rb.orig	Fri Apr 20 14:38:57 2001
+++ extconf.rb	Thu Jun 21 21:24:05 2001
@@ -6,8 +6,8 @@
 nis_h = have_header('rpcsvc/nis.h')
 ypclnt_h = have_header('rpcsvc/ypclnt.h')
 ypprot_h = have_header('rpcsvc/yp_prot.h')
-libnsl = have_library('nsl')
+have_library('nsl')
 
-if( libnsl && ypclnt_h && ypprot_h )
+if( have_func("yp_all") && ypclnt_h && ypprot_h )
   create_makefile('nis')
 end
