--- setup.py.org	2012-06-22 15:50:45.283520178 +0900
+++ setup.py	2012-06-22 15:51:13.184520094 +0900
@@ -41,7 +41,7 @@
 else:
 	setup(
 		name = "reposado",
-		version = "git",
+		version = "%%PORTVERSION%%",
 		author = "Greg Neagle",
 		author_email = "reposado@googlegroups.com",
 		maintainer = "Brent B",
