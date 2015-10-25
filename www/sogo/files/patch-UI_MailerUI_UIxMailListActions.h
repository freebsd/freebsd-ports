--- UI/MailerUI/UIxMailListActions.h.orig	2015-09-16 18:41:36 UTC
+++ UI/MailerUI/UIxMailListActions.h
@@ -43,7 +43,6 @@
 }
 
 - (NSString *) defaultSortKey;
-- (NSString *) imap4SortKey;
 - (NSString *) imap4SortOrdering;
 - (EOQualifier *) searchQualifier;
 - (NSString *) msgLabels;
