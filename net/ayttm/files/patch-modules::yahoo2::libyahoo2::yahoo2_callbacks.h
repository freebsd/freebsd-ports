--- modules/yahoo2/libyahoo2/yahoo2_callbacks.h.orig	Fri Jan 16 14:39:19 2004
+++ modules/yahoo2/libyahoo2/yahoo2_callbacks.h	Sun Feb  8 01:03:04 2004
@@ -629,9 +629,10 @@
  * Name: ext_yahoo_remove_handler
  * 	Remove the listener for the fd.
  * Params:
+ * 	id   - the id that identifies the connection
  * 	tag  - the handler tag to remove
  */
-void YAHOO_CALLBACK_TYPE(ext_yahoo_remove_handler)(int tag);
+void YAHOO_CALLBACK_TYPE(ext_yahoo_remove_handler)(int id, int tag);
 
 
 
