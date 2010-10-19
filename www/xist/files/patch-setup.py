--- setup.py.orig	2010-10-19 09:50:33.000000000 +0800
+++ setup.py	2010-10-19 09:50:51.000000000 +0800
@@ -283,7 +283,7 @@
 		"scripts/orafind.py",
 	],
 	install_requires=[
-		"cssutils == 0.9.5.1",
+		"cssutils >= 0.9.5.1",
 	],
 	extras_require = {
 		"oracle":  ["cx_Oracle >= 5.0.1"],
