Index: appl/ftp/ftp/ftp.c
===================================================================
RCS file: /home/kth-krb/appl/ftp/ftp/ftp.c,v
retrieving revision 1.70
retrieving revision 1.71
diff -u -r1.70 -r1.71
--- appl/ftp/ftp/ftp.c	2001/09/07 20:28:10	1.70
+++ appl/ftp/ftp/ftp.c	2002/04/24 21:55:07	1.71
 struct sockaddr *hisctladdr = (struct sockaddr *)&hisctladdr_ss;
@@ -312,7 +312,8 @@
     char *lead_string;
     int c;
     struct sigaction sa, osa;
-    char buf[1024];
+    char buf[8192];
+    int long_warn = 0;
 
     sigemptyset (&sa.sa_mask);
     sa.sa_flags = 0;
@@ -368,7 +369,7 @@
 		if (verbose > 0 || (verbose > -1 && code > 499))
 		    fprintf (stdout, "%s%s\n", lead_string, buf);
 		if (buf[3] == ' ') {
-		    strcpy (reply_string, buf);
+		    strlcpy (reply_string, buf, sizeof(reply_string));
 		    if (code >= 200)
 			cpend = 0;
 		    sigaction (SIGINT, &osa, NULL);
@@ -381,17 +382,12 @@
 			osa.sa_handler (SIGINT);
 #endif
 		    if (code == 227 || code == 229) {
-			char *p, *q;
+			char *p;
 
-			pasv[0] = 0;
 			p = strchr (reply_string, '(');
 			if (p) {
 			    p++;
-			    q = strchr(p, ')');
-			    if(q){
-				memcpy (pasv, p, q - p);
-				pasv[q - p] = 0;
-			    }
+			    strlcpy(pasv, p, sizeof(pasv));
 			}
 		    }
 		    return code / 100;
@@ -404,9 +400,15 @@
 		}
 	    }
 	    p = buf;
+	    long_warn = 0;
 	    continue;
 	default:
-	    *p++ = c;
+	    if(p < buf + sizeof(buf) - 1)
+		*p++ = c; 
+	    else if(long_warn == 0) {
+		fprintf(stderr, "WARNING: incredibly long line received\n");
+		long_warn = 1;
+	    }
 	}
     }
 
