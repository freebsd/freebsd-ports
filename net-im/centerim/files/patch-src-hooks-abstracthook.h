--- src/hooks/abstracthook.h.orig	2011-05-23 01:06:31.000000000 +0400
+++ src/hooks/abstracthook.h	2014-01-21 08:30:44.206593005 +0400
@@ -47,11 +47,7 @@
 };
 
 class abstracthook {
-    protected:
-	enum Encoding {
-	    encUTF, encKOI, encUnknown
-	};
-
+	public:
 	enum logevent {
 	    logConnecting,
 	    logLogged,
@@ -63,6 +59,11 @@
 	    logConfMembers
 	};
 
+    protected:
+	enum Encoding {
+	    encUTF, encKOI, encUnknown
+	};
+
 	protocolname proto;
 	imstatus manualstatus;
 	verticalmenu *searchdest;
