--- extconf.rb.orig	Sun Dec  8 07:55:26 2002
+++ extconf.rb	Fri Aug  5 19:50:43 2005
@@ -23,7 +23,7 @@
 dir_config('xml2')
 
 
-unless have_library('m', 'atan')
+unless have_library('m', 'atan', 'math.h')
   crash('need libm')
 end
 
