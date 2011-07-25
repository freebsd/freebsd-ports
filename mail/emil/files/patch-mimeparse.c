--- mimeparse.c.orig	1996-06-04 15:36:59.000000000 +0200
+++ mimeparse.c	2011-07-25 20:21:13.000000000 +0200
@@ -219,8 +219,39 @@ parse_mime_siblings(struct message *m)
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
+        tttt = getline(m->sd);
+#ifdef DEBUG
+          if (edebug)
+            fprintf(stderr," getline = %d\n", tttt);
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
+
+    }
+  else
+  /* END_FIX */
+    m->sd->offset = m->sd->bodyend;
+
 
-  m->sd->offset = m->sd->bodyend;
   if (getline(m->sd) == 0)
     return(OK);
   if (m->sd->offset < m->sd->end)
