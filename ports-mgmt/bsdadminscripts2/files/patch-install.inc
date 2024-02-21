--- install.inc.orig	2023-10-08 11:09:04 UTC
+++ install.inc
@@ -91,7 +91,7 @@ replace="
 %%PREFIX%%,$prefix
 %%DATADIR%%,$datadir
 %%DOCSDIR%%,$docsdir
-%%MAN%%,$prefix/man
+%%MAN%%,$prefix/share/man
 %%TMP%%,$tmp
 %%PORTS%%,$ports
 "
