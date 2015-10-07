--- libxorp/ref_trie.hh.orig	2015-09-12 03:45:51.752442000 +0900
+++ libxorp/ref_trie.hh	2015-09-12 03:48:56.187304000 +0900
@@ -1336,10 +1336,6 @@
 #ifdef DEBUG_LOGGING
     debug_msg_indent(indent);
 
-    if (this == NULL) {
-	debug_msg("%sNULL\n", msg);
-	return;
-    }
     debug_msg("%skey: %s %s\n",
 	      msg, _k.str().c_str(), _p ? "PL" : "[]");
     debug_msg("    U: %s\n", _up ? _up->_k.str().c_str() : "NULL");
@@ -1356,10 +1352,7 @@
 RefTrieNode<A, Payload>::str() const
 {
     string s;
-    if (this == NULL) {
-	s = "NULL";
-	return s;
-    }
+
     s = c_format("key: %s ", _k.str().c_str());
     if (_p)
 	s += "PL";
