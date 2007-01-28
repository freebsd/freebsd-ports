--- src/out_xml_event.c.orig	Tue Apr  5 17:01:33 2005
+++ src/out_xml_event.c	Sun Jan 28 14:28:18 2007
@@ -127,7 +127,7 @@
 	.om_draw = xml_event_draw,
 	.om_set_opts = xml_event_set_opts,
 	.om_probe = xml_event_probe,
-	.om_shutdown xml_event_shutdown,
+	.om_shutdown = xml_event_shutdown,
 };
 
 static void __init xml_event_init(void)
