--- panel-plugin/mailwatch-mailbox-gmail.c.orig	Thu Apr 20 11:24:36 2006
+++ panel-plugin/mailwatch-mailbox-gmail.c	Sat Jan 27 11:15:51 2007
@@ -159,10 +159,16 @@
 gmail_get_sockaddr(XfceMailwatchGMailMailbox *gmailbox, const gchar *host,
                   const gchar *service, struct sockaddr_in *addr)
 {
-    struct addrinfo hints = { 0, PF_INET, SOCK_STREAM, IPPROTO_TCP,
-            sizeof(struct sockaddr_in), NULL, NULL, NULL };
+    struct addrinfo hints;
     GError *error = NULL;
     
+    memset(&hints, 0, sizeof(hints));
+ 
+    hints.ai_flags = 0;
+    hints.ai_family = PF_INET;
+    hints.ai_socktype = SOCK_STREAM;
+    hints.ai_protocol = IPPROTO_TCP;
+
     TRACE("entering (%s, %s, %p)", host, service, addr);
     
     g_return_val_if_fail(host && service && addr, FALSE);
