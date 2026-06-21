--- iris/src/xmpp/xmpp-im/xmpp_caps.cpp.orig	2020-09-06 07:44:45 UTC
+++ iris/src/xmpp/xmpp-im/xmpp_caps.cpp
@@ -336,7 +336,8 @@ void CapsManager::updateDisco(const Jid &jid, const Di
 	if (!cs.isValid()) {
 		return;
 	}
-	if (item.capsHash(cs.hashAlgorithm()) == cs.version()) {
+	auto algo = cs.hashAlgorithm();
+	if (algo && item.capsHash(*algo) == cs.version()) {
 		CapsRegistry::instance()->registerCaps(cs, item);
 	}
 }
