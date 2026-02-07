--- bdf.c~	2010-04-16 09:38:59.000000000 -0500
+++ bdf.c	2012-06-05 12:14:59.810640261 -0500
@@ -1654,6 +1654,9 @@ _bdf_parse_properties(char *line, unsign
     next = (_bdf_line_func_t *) call_data;
     p = (_bdf_parse_t *) client_data;
 
+    while (*line == ' ' || *line == '\t')
+        ++line;
+
     /*
      * Check for the end of the properties.
      */
