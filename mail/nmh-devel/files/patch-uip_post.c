--- uip/post.c.orig	2023-12-04 03:00:44 UTC
+++ uip/post.c
@@ -657,34 +657,17 @@ main (int argc, char **argv)
 		free (cp);
 		continue;
 
-	    case BODY: {
-		size_t n, n_written;
-
+	    case BODY: 
 		finish_headers (out);
 		if (whomsw)
 		    break;
-		if (fwrite ("\n", 1, 1, out) != 1) {
-		    adios ("write of newline between header and body",
-			   "failed");
-		}
-		/* Don't emit trailing NUL, to not interfere with SMTP
-		   conversation. */
-		n = bufsz > 0 && buf[bufsz-1] == '\0' ? bufsz - 1 : bufsz;
-		if (n > 0  &&  (n_written = fwrite (buf, 1, n, out)) != n) {
-		    adios ("octets of body", "wrote %ld instead of %ld",
-			   n_written, n);
-		}
+		fprintf (out, "\n%s", buf);
 		while (state == BODY) {
 		    bufsz = sizeof buf;
 		    state = m_getfld2(&gstate, name, buf, &bufsz);
-		    n = bufsz > 0 && buf[bufsz-1] == '\0' ? bufsz - 1 : bufsz;
-		    if (n > 0  &&  (n_written = fwrite (buf, 1, n, out)) != n) {
-			adios ("octets of body continuation",
-			       "wrote %ld instead of %ld", n_written, n);
-		    }
+		    fputs (buf, out);
 		}
 		break;
-	    }
 
 	    case FILEEOF: 
 		finish_headers (out);
