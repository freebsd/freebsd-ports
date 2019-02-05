--- Telegram/SourceFiles/core/utils.h.orig	2019-02-01 12:51:46 UTC
+++ Telegram/SourceFiles/core/utils.h
@@ -350,6 +350,7 @@ enum DBIPlatform {
 	dbipLinux64 = 2,
 	dbipLinux32 = 3,
 	dbipMacOld = 4,
+	dbipFreeBSD = 5,
 };
 
 enum DBIPeerReportSpamStatus {
