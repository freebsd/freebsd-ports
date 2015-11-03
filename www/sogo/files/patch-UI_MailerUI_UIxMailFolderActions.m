--- UI/MailerUI/UIxMailFolderActions.m.orig	2015-09-16 18:41:36 UTC
+++ UI/MailerUI/UIxMailFolderActions.m
@@ -383,7 +383,7 @@
 - (WOResponse *) moveMessagesAction
 {
   SOGoMailFolder *co;
-  SOGoUserSettings *us;
+  SOGoUserSettings *us=nil;
   WOResponse *response;
   NSArray *uids;
   NSString *value, *destinationFolder;
