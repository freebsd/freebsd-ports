--- ./contrib/olsr/face_manager.cc.orig	2011-07-25 17:55:36.000000000 +0000
+++ ./contrib/olsr/face_manager.cc	2014-02-26 21:17:13.000000000 +0000
@@ -239,8 +239,11 @@
 
 	// Walk the list of message handler functions in reverse,
 	// looking for one which is willing to consume this message.
-	vector<MessageReceiveCB>::reverse_iterator jj;
-	for (jj = _handlers.rbegin(); jj != _handlers.rend(); jj++) {
+	// vector<MessageReceiveCB>::reverse_iterator jj;
+	vector<MessageReceiveCB>::iterator jj;
+	if (! _handlers.empty())
+	// for (jj = _handlers.rbegin(); jj != _handlers.rend(); jj++) {
+	for (jj = _handlers.end(); jj-- != _handlers.begin(); ) {
 	    try {
 		is_consumed = (*jj)->dispatch(msg, src, face->local_addr());
 		if (is_consumed)
