--- qxmpp.pri.orig	2011-04-07 05:36:03.000000000 +0000
+++ qxmpp.pri	2012-01-08 14:08:13.744880936 +0000
@@ -35,3 +35,11 @@
     QXMPP_LIBRARY_FILE = $${QXMPP_LIBRARY_DIR}/lib$${QXMPP_LIBRARY_NAME}.a
 }
 
+unix {
+	isEmpty(PREFIX) {
+		PREFIX = /usr/local
+	}
+	isEmpty(LIBDIR) {
+		LIBDIR = lib
+	}
+}
