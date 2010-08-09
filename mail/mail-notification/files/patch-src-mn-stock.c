diff -Nrbu src/mn-stock.c.orig src/mn-stock.c
--- src/mn-stock.c.orig	2008-05-22 19:45:35.000000000 +0400
+++ src/mn-stock.c	2010-05-24 19:36:03.000000000 +0400
@@ -32,11 +32,11 @@
     const char	*icon_name;
     const char	*source_stock_id;
   } icons[] = {
-    { MN_STOCK_MAIL,			NULL, "stock_mail" },
-    { MN_STOCK_NO_MAIL,			NULL, "stock_inbox" },
-    { MN_STOCK_LOCAL,			NULL, "stock_folder" },
-    { MN_STOCK_REMOTE,			NULL, "stock_internet" },
-    { MN_STOCK_UNKNOWN,			NULL, "stock_unknown" },
+    { MN_STOCK_MAIL,			NULL, "mail-message-new" },
+    { MN_STOCK_NO_MAIL,			NULL, "mail-notification" },
+    { MN_STOCK_LOCAL,			NULL, "folder" },
+    { MN_STOCK_REMOTE,			NULL, "applications-internet" },
+    { MN_STOCK_UNKNOWN,			NULL, "dialog-question" },
     { MN_STOCK_ERROR,			NULL, NULL, GTK_STOCK_DIALOG_ERROR },
 #if WITH_GMAIL
     { MN_STOCK_GMAIL,			PKGDATADIR G_DIR_SEPARATOR_S "gmail.png" },
@@ -48,14 +48,14 @@
     { MN_STOCK_HOTMAIL,			PKGDATADIR G_DIR_SEPARATOR_S "hotmail.png" },
 #endif
 #if WITH_MBOX || WITH_MOZILLA || WITH_MH || WITH_MAILDIR || WITH_SYLPHEED
-    { MN_STOCK_SYSTEM_MAILBOX,		NULL, "system" },
+    { MN_STOCK_SYSTEM_MAILBOX,		NULL, "applications-system" },
 #endif
 #if WITH_EVOLUTION
     { MN_STOCK_EVOLUTION_MAILBOX,	NULL, "evolution" },
 #endif
-    { MN_STOCK_MAIL_READER,		NULL, "stock_mail-handling" },
-    { MN_STOCK_OPEN_MESSAGE,		NULL, "stock_mail-open" },
-    { MN_STOCK_CONSIDER_NEW_MAIL_AS_READ, NULL, "stock_mark" }
+    { MN_STOCK_MAIL_READER,		NULL, "mail-unread" },
+    { MN_STOCK_OPEN_MESSAGE,		NULL, "mail-read" },
+    { MN_STOCK_CONSIDER_NEW_MAIL_AS_READ, NULL, "mail-mark-read" }
   };
   GtkIconFactory *factory;
   GtkIconTheme *icon_theme;
