
$FreeBSD$

--- modules/tm/t_lookup.c.orig	Fri Jul 16 00:18:34 2004
+++ modules/tm/t_lookup.c	Tue Jul 27 21:01:37 2004
@@ -97,8 +97,8 @@
 #include "t_msgbuilder.h" /* for t_lookup_callid */
 
 #define EQ_VIA_LEN(_via)\
-	( (p_msg->via1->bsize-(p_msg->_via->name.s-(p_msg->_via->hdr.s+p_msg->_via->hdr.len)))==\
-	  	(t_msg->via1->bsize-(t_msg->_via->name.s-(t_msg->_via->hdr.s+t_msg->_via->hdr.len))) )
+	( (p_msg->_via->port_str.len > 0 ? (p_msg->_via->port_str.s + p_msg->_via->port_str.len - p_msg->_via->name.s) : p_msg->_via->name.len) ==\
+		(t_msg->_via->port_str.len > 0 ? (t_msg->_via->port_str.s + t_msg->_via->port_str.len - t_msg->_via->name.s) : t_msg->_via->name.len) )
 
 
 
@@ -116,7 +116,7 @@
 #define EQ_VIA_STR(_via)\
 	( memcmp( t_msg->_via->name.s,\
 	 p_msg->_via->name.s,\
-	 (t_msg->via1->bsize-(t_msg->_via->name.s-(t_msg->_via->hdr.s+t_msg->_via->hdr.len)))\
+	 (t_msg->_via->port_str.len > 0 ? (t_msg->_via->port_str.s+t_msg->_via->port_str.len - t_msg->_via->name.s) : t_msg->_via->name.len) \
 	)==0 )
 
 
