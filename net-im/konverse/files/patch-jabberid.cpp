--- konverse/jabberid.cpp	2000/12/28 03:41:37	1.10
+++ konverse/jabberid.cpp	2002/02/20 04:25:25	1.11
@@ -35,7 +35,7 @@
 	_resource = resource.copy();
 }
 
-JabberID::JabberID(JabberID &jid)
+JabberID::JabberID(const JabberID &jid)
 {
         _node = jid.getNode().copy();
         _domain = jid.getDomain().copy();
@@ -81,22 +81,22 @@
  	 }
 }
 
-QString JabberID::getDomain()
+QString JabberID::getDomain() const
 {
 	return _domain;
 }
 
-QString JabberID::getNode()
+QString JabberID::getNode() const
 {
 	return _node;
 }
 
-QString JabberID::getResource()
+QString JabberID::getResource() const
 {
 	return _resource;
 }
 
-QString JabberID::getJID()
+QString JabberID::getJID() const
 {
 	QString fullID;
 

