--- login.tcl.orig	Tue Aug  3 14:35:36 2004
+++ login.tcl	Tue Aug  3 14:35:54 2004
@@ -36,10 +36,10 @@
 custom::defvar loginconf(usedigest) 1 \
     [::msgcat::mc "Use hashed password transmission."] \
     -group Login -type boolean
-custom::defvar loginconf(resource) "tkabber" \
+custom::defvar loginconf(resource) "TKabber" \
     [::msgcat::mc "Resource."] \
     -group Login -type string
-custom::defvar loginconf(server) "localhost" \
+custom::defvar loginconf(server) "jabber.ru" \
     [::msgcat::mc "Server name."] \
     -group Login -type string
 custom::defvar loginconf(port) "5222" \
