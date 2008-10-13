--- lib/platform/CXWindowsClipboard.h.orig	2008-10-06 14:51:40.000000000 +0800
+++ lib/platform/CXWindowsClipboard.h	2008-10-06 14:52:33.000000000 +0800
@@ -265,7 +265,7 @@
 	bool				insertMultipleReply(Window, ::Time, Atom);
 	void				insertReply(CReply*);
 	void				pushReplies();
-	void				pushReplies(CReplyMap::iterator,
+	void				pushReplies(Window requestor,
 							CReplyList&, CReplyList::iterator);
 	bool				sendReply(CReply*);
 	void				clearReplies();
