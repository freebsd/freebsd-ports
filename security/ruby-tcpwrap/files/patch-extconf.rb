--- extconf.rb.orig	Thu Apr 19 11:17:19 2001
+++ extconf.rb	Fri Jan 24 03:42:50 2003
@@ -9,7 +9,7 @@
   have_func("ident_id")
 end
 if have_header("tcpd.h") and
-    have_library("wrap", nil)
+    have_library("wrap")
   have_func("hsterror")
   create_makefile("tcpwrap")
 end
