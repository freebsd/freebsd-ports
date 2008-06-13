--- FastCGI/WebObjects.c.orig	Wed Mar 26 21:13:09 2003
+++ FastCGI/WebObjects.c	Sun May 13 07:08:27 2007
@@ -212,7 +212,7 @@
 		       WOLog(WO_INFO,"<FastCGI> Signal %s caught", strsignal(signum));
 		       break;
 	case SIGPIPE : WOLog(WO_WARN,"<FastCGI> Signal %s caught", strsignal(signum));
-		       exit(-1);
+		       break;
 	case SIGTERM : WOLog(WO_ERR,"<FastCGI> Signal %s caught", strsignal(signum));
 		       exit(-1);
 	default:       WOLog( WO_INFO,"<FastCGI> Signal %s caught", strsignal(signum));
@@ -327,19 +327,7 @@
       /*
        *	extract WebObjects application name from URI
        */
-      qs = FCGX_GetParam("QUERY_STRING", hdrp);
-      if (qs) {
-         qs_len = strlen(qs);
-      } else {
-         qs_len = 0;
-      }
-
-      if (qs_len > 0) {
-         /* Make room for query string and "?" */
-         url = WOMALLOC(strlen(path_info) + strlen(script_name) + 1 + qs_len + 2);
-      } else {
-         url = WOMALLOC(strlen(path_info) + strlen(script_name) + 1);
-      }
+      url = WOMALLOC(strlen(path_info) + strlen(script_name) + 1);
       strcpy(url, script_name);
       strcat(url, path_info);
       WOLog(WO_INFO,"<FastCGI> new request: %s",url);
@@ -459,25 +447,28 @@
 */
          }
       }
-			
-			WOLog ( WO_INFO, "Content length: %d",req->content_length );
-			WOLog ( WO_INFO, "--------Content: %s---",req->content );
-			if ( req->content ) {
-				content_buffer = (char *)malloc (req->content_length+1);			
-				strncpy (content_buffer,req->content,req->content_length);
-				content_buffer[req->content_length] = '\0';
-				WOLog ( WO_INFO, "---content buffer: %s",content_buffer );
-				strncpy (req->content,content_buffer,req->content_length+1);
-				free (content_buffer);
-			}
-			//WOLog ( WO_INFO, "Content_length: %d, real: %d", req->content_length,strlen (req->content) );
+
+      WOLog(WO_INFO, "Content length: %d",req->content_length);
+      WOLog(WO_INFO, "--------Content: %s---",req->content);
+      if (req->content) {
+         content_buffer = (char *)WOMALLOC(req->content_length+1);
+         strncpy(content_buffer,req->content,req->content_length);
+         content_buffer[req->content_length] = '\0';
+         WOLog(WO_INFO, "---content buffer: %s",content_buffer);
+         strncpy(req->content,content_buffer,req->content_length+1);
+         WOFREE(content_buffer);
+      }
+      //WOLog ( WO_INFO, "Content_length: %d, real: %d", req->content_length,strlen (req->content) );
 
       /* Always get the query string */
-      /* Don't add ? if the query string is empty. */
+      qs = FCGX_GetParam("QUERY_STRING", hdrp);
+      if (qs) {
+         qs_len = strlen(qs);
+      } else {
+         qs_len = 0;
+      }
+
       if (qs_len > 0) {
-         /* Add the query string to the full URL - useful for debugging */
-         strcat(url, "?");
-         strcat(url, qs);
          wc.queryString.start = qs;
          wc.queryString.length = qs_len;
          WOLog(WO_INFO,"<FastCGI> new request with Query String: %s", qs);
@@ -493,10 +484,10 @@
          resp_free(resp);		/* dump the response */
       }
 
-#if defined(FINDLEAKS)
-      WOFREE(url);				/* just for neatness */
+      WOFREE(url);
       req_free(req);
 
+#if defined(FINDLEAKS)
       showleaks();
 #endif
     }
