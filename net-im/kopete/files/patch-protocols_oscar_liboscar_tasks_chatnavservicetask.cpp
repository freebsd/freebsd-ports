--- protocols/oscar/liboscar/tasks/chatnavservicetask.cpp.orig	2018-03-31 17:20:06 UTC
+++ protocols/oscar/liboscar/tasks/chatnavservicetask.cpp
@@ -103,7 +103,7 @@ bool ChatNavServiceTask::take( Transfer* transfer )
 void ChatNavServiceTask::onGo()
 {
     FLAP f =  { 0x02, 0, 0x00 };
-    SNAC s = { 0x000D, m_type, 0x0000, client()->snacSequence() };
+    SNAC s = { 0x000D, static_cast<WORD>(m_type), 0x0000, client()->snacSequence() };
     Buffer* b = new Buffer();
 
     Transfer* t = createTransfer( f, s, b );
