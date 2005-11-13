--- connection.c.orig	Fri Jul 16 11:16:29 2004
+++ connection.c	Fri Sep  9 06:38:14 2005
@@ -100,8 +100,12 @@
 #ifdef APACHE2
     return INT2NUM(conn->local_addr->port);
 #else
+#ifdef APACHE6
+    return INT2NUM(ntohs(((struct sockaddr_in *)&conn->local_addr)->sin_port));
+#else
     return INT2NUM(ntohs(conn->local_addr.sin_port));
 #endif
+#endif
 }
 
 static VALUE connection_remote_port(VALUE self)
@@ -112,7 +116,11 @@
 #ifdef APACHE2
     return INT2NUM(conn->remote_addr->port);
 #else
+#ifdef APACHE6
+    return INT2NUM(ntohs(((struct sockaddr_in *)&conn->remote_addr)->sin_port));
+#else
     return INT2NUM(ntohs(conn->remote_addr.sin_port));
+#endif
 #endif
 }
 
