--- login.tcl.orig      Tue Oct 31 13:08:19 2006
+++ login.tcl   Tue Oct 31 13:08:45 2006
@@ -46,13 +46,13 @@
 custom::defvar loginconf(user) "" \
     [::msgcat::mc "User name."] \
     -group Login -type string
-custom::defvar loginconf(server) "localhost" \
+custom::defvar loginconf(server) "jabber.ru" \
     [::msgcat::mc "Server name."] \
     -group Login -type string
 custom::defvar loginconf(password) "" \
     [::msgcat::mc "Password."] \
     -group Login -type password
-custom::defvar loginconf(resource) "tkabber" \
+custom::defvar loginconf(resource) "TKabber" \
     [::msgcat::mc "Resource."] \
     -group Login -type string
 custom::defvar loginconf(priority) "8" \
