--- Telegram/SourceFiles/core/utils.h.orig	2018-12-24 08:16:05 UTC
+++ Telegram/SourceFiles/core/utils.h
@@ -378,6 +378,7 @@ enum DBIPlatform {
 	dbipLinux64 = 2,
 	dbipLinux32 = 3,
 	dbipMacOld = 4,
+	dbipFreeBSD = 5,
 };
 
 enum DBIPeerReportSpamStatus {
