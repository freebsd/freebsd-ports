diff --unified --recursive silc-client-0.9.10.1/irssi/src/silc/core/client_ops.c silc-client-0.9.10.1.db/irssi/src/silc/core/client_ops.c
--- irssi/src/silc/core/client_ops.c.orig	Thu Dec  5 15:37:49 2002
+++ irssi/src/silc/core/client_ops.c	Tue Sep  9 18:41:57 2003
@@ -312,9 +312,26 @@
   /* FIXME: replace those printformat calls with signals and add signature
             information to them (if present) */
   if (flags & SILC_MESSAGE_FLAG_ACTION)
-    printformat_module("fe-common/silc", server, channel->channel_name,
-		       MSGLEVEL_ACTIONS, SILCTXT_CHANNEL_ACTION, 
-                       nick == NULL ? "[<unknown>]" : nick->nick, message);
+    if(flags & SILC_MESSAGE_FLAG_UTF8 && !silc_term_utf8()) {
+      char tmp[256], *cp, *dm = NULL;
+      memset(tmp, 0, sizeof(tmp));
+      cp = tmp;
+      if(message_len > sizeof(tmp) - 1) {
+        dm = silc_calloc(message_len + 1, sizeof(*dm));
+        cp = dm;
+      }
+      silc_utf8_decode(message, message_len, SILC_STRING_LANGUAGE,
+                       cp, message_len);
+      printformat_module("fe-common/silc", server, channel->channel_name,
+                         MSGLEVEL_ACTIONS, SILCTXT_CHANNEL_ACTION,
+                         nick == NULL ? "[<unknown>]" : nick->nick, cp);
+      silc_free(dm);
+    } else {
+      printformat_module("fe-common/silc", server, channel->channel_name,
+                         MSGLEVEL_ACTIONS, SILCTXT_CHANNEL_ACTION,
+                         nick == NULL ? "[<unknown>]" : nick->nick,
+                         message);
+    }
   else if (flags & SILC_MESSAGE_FLAG_NOTICE)
     printformat_module("fe-common/silc", server, channel->channel_name,
 		       MSGLEVEL_NOTICES, SILCTXT_CHANNEL_NOTICE, 
