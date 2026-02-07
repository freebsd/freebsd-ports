--- frontends/xml/vcd_xml_common.c.orig	2018-01-03 20:17:37 UTC
+++ frontends/xml/vcd_xml_common.c
@@ -242,16 +242,26 @@ _convert (const char in[], const char encoding[], bool
 
   temp = size - 1;
   if (from) {
-    if (NULL != handler->output)
-      ret = handler->output (out, &out_size, (const unsigned char *) in, &temp);
-    else
+    if (!(handler->flags & 2) && NULL != handler->output.func)
+      ret = handler->output.func (handler->outputCtxt, out, &out_size, (const unsigned char *) in, &temp, 1);
+    if ((handler->flags & 2) && NULL != handler->output.legacyFunc)
+      ret = handler->output.legacyFunc (out, &out_size, (const unsigned char *) in, &temp);
+    else {
+      xmlCharEncCloseFunc(handler);
       return strdup(in);
+    }
   } else {
-    if (NULL != handler->input)
-      ret = handler->input (out, &out_size, (const unsigned char *) in, &temp);
-    else
+    if (!(handler->flags & 2) && NULL != handler->input.func)
+      ret = handler->input.func (handler->inputCtxt, out, &out_size, (const unsigned char *) in, &temp, 1);
+    if ((handler->flags & 2) && NULL != handler->input.legacyFunc)
+      ret = handler->input.legacyFunc (out, &out_size, (const unsigned char *) in, &temp);
+    else {
+      xmlCharEncCloseFunc(handler);
       return strdup(in);
+    }
   }
+
+  xmlCharEncCloseFunc(handler);
 
   if (ret < 0 || (temp - size + 1))
     {
