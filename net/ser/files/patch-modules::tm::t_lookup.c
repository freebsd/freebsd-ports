
$FreeBSD$

--- modules/tm/t_lookup.c	2003/07/29 04:01:00	1.1
+++ modules/tm/t_lookup.c	2003/07/29 04:05:47
@@ -94,8 +94,8 @@
 #include "t_lookup.h"
 
 #define EQ_VIA_LEN(_via)\
-	( (p_msg->via1->bsize-(p_msg->_via->name.s-(p_msg->_via->hdr.s+p_msg->_via->hdr.len)))==\
-	  	(t_msg->via1->bsize-(t_msg->_via->name.s-(t_msg->_via->hdr.s+t_msg->_via->hdr.len))) )
+	( (p_msg->_via->port_str.s + p_msg->_via->port_str.len - p_msg->_via->name.s)==\
+		(t_msg->_via->port_str.s + t_msg->_via->port_str.len - t_msg->_via->name.s) )
 
 
 
@@ -113,7 +113,7 @@
 #define EQ_VIA_STR(_via)\
 	( memcmp( t_msg->_via->name.s,\
 	 p_msg->_via->name.s,\
-	 (t_msg->via1->bsize-(t_msg->_via->name.s-(t_msg->_via->hdr.s+t_msg->_via->hdr.len)))\
+	 (t_msg->_via->port_str.s+t_msg->_via->port_str.len - t_msg->_via->name.s)\
 	)==0 )
 
 
