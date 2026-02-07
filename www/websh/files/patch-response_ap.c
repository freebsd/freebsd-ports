Patch an ancient bug, uncovered by clang10's new warning-flag...

	-mi

--- ../generic/response_ap.c	2009-05-22 06:13:35.000000000 -0400
+++ ../generic/response_ap.c	2020-03-16 22:40:32.845609000 -0400
@@ -69,4 +69,6 @@
 		r->status_line = ap_pstrdup(r->pool, ++response);
 #else /* APACHE2 */
+	  {
+
 		r->status_line = (char *) apr_pstrdup(r->pool, ++response);
 		/* as of Apache 2.2.1, r->status_line must be in line with
@@ -80,5 +82,5 @@
 		  response[3] = tmp;
 		}
-		
+	  }
 #endif /* APACHE2 */
 	}
