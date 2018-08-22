--- Telegram/SourceFiles/core/utils.h.orig	2018-08-04 18:53:40 UTC
+++ Telegram/SourceFiles/core/utils.h
@@ -433,6 +433,7 @@ enum DBIPlatform {
 	dbipLinux64 = 2,
 	dbipLinux32 = 3,
 	dbipMacOld = 4,
+	dbipFreeBSD = 5,
 };
 
 enum DBIPeerReportSpamStatus {
