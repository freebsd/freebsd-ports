--- lib/platform/CXWindowsClipboard.cpp.orig	2006-04-02 09:47:03.000000000 +0800
+++ lib/platform/CXWindowsClipboard.cpp	2008-10-06 15:52:39.000000000 +0800
@@ -219,7 +219,7 @@
 		if (reply->m_replied && reply->m_property == property) {
 			// if reply is complete then remove it and start the
 			// next one.
-			pushReplies(index, replies, index2);
+			pushReplies(index->first, replies, index2);
 			return true;
 		}
 	}
@@ -928,17 +928,23 @@
 {
 	// send the first reply for each window if that reply hasn't
 	// been sent yet.
-	for (CReplyMap::iterator index = m_replies.begin();
-								index != m_replies.end(); ++index) {
-		assert(!index->second.empty());
-		if (!index->second.front()->m_replied) {
-			pushReplies(index, index->second, index->second.begin());
+	CReplyMap::iterator index = m_replies.begin();
+	while (index != m_replies.end()) {
+		// increment index before calling pushReplies(...) as
+		// pushReplies(...) normally erases the member of the map, that
+		// index points to, invalidating index as iterator.
+		Window requestor = index->first;
+		CReplyList& replies = index->second;
+		index++;
+		assert(!replies.empty());
+		if (!replies.front()->m_replied) {
+			pushReplies(requestor, replies, replies.begin());
 		}
 	}
 }
 
 void
-CXWindowsClipboard::pushReplies(CReplyMap::iterator mapIndex,
+CXWindowsClipboard::pushReplies(Window requestor,
 				CReplyList& replies, CReplyList::iterator index)
 {
 	CReply* reply = *index;
@@ -957,9 +963,8 @@
 	// and stop watching the requestor for events.
 	if (replies.empty()) {
 		CXWindowsUtil::CErrorLock lock(m_display);
-		Window requestor = mapIndex->first;
 		XSelectInput(m_display, requestor, m_eventMasks[requestor]);
-		m_replies.erase(mapIndex);
+		m_replies.erase(requestor);
 		m_eventMasks.erase(requestor);
 	}
 }
