--- install.inc.orig	2024-03-14 14:00:20 UTC
+++ install.inc
@@ -49,7 +49,7 @@ replace="
 
 replace="
 %%PREFIX%%,$prefix
-%%MAN%%,$prefix/man
+%%MAN%%,$prefix/share/man
 %%TMP%%,$tmp
 %%RUN%%,$run
 %%VARTMP%%,$vartmp
