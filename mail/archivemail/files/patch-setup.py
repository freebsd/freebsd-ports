--- setup.py.orig	2019-04-14 08:03:17 UTC
+++ setup.py
@@ -29,5 +29,5 @@ setup(name="archivemail",
       maintainer="Nikolaus Schulz, Peter Poeml",
       maintainer_email="nikosch@users.sourceforge.net, poeml@users.sourceforge.net",
       scripts=["archivemail"],
-      data_files=[("share/man/man1", ["archivemail.1"])],
+      data_files=[("man/man1", ["archivemail.1"])],
       )
