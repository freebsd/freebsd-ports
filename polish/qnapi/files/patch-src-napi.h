--- src/napi.h.orig	2010-11-27 12:39:09.000000000 +0100
+++ src/napi.h	2010-11-27 12:40:06.000000000 +0100
@@ -67,7 +67,7 @@
 
 bool napiMatchSubtitles(const QString & md5sum, const QString & zip_file, const QString & movie_file,
 						bool noBackup = false, const QString & tmp_path = "/tmp",
-						const QString & p7zip_path = "/usr/bin/7z");
+						const QString & p7zip_path = "@LOCALBASE@/bin/7z");
 
 bool napiCheckUser(const QString & nick, const QString & pass);
 
@@ -76,7 +76,7 @@
 										const QString & pass, bool correct = false,
 										const QString & comment = "",
 										const QString & tmp_path = "/tmp",
-										const QString & p7zip_path = "/usr/bin/7z");
+										const QString & p7zip_path = "@LOCALBASE@/bin/7z");
 
 napiReportResult napiReportBad(const QString & movie_file, const QString & language,
 								const QString & nick, const QString & pass, const QString & comment,
