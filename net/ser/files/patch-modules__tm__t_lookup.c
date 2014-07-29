
$FreeBSD$

--- modules/tm/t_lookup.c.orig
+++ modules/tm/t_lookup.c
@@ -103,8 +103,8 @@
 #include "t_msgbuilder.h" /* for t_lookup_callid */
 
 #define EQ_VIA_LEN(_via)\
-	( (p_msg->via1->bsize-(p_msg->_via->name.s-(p_msg->_via->hdr.s+p_msg->_via->hdr.len)))==\
-	  	(t_msg->via1->bsize-(t_msg->_via->name.s-(t_msg->_via->hdr.s+t_msg->_via->hdr.len))) )
+	( (p_msg->_via->port_str.len > 0 ? (p_msg->_via->port_str.s + p_msg->_via->port_str.len - p_msg->_via->name.s) : p_msg->_via->name.len) ==\
+		(t_msg->_via->port_str.len > 0 ? (t_msg->_via->port_str.s + t_msg->_via->port_str.len - t_msg->_via->name.s) : t_msg->_via->name.len) )
 
 
 
@@ -122,7 +122,7 @@
 #define EQ_VIA_STR(_via)\
 	( memcmp( t_msg->_via->name.s,\
 	 p_msg->_via->name.s,\
-	 (t_msg->via1->bsize-(t_msg->_via->name.s-(t_msg->_via->hdr.s+t_msg->_via->hdr.len)))\
+	 (t_msg->_via->port_str.len > 0 ? (t_msg->_via->port_str.s+t_msg->_via->port_str.len - t_msg->_via->name.s) : t_msg->_via->name.len) \
 	)==0 )
 
 
@@ -264,8 +264,10 @@
 	if (memcmp(inv_via->host.s, ack_via->host.s,
 			ack_via->host.len)!=0)
 		return 0;
+#if 0
 	if (inv_via->port!=ack_via->port)
 		return 0;
+#endif
 	if (inv_via->transport.len!=ack_via->transport.len)
 		return 0;
 	if (memcmp(inv_via->transport.s, ack_via->transport.s,
