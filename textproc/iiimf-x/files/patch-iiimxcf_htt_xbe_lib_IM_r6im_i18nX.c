--- iiimxcf/htt_xbe/lib/IMdkit/r6im/i18nX.c	Fri Nov  1 09:15:38 2002
+++ iiimxcf/htt_xbe/lib/IMdkit/r6im/i18nX.c	Wed Feb 16 19:33:10 2005
@@ -389,8 +389,8 @@
     extern void _Xi18nMessageHandler(XIMS, CARD16,
 				     unsigned char*, Bool*);
     Bool delete = True;
-    unsigned char *packet;
-    int connect_id;
+    unsigned char *packet = NULL;
+    int connect_id = 0;
 
     if (((XClientMessageEvent *)ev)->message_type ==
 	spec->xim_request) {
