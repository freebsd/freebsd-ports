--- kxicq/engine/kxengine.cpp.orig	Sat Jun 22 21:27:40 2002
+++ kxicq/engine/kxengine.cpp	Sat Jun 22 21:40:27 2002
@@ -718,7 +718,7 @@
 {
 	if (AIM) AIM->setKeepAlive(send);
 }
-void kxEngine::setUseServerList(bool s=TRUE)
+void kxEngine::setUseServerList(bool s)
 {
 saveContactsOnServer=s;
 if (AIM) AIM->setUseServerList(s);
