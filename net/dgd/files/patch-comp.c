--- src/comp/comp.c.orig	Tue Sep  2 10:58:56 2003
+++ src/comp/comp.c	Tue Sep  2 11:14:29 2003
@@ -558,6 +558,20 @@
     return TRUE;
 }
 
+#ifdef NETWORK_PACKAGE
+/*
+ * NAME:	comm->openport()
+ * DESCRIPTION:	pretend to open a port
+ */
+void comm_openport(f, obj, protocol, portnr)
+frame *f;
+object *obj;
+unsigned char protocol;
+unsigned short portnr;
+{
+}
+#endif
+
 /*
  * NAME:	comm->finish()
  * DESCRIPTION:	pretend to terminate connections
@@ -585,6 +599,35 @@
     return 0;
 }
 
+#ifdef NETWORK_PACKAGE
+/*
+ * NAME:	comm->connect()
+ * DESCRIPTION:	pretend to open a connection to a port
+ */
+void
+comm_connect(f, obj, addr, protocol, port)
+frame *f;
+object *obj;
+char *addr;
+unsigned char protocol;
+unsigned short port;
+{
+}
+
+/*
+ * NAME:	comm->senddatagram()
+ * DESCRIPTION:	pretend to send a UDP datagram
+ */
+int comm_senddatagram(obj, str, ip, port)
+object * obj;
+string * str;
+string * ip;
+int port;
+{
+	return 0;
+}
+#endif
+
 /*
  * NAME:	comm->udpsend()
  * DESCRIPTION:	pretend to send a message on the UDP channel of a connection
@@ -668,8 +711,14 @@
  * NAME:	comm->users()
  * DESCRIPTION:	pretend to return an array with all user objects
  */
+#ifdef NETWORK_PACKAGE
+array *comm_users(data, ports)
+dataspace *data;
+bool ports;
+#else
 array *comm_users(data)
 dataspace *data;
+#endif
 {
     return (array *) NULL;
 }
