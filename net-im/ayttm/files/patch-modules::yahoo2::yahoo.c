--- modules/yahoo2/yahoo.c.orig	Mon Jan 12 18:42:12 2004
+++ modules/yahoo2/yahoo.c	Sun Feb  8 00:33:04 2004
@@ -136,8 +136,8 @@
 	PLUGIN_SERVICE,
 	"Yahoo",
 	"Provides Yahoo Instant Messenger support",
-	"$Revision: 1.89 $",
-	"$Date: 2004/01/07 05:28:44 $",
+	"$Revision: 1.90 $",
+	"$Date: 2004/01/29 05:13:14 $",
 	&ref_count,
 	plugin_init,
 	plugin_finish,
@@ -3215,7 +3215,7 @@
 	return d->tag;
 }
 
-static void ext_yahoo_remove_handler(int tag)
+static void ext_yahoo_remove_handler(int id, int tag)
 {
 	YList * l;
 	for(l = handlers; l; l = l->next)
