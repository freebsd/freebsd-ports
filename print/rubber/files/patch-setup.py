--- setup.py.orig	Sun Oct  5 22:08:57 2003
+++ setup.py	Sun Oct  5 22:09:39 2003
@@ -135,8 +135,8 @@
 		package_dir = {"rubber": "src"},
 		scripts = ["rubber", "rubber-info"],
 		data_files =
-		[(mandir + "/man1", ["man/en/rubber.1", "man/en/rubber-info.1"]),
-		 (mandir + "/fr/man1", ["man/fr/rubber.1", "man/fr/rubber-info.1"])]
+		[(mandir + "/man1", ["man/en/rubber.1", "man/en/rubber-info.1"])
+		]
 		)
 
 
