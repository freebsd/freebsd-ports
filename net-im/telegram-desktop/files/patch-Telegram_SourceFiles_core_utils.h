--- Telegram/SourceFiles/core/utils.h.orig	2018-04-08 17:34:33 UTC
+++ Telegram/SourceFiles/core/utils.h
@@ -451,6 +451,7 @@ enum DBIPlatform {
 	dbipLinux64 = 2,
 	dbipLinux32 = 3,
 	dbipMacOld = 4,
+	dbipFreeBSD = 5,
 };
 
 enum DBIPeerReportSpamStatus {
