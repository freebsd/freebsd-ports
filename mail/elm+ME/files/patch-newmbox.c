--- src/newmbox.c.orig	Tue Feb  6 19:48:32 2001
+++ src/newmbox.c	Sat May 12 21:28:05 2001
@@ -568,6 +568,33 @@
 		}	       
 	    }
 
+	    else if (NULL != (tmphdr = locate_header_by_name(parsed_headers,
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
+		    if (debug > 15 && debugfile) {
+			struct addr_item * p;
+			for (p =  current_header->to; p->addr; p++) {
+			    elm_fprintf(debugfile,
+					FRM("--   to[%d] addr='%s' comment='%S' fullname='%S'\n"),
+					p - current_header->to,
+					p->addr,
+					p->comment,
+					p->fullname);
+			}
+		    }
+		}	       
+	    }
+
 	    if (NULL != (tmphdr = locate_header_by_name(parsed_headers,
 							"Cc"))) {	    
 		struct addr_item * addrs = 
