--- setup.py.orig	2022-06-11 05:51:46 UTC
+++ setup.py
@@ -27,23 +27,23 @@ if py_version < (3, 7):
 VERSION_FILE = os.path.join("errbot", "version.py")
 
 deps = [
-    "webtest==3.0.0",
-    "setuptools==60.5.0",
-    "flask==2.0.2",
-    "requests==2.27.1",
-    "jinja2==3.0.3",
-    "pyOpenSSL==21.0.0",
-    "colorlog==6.6.0",
-    "markdown==3.3.6",
-    "ansi==0.2.0",
-    "Pygments==2.11.2",
-    "pygments-markdown-lexer==0.1.0.dev39",  # sytax coloring to debug md
-    "dulwich==0.20.31",  # python implementation of git
-    "deepmerge==1.0.1",
+    "webtest>=2.0.32",
+    "setuptools>=60.5.0",
+    "flask>=2.0.2",
+    "requests>=2.27.1",
+    "jinja2>=3.0.1",
+    "pyOpenSSL>=21.0.0",
+    "colorlog>=6.6.0",
+    "markdown>=3.3.6",
+    "ansi>=0.2.0",
+    "Pygments>=2.9.0",
+    "pygments-markdown-lexer>=0.1.0.dev39",  # sytax coloring to debug md
+    "dulwich>=0.19.16",  # python implementation of git
+    "deepmerge>=1.0.1",
 ]
 
 if py_version < (3, 9):
-    deps.append("graphlib-backport==1.0.3")
+    deps.append("graphlib-backport>=1.0.3")
 
 src_root = os.curdir
 
@@ -112,23 +112,23 @@ if __name__ == "__main__":
         },
         extras_require={
             "IRC": [
-                "irc==20.0.0",
+                "irc>=20.0.0",
             ],
             "slack": [
-                "slackclient==1.3.2",
+                "slackclient>=1.3.2",
             ],
             "slack-rtm": [
-                "slackclient==2.9.3",
+                "slackclient>=2.9.3",
             ],
             "telegram": [
-                "python-telegram-bot==13.10",
+                "python-telegram-bot>=13.10",
             ],
             "XMPP": [
-                "slixmpp==1.7.1",
-                "pyasn1==0.4.8",
-                "pyasn1-modules==0.2.8",
+                "slixmpp>=1.7.1",
+                "pyasn1>=0.4.8",
+                "pyasn1-modules>=0.2.8",
             ],
-            ':sys_platform!="win32"': ["daemonize==2.5.0"],
+            ':sys_platform!="win32"': ["daemonize>=2.5.0"],
         },
         author="errbot.io",
         author_email="info@errbot.io",
