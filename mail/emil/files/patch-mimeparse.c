--- mimeparse.c.orig	1996-06-04 13:36:59 UTC
+++ mimeparse.c
@@ -219,9 +219,40 @@ parse_mime_siblings(struct message *m)
 	    inbuf->bodystart,
 	    inbuf->bodyend);
 #endif
+  /* FIX */
+  if (m->sd->encoding == EMULTI && m->sd->endbound != NULL)
+    {
+      int tttt;
+      move_past_boundary(m, m->sd->endbound);
+      for (;;)
+      {
+        tttt = get_line(m->sd);
+#ifdef DEBUG
+          if (edebug)
+            fprintf(stderr," get_line = %d\n", tttt);
+#endif
+        if (tttt == 1)
+          {
+            inbuf->offset += tttt;
+            inbuf->loffset += 1;
+            continue;
+          }
+        if (tttt == 2 && *(m->sd->contents + m->sd->offset) == '\r')
+          {
+            inbuf->offset += tttt;
+            inbuf->loffset += 1;
+            continue;
+          }
+        break;
+      }
 
-  m->sd->offset = m->sd->bodyend;
-  if (getline(m->sd) == 0)
+    }
+  else
+  /* END_FIX */
+    m->sd->offset = m->sd->bodyend;
+
+
+  if (get_line(m->sd) == 0)
     return(OK);
   if (m->sd->offset < m->sd->end)
     {
