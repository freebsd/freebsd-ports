--- src/ui/app/routes/profile.py.orig	2026-09-21 08:05:39 UTC
+++ src/ui/app/routes/profile.py
@@ -5,6 +5,21 @@
 from flask_login import current_user, login_required
 from user_agents import parse
 
+
+# devel/py-user_agents is still at 1.0.1, which lacks the get_browser(),
+# get_os() and get_device() helpers added in 2.1.  Build the same strings
+# from the attributes 1.0.1 already provides.
+def _ua_browser(ua):
+    return ("%s %s" % (ua.browser.family, ua.browser.version_string)).strip()
+
+
+def _ua_os(ua):
+    return ("%s %s" % (ua.os.family, ua.os.version_string)).strip()
+
+
+def _ua_device(ua):
+    return "PC" if ua.is_pc else ua.device.family
+
 from app.models.totp import totp as TOTP
 
 from app.dependencies import DB
@@ -51,9 +66,9 @@
                 "current": (
                     db_session.get("id") == session.get("session_id") if isinstance(db_session, dict) and "session_id" in session else "id" not in db_session
                 ),
-                "browser": ua_data.get_browser(),
-                "os": ua_data.get_os(),
-                "device": ua_data.get_device(),
+                "browser": _ua_browser(ua_data),
+                "os": _ua_os(ua_data),
+                "device": _ua_device(ua_data),
                 "ip": (db_session.get("ip") if isinstance(db_session, dict) else session.get("ip", "-")) or "-",
                 "creation_date": _fmt_dt(creation_dt),
                 "last_activity": (
