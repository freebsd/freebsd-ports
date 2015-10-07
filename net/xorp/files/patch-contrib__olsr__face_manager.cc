--- contrib/olsr/face_manager.cc.orig	2012-01-11 17:56:10 UTC
+++ contrib/olsr/face_manager.cc
@@ -239,8 +239,11 @@ FaceManager::receive(const string& inter
 
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
