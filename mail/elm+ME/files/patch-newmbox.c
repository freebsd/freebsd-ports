--- src/newmbox.c.orig	Sun Aug 19 07:24:27 2001
+++ src/newmbox.c	Sun Aug 19 07:25:50 2001
@@ -585,6 +585,36 @@
 	    }
 
 	    if (NULL != (tmphdr = locate_header_by_name(parsed_headers,
+							"Newsgroups"))) {
+		struct addr_item * addrs = 
+		    break_down_address(tmphdr->body,
+				       !(current_header -> status & 
+					 NOHDRENCODING) &&
+				       is_rfc1522(tmphdr->body),
+				       current_header->header_charset);
+
+		if (addrs) {
+		    if (current_header->to)
+			free_addr_items(current_header->to);
+		    current_header->to = addrs;
+
+#if DEBUG
+		    if (Debug.active > 10) {
+			struct addr_item * p;
+			for (p =  current_header->to; p->addr; p++) {
+			    DPRINT(Debug,15,(&Debug, 
+					     "--   newsgroup[%d] addr='%s' comment='%S' fullname='%S'\n",
+					     p - current_header->to,
+					     p->addr,
+					     p->comment,
+					     p->fullname));
+			}
+		    }
+#endif
+		}	       
+	    }
+
+	    if (NULL != (tmphdr = locate_header_by_name(parsed_headers,
 							"Cc"))) {	    
 		struct addr_item * addrs = 
 		    break_down_address(tmphdr->body,
