
$FreeBSD$

--- modules/tm/t_lookup.c.orig	Thu Aug 21 22:33:58 2003
+++ modules/tm/t_lookup.c	Mon Dec 15 20:59:56 2003
@@ -96,8 +96,8 @@
 #include "t_lookup.h"
 
 #define EQ_VIA_LEN(_via)\
-	( (p_msg->via1->bsize-(p_msg->_via->name.s-(p_msg->_via->hdr.s+p_msg->_via->hdr.len)))==\
-	  	(t_msg->via1->bsize-(t_msg->_via->name.s-(t_msg->_via->hdr.s+t_msg->_via->hdr.len))) )
+	( (p_msg->_via->port_str.len > 0 ? (p_msg->_via->port_str.s + p_msg->_via->port_str.len - p_msg->_via->name.s) : p_msg->_via->name.len) ==\
+		(t_msg->_via->port_str.len > 0 ? (t_msg->_via->port_str.s + t_msg->_via->port_str.len - t_msg->_via->name.s) : t_msg->_via->name.len) )
 
 
 
@@ -115,7 +115,7 @@
 #define EQ_VIA_STR(_via)\
 	( memcmp( t_msg->_via->name.s,\
 	 p_msg->_via->name.s,\
-	 (t_msg->via1->bsize-(t_msg->_via->name.s-(t_msg->_via->hdr.s+t_msg->_via->hdr.len)))\
+	 (t_msg->_via->port_str.len > 0 ? (t_msg->_via->port_str.s+t_msg->_via->port_str.len - t_msg->_via->name.s) : t_msg->_via->name.len) \
 	)==0 )
 
 
