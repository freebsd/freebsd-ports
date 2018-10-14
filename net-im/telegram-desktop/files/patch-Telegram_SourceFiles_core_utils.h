--- Telegram/SourceFiles/core/utils.h.orig	2018-10-09 21:21:48 UTC
+++ Telegram/SourceFiles/core/utils.h
@@ -406,6 +406,7 @@ enum DBIPlatform {
 	dbipLinux64 = 2,
 	dbipLinux32 = 3,
 	dbipMacOld = 4,
+	dbipFreeBSD = 5,
 };
 
 enum DBIPeerReportSpamStatus {
