
$FreeBSD$

--- modules/xlog/xl_lib.c	2003/11/17 11:31:59	1.1
+++ modules/xlog/xl_lib.c	2003/11/17 11:38:37
@@ -38,6 +38,7 @@
 #include "../../ut.h" 
 #include "../../trim.h" 
 
+#include "../../parser/contact/parse_contact.h"
 #include "../../parser/parse_from.h"
 #include "../../parser/parse_uri.h"
 
@@ -195,7 +196,14 @@
 		DBG("XLOG: xl_get_contact: no contact header\n");
 		return xl_get_null(msg, res);
 	}
-	
+
+	if (msg->contact && msg->contact->parsed &&
+	    ((contact_body_t*)msg->contact->parsed)->contacts &&
+	    ((contact_body_t*)msg->contact->parsed)->contacts->uri.len > 0) {
+		*res = ((contact_body_t*)msg->contact->parsed)->contacts->uri;
+		return 0;
+	}
+
 	if(!msg->contact || !msg->contact->body.s || msg->contact->body.len<=0)
     {
 		DBG("XLOG: xl_get_contact: no contact header!\n");
