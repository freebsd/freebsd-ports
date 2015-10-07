--- policy/configuration.hh.orig	2012-01-11 17:56:10 UTC
+++ policy/configuration.hh
@@ -43,11 +43,19 @@ typedef map<string, string> RESOURCES;
 
 // XXX we go reverse in order to make peer specific policies override global
 // ones.  Global is "" so it's always smallest (first).
+/*
 #define FOR_ALL_POLICIES(n) \
     for (PROTOCOL::reverse_iterator i = _protocols.rbegin(); \
 	 i != _protocols.rend(); ++i) \
 	for (POLICY::reverse_iterator n = i->second->rbegin(); \
 	    n != i->second->rend(); ++n)
+*/
+#define FOR_ALL_POLICIES(n) \
+    if (! _protocols.empty()) \
+    for (PROTOCOL::iterator i = _protocols.end(); \
+	i-- != _protocols.begin(); ) \
+	for (POLICY::iterator n = i->second->end(); \
+	    (! i->second->empty()) & (n-- != i->second->begin()); )
 
 class IEMap {
 public:
