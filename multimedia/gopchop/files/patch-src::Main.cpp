--- src/Main.cpp.orig	Thu Apr 15 12:08:27 2004
+++ src/Main.cpp	Thu Apr 15 12:08:40 2004
@@ -305,7 +305,7 @@
     static gchar *str = NULL;
 
     // text needs a static area, I think... ?
-    (void *) str = g_realloc(str, strlen(text) + 1);
+    str = (gchar *) g_realloc(str, strlen(text) + 1);
     strcpy(str, text);
 
     gtk_text_freeze(GTK_TEXT(error_text_why));
@@ -998,7 +998,6 @@
         else if (accel & MPEG2_ACCEL_SPARC_VIS2)
             printf("%s", _("Using Sparc VIS2 acceleration\n"));
 #endif
-        else
             printf("%s", _("Using no special acceleration\n"));
     
         if (!(mpeg2dec = mpeg2_init()))
@@ -1382,7 +1381,7 @@
                 }
     
                 len = ves->getLen();
-                (void *)loc = mpeg2parser->bytesAvail(ves->getStart(), len);
+                loc = (uint8_t *) mpeg2parser->bytesAvail(ves->getStart(), len);
     
                 /*
                 fprintf(stderr,_("\t\tVES: %d @ %llu (%d): 0x%08x\n"),
@@ -1399,7 +1398,7 @@
             // send entire packet to pipe
 
             len = packet->getLen();
-            (void *)loc = mpeg2parser->bytesAvail(packet->getStart(), len);
+            loc = (uint8_t *) mpeg2parser->bytesAvail(packet->getStart(), len);
             if (loc && client_pipe)
             {
                 int written;
