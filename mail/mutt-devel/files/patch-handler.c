--- handler.c.orig	2008-01-30 05:26:50.000000000 +0100
+++ handler.c	2008-10-16 10:56:40.000000000 +0200
@@ -1199,11 +1199,12 @@
     
     if (rc)
     {
+      mutt_error ("One or more parts of this message could not be displayed");
       dprint (1, (debugfile, "Failed on attachment #%d, type %s/%s.\n", count, TYPE(p), NONULL (p->subtype)));
     }
     
-    if (rc || ((s->flags & M_REPLYING)
-               && (option (OPTINCLUDEONLYFIRST)) && (s->flags & M_FIRSTDONE)))
+    if ((s->flags & M_REPLYING)
+        && (option (OPTINCLUDEONLYFIRST)) && (s->flags & M_FIRSTDONE))
       break;
   }
 
@@ -1564,6 +1565,14 @@
 
     if (!handler)
       handler = multipart_handler;
+    
+    if (b->encoding != ENC7BIT && b->encoding != ENC8BIT
+        && b->encoding != ENCBINARY)
+    {
+      dprint (1, (debugfile, "Bad encoding type %d for multipart entity, "
+                  "assuming 7 bit\n", b->encoding));
+      b->encoding = ENC7BIT;
+    }
   }
   else if (WithCrypto && b->type == TYPEAPPLICATION)
   {
