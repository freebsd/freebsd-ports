--- src/CommandSystem.cc.orig	2008-02-05 14:17:58.000000000 +0100
+++ src/CommandSystem.cc	2008-04-29 13:29:39.000000000 +0200
@@ -120,8 +120,8 @@
 {
 	se_debug(SE_DEBUG_COMMAND);
 
-	std::list<Command*>::const_reverse_iterator it;
-	for(it = m_stack.rbegin(); it!= m_stack.rend(); ++it)
+	std::list<Command*>::const_iterator it;
+	for(it = m_stack.begin(); it!= m_stack.end(); ++it)
 	{
 		(*it)->restore();
 	}
