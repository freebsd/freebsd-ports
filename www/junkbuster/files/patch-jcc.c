--- jcc.c.orig	Fri Oct 30 22:58:48 1998
+++ jcc.c	Sat Mar 11 11:42:32 2000
@@ -96,9 +96,27 @@
 
 char DEFAULT_USER_AGENT[] ="User-Agent: Mozilla/3.01Gold (Macintosh; I; 68K)";
 
+char BLANKGIF[] = "HTTP/1.0 200 OK\r\n" 
+                  "Content-type: image/gif\r\n\r\n" 
+                  "GIF89a\001\000\001\000\200\000\000\377\377\377\000\000" 
+                  "\000!\371\004\001\000\000\000\000,\000\000\000\000\001" 
+                  "\000\001\000\000\002\002D\001\000;"; 
+
+char JBGIF[] = "HTTP/1.0 200 OK\r\n"
+                  "Content-type: image/gif\r\n\r\n"
+                  "GIF89aD\000\013\000\360\000\000\000\000\000\377\377\377!"
+                  "\371\004\001\000\000\001\000,\000\000\000\000D\000\013\000"
+                  "\000\002a\214\217\251\313\355\277\000\200G&K\025\316hC\037"
+                  "\200\234\230Y\2309\235S\230\266\206\372J\253<\3131\253\271"
+                  "\270\215\342\254\013\203\371\202\264\334P\207\332\020o\266"
+                  "N\215I\332=\211\312\3513\266:\026AK)\364\370\365aobr\305"
+                  "\372\003S\275\274k2\354\254z\347?\335\274x\306^9\374\276"
+                  "\037Q\000\000;";
+
 int debug           = 0;
 int multi_threaded  = 1;
 int hideConsole     = 0;
+int tinygif         = 0;
 
 #ifdef _WIN32
 #define sleep(N)	Sleep(((N) * 1000))
@@ -198,6 +216,9 @@
 	struct cookie_spec *cs;
 	struct gateway *gw;
 	struct http_request *http;
+	char *my_image_regexp = ".*(\\.gif|\\.jpe?g|\\gif$|\\jpe?g$)";
+	regex_t my_regexp;
+	int errcode;
 
 	http = csp->http;
 
@@ -328,7 +349,21 @@
 				prog, http->hostport, http->path);
 		}
 
-		write_socket(csp->cfd, p, strlen(p));
+		if (tinygif > 0) {
+		  errcode = regcomp(&my_regexp, my_image_regexp,
+				    (REG_EXTENDED|REG_NOSUB|REG_ICASE));
+		  
+		  if (regexec( &my_regexp, http->path, 0, NULL, 0) == 0) {
+		    if (tinygif == 1)
+		      write_socket(csp->cfd, BLANKGIF, sizeof(BLANKGIF)-1);
+		    else
+		      write_socket(csp->cfd, JBGIF, sizeof(JBGIF)-1);
+		  } else {
+		    write_socket(csp->cfd, p, strlen(p));
+		  }
+		  regfree( &my_regexp );
+		} else
+		  write_socket(csp->cfd, p, strlen(p));
 
 		if(DEBUG(LOG)) fwrite(p, strlen(p), 1, logfp);
 
@@ -704,6 +739,11 @@
 
 			if(strcmp(cmd, "debug") == 0) {
 				debug |= atoi(arg);
+				continue;
+			}
+
+			if(strcmp(cmd, "tinygif") == 0) {
+				tinygif = atoi(arg);
 				continue;
 			}
 
