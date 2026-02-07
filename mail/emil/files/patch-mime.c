--- mime.c.orig	1996-06-04 13:36:59 UTC
+++ mime.c
@@ -56,18 +56,18 @@ encode_mime(struct message *m)
       if (match(m->sd->type, "TEXT"))
 	{
 	  if (m->td->charset != NULL)
-	    sprintf(buf, "%s; charset=\"%s\"", ct, m->td->charset);
+	    snprintf(buf, sizeof(buf), "%s; charset=\"%s\"", ct, m->td->charset);
 	  else
-	    sprintf(buf, "%s", ct);
+	    snprintf(buf, sizeof(buf), "%s", ct);
 	}
       else
 	if (match(m->sd->type, "MULTIPART"))
 	  {
 	    bb = (char *)getmimebound();
 	    if (m->sd->applefile == AMDOUBLE)
-	      sprintf(buf, "Multipart/AppleDouble; boundary=\"%s\"", bb);
+	      snprintf(buf, sizeof(buf), "Multipart/AppleDouble; boundary=\"%s\"", bb);
 	    else
-	      sprintf(buf,"%s; boundary=\"%s\"", ct, bb);
+	      snprintf(buf, sizeof(buf), "%s; boundary=\"%s\"", ct, bb);
 	    m->td->startbound = (char *)Yalloc(MIMEBOUNDLEN + 5);
 	    m->td->endbound = (char *)Yalloc(MIMEBOUNDLEN + 7);
 	    sprintf(m->td->startbound, "--%s", bb);
@@ -75,7 +75,7 @@ encode_mime(struct message *m)
 	  }
 	else
 	  {
-	    sprintf(buf, "%s", ct);
+	    snprintf(buf, sizeof(buf), "%s", ct);
 	  }
     }
   else
@@ -87,7 +87,10 @@ encode_mime(struct message *m)
   
   if (m->sd->name != NULL)
     {
-      sprintf(buf, "%s; name=\"%s\"", buf, m->sd->name);
+      char *buf2;
+      buf2 = strdup(buf);
+      snprintf(buf, sizeof(buf), "%s; name=\"%s\"", buf2, m->sd->name);
+      free(buf2);
     }
   add_header(m, "Content-Type", buf, MIME);
   if (bb != NULL)
