--- konverse/jabberid.h	2001/02/27 02:31:57	1.4
+++ konverse/jabberid.h	2002/02/20 04:25:25	1.5
@@ -44,16 +44,16 @@
 	 */
 	JabberID( QString jid );
 	JabberID( QString node, QString domain, QString resource );
-        JabberID( JabberID &jid );
+        JabberID( const JabberID &jid );
 
 	/**
 	 * Returns jabber id strings.
 	 */
-	QString getJID(); //In [node@]domain[/resource] format
+	QString getJID() const; //In [node@]domain[/resource] format
 
-	QString getNode();
-	QString getDomain();
-	QString getResource();
+	QString getNode() const;
+	QString getDomain() const;
+	QString getResource() const;
 
 	JabberID operator=(QString& jid);
 

