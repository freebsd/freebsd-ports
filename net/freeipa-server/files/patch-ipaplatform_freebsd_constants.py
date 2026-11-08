--- ipaplatform/freebsd/constants.py.orig	2026-06-30 21:34:05 UTC
+++ ipaplatform/freebsd/constants.py
@@ -0,0 +1,23 @@
+#
+# Copyright (C) 2026 FreeIPA Contributors see COPYING for license
+#
+
+from ipaplatform.base.constants import BaseConstantsNamespace, Group, User
+
+__all__ = ("constants", "User", "Group")
+
+
+class FreeBSDConstantsNamespace(BaseConstantsNamespace):
+    HTTPD_USER = User("www")
+    HTTPD_GROUP = Group("www")
+    # httpd runs with GSS_USE_PROXY=no (see tasks.py), so httpd itself
+    # reads the HTTP keytab rather than gssproxy.  Leaving it owned by
+    # root deprives mod_auth_gssapi of its server credentials.
+    GSSPROXY_USER = User("www")
+    NAMED_USER = User("bind")
+    NAMED_GROUP = Group("bind")
+    ODS_USER = User("opendnssec")
+    ODS_GROUP = Group("opendnssec")
+
+
+constants = FreeBSDConstantsNamespace()
