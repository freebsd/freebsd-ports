--- src/protocols/yahoo/yahoo.c.orig	Sat Dec  7 12:54:15 2002
+++ src/protocols/yahoo/yahoo.c	Mon Jan  6 18:48:24 2003
@@ -87,6 +87,8 @@
 #define USEROPT_PAGERPORT 4
 #define YAHOO_PAGER_PORT 5050
 
+#define YAHOO_PROTO_VER 0x0900
+
 enum yahoo_service { /* these are easier to see in hex */
 	YAHOO_SERVICE_LOGON = 1,
 	YAHOO_SERVICE_LOGOFF,
@@ -352,7 +354,7 @@
 	data = g_malloc0(len + 1);
 
 	memcpy(data + pos, "YMSG", 4); pos += 4;
-	pos += yahoo_put16(data + pos, 0x0600);
+	pos += yahoo_put16(data + pos, YAHOO_PROTO_VER);
 	pos += yahoo_put16(data + pos, 0x0000);
 	pos += yahoo_put16(data + pos, pktlen);
 	pos += yahoo_put16(data + pos, pkt->service);
