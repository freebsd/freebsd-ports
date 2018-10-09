--- Telegram/SourceFiles/core/utils.h.orig	2018-09-28 13:08:38 UTC
+++ Telegram/SourceFiles/core/utils.h
@@ -411,6 +411,7 @@ enum DBIPlatform {
 	dbipLinux64 = 2,
 	dbipLinux32 = 3,
 	dbipMacOld = 4,
+	dbipFreeBSD = 5,
 };
 
 enum DBIPeerReportSpamStatus {
