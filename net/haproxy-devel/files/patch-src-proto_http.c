--- src/proto_http.c.orig	2012-12-24 19:48:14.000000000 +0400
+++ src/proto_http.c	2012-12-26 00:10:46.000000000 +0400
@@ -3113,11 +3113,11 @@
 				trash.str[trash.len++] = ' ';
 				trash.len += build_logline(s, trash.str + trash.len, trash.size - trash.len, &rule->arg.hdr_add.fmt);
 				http_header_add_tail2(&txn->req, &txn->hdr_idx, trash.str, trash.len);
-				break;
+				return rule;
 			}
 		}
 	}
-	return rule;
+	return NULL;
 }
 
 /* This stream analyser runs all HTTP request processing which is common to
