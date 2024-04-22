--- setup.py.orig	2024-01-01 22:29:55 UTC
+++ setup.py
@@ -27,23 +27,23 @@ if py_version < (3, 8):
 VERSION_FILE = os.path.join("errbot", "version.py")
 
 deps = [
-    "webtest==3.0.0",
-    "setuptools==68.1.2",
-    "flask==2.3.3",
-    "requests==2.31.0",
-    "jinja2==3.1.2",
-    "pyOpenSSL==23.2.0",
-    "colorlog==6.7.0",
-    "markdown==3.4.4",
-    "ansi==0.3.6",
-    "Pygments==2.16.1",
-    "pygments-markdown-lexer==0.1.0.dev39",  # sytax coloring to debug md
-    "dulwich==0.21.5",  # python implementation of git
-    "deepmerge==1.1.0",
+    "webtest>=3.0.0",
+    "setuptools>=61",
+    "flask>=2.3.3",
+    "requests>=2.31.0",
+    "jinja2>=3.1.2",
+    "pyOpenSSL>=23.2.0",
+    "colorlog>=6.7.0",
+    "markdown>=3.4.4",
+    "ansi>=0.3.6",
+    "Pygments>=2.16.1",
+    "pygments-markdown-lexer>=0.1.0.dev39",  # sytax coloring to debug md
+    "dulwich>=0.21.2",  # python implementation of git
+    "deepmerge>=1.1.0",
 ]
 
 if py_version < (3, 9):
-    deps.append("graphlib-backport==1.0.3")
+    deps.append("graphlib-backport>=1.0.3")
 
 src_root = os.curdir
 
@@ -112,24 +112,24 @@ if __name__ == "__main__":
         },
         extras_require={
             "slack": [
-                "errbot-backend-slackv3==0.2.1",
+                "errbot-backend-slackv3>=0.2.1",
             ],
             "discord": [
-                "err-backend-discord==3.0.1",
+                "err-backend-discord>=3.0.1",
             ],
             "mattermost": [
-                "err-backend-mattermost==3.0.0",
+                "err-backend-mattermost>=3.0.0",
             ],
             "IRC": [
-                "irc==20.3.0",
+                "irc>=20.3.0",
             ],
             "telegram": [
-                "python-telegram-bot==13.15",
+                "python-telegram-bot>=13.15",
             ],
             "XMPP": [
-                "slixmpp==1.8.4",
-                "pyasn1==0.5.0",
-                "pyasn1-modules==0.3.0",
+                "slixmpp>=1.8.4",
+                "pyasn1>=0.5.0",
+                "pyasn1-modules>=0.3.0",
             ],
             ':sys_platform!="win32"': ["daemonize==2.5.0"],
         },
