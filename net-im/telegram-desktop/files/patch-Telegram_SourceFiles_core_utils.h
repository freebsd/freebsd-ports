--- Telegram/SourceFiles/core/utils.h.orig	2019-04-13 06:46:58 UTC
+++ Telegram/SourceFiles/core/utils.h
@@ -347,6 +347,7 @@ enum DBIPlatform {
 	dbipLinux64 = 2,
 	dbipLinux32 = 3,
 	dbipMacOld = 4,
+	dbipFreeBSD = 5,
 };
 
 enum DBIPeerReportSpamStatus {
