--- extconf.rb.orig	Mon Dec 20 21:35:54 2004
+++ extconf.rb	Mon Dec 20 21:36:21 2004
@@ -1,5 +1,5 @@
 require 'mkmf'
 
-if have_library('gpgme', 'gpgme_check_version') and have_header('gpgme.h')
+if have_library('gpgme03', 'gpgme_check_version') and have_header('gpgme03/gpgme.h')
   create_makefile ('gpgme_n')
 end
