--- SOAPParameter.h.orig	Thu Jun 26 09:18:02 2003
+++ include/easysoap/SOAPParameter.h	Thu Jun 26 09:18:19 2003
@@ -165,7 +165,7 @@
 		Data(const Data&);
 	};
 
-	friend Data;
+	friend class Data;
 
 	Pool			m_pool;
 	SOAPParameter	*m_parent;
