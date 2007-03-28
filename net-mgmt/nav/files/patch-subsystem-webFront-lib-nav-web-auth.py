--- subsystem/webFront/lib/nav/web/auth.py.orig	Tue Mar 13 11:59:25 2007
+++ subsystem/webFront/lib/nav/web/auth.py	Wed Mar 14 12:09:35 2007
@@ -30,6 +30,7 @@
 import nav
 import logging
 
+from nav import auth
 from nav import db
 from nav.db import navprofiles
 from nav.web.preferences import Preferences, Link
