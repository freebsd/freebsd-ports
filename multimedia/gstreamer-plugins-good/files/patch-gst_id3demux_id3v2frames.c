diff -u -r1.16 id3v2frames.c
--- gst/id3demux/id3v2frames.c	10 May 2006 13:51:01 -0000	1.16
+++ gst/id3demux/id3v2frames.c	15 May 2006 09:48:46 -0000
@@ -667,33 +667,21 @@
   return result;
 }
 
-static void
-parse_insert_string_field (const gchar * encoding, gchar * data, gint data_size,
-    GArray * fields)
-{
-  gchar *field;
-
-  field = g_convert (data, data_size, "UTF-8", encoding, NULL, NULL, NULL);
-  if (field && !g_utf8_validate (field, -1, NULL)) {
-    GST_DEBUG ("%s was bad UTF-8. Ignoring", field);
-    g_free (field);
-    field = NULL;
-  }
-  if (field)
-    g_array_append_val (fields, field);
-}
+static const gchar utf16enc[] = "UTF-16";
+static const gchar utf16leenc[] = "UTF-16LE";
+static const gchar utf16beenc[] = "UTF-16BE";
 
 static gboolean
-has_utf16_bom (gchar * data, const gchar ** p_in_encoding)
+find_utf16_bom (gchar * data, const gchar ** p_in_encoding)
 {
   guint16 marker = (GST_READ_UINT8 (data) << 8) | GST_READ_UINT8 (data + 1);
 
   switch (marker) {
     case 0xFFFE:
-      *p_in_encoding = "UTF16LE";
+      *p_in_encoding = utf16leenc;
       return TRUE;
     case 0xFEFF:
-      *p_in_encoding = "UTF16BE";
+      *p_in_encoding = utf16beenc;
       return TRUE;
     default:
       break;
@@ -702,6 +690,63 @@
 }
 
 static void
+parse_insert_string_field (guint8 encoding, gchar * data, gint data_size,
+    GArray * fields)
+{
+  gchar *field = NULL;
+
+  switch (encoding) {
+  case ID3V2_ENCODING_UTF16:
+  case ID3V2_ENCODING_UTF16BE:
+    {
+      const gchar *in_encode;
+
+      if (encoding == ID3V2_ENCODING_UTF16)
+        in_encode = utf16enc;
+      else
+        in_encode = utf16beenc;
+
+      /* Sometimes we see strings with multiple BOM markers at the start.
+       * In that case, we assume the innermost one is correct. If that fails
+       * to produce valid UTF-8, we try the other endianness anyway */
+      while (data_size > 2 && find_utf16_bom (data, &in_encode)) {
+        data += 2;          /* skip BOM */
+        data_size -= 2;
+      }
+
+      field = g_convert (data, data_size, "UTF-8", in_encode, NULL, NULL, NULL);
+
+      if (field == NULL || g_utf8_validate (field, -1, NULL) == FALSE) {
+        /* As a fallback, try interpreting UTF-16 in the other endianness */
+        if (in_encode == utf16beenc)
+          field = g_convert (data, data_size, "UTF-8", utf16leenc, 
+                      NULL, NULL, NULL);
+      }
+    }
+
+    break;
+  case ID3V2_ENCODING_ISO8859:
+    field = g_convert (data, data_size, "UTF-8", "ISO-8859-1", 
+              NULL, NULL, NULL);
+    break;
+  default:
+    field = g_strndup (data, data_size);
+    break;
+  }
+
+  if (field) {
+    if (g_utf8_validate (field, -1, NULL)) {
+      g_array_append_val (fields, field);
+      return;
+    }
+
+    GST_DEBUG ("%s was bad UTF-8 after conversion from encoding %d. Ignoring", 
+        field, encoding);
+    g_free (field);
+  }
+}
+
+static void
 parse_split_strings (guint8 encoding, gchar * data, gint data_size,
     GArray ** out_fields)
 {
@@ -715,13 +760,13 @@
     case ID3V2_ENCODING_ISO8859:
       for (text_pos = 0; text_pos < data_size; text_pos++) {
         if (data[text_pos] == 0) {
-          parse_insert_string_field ("ISO-8859-1", data + prev,
+          parse_insert_string_field (encoding, data + prev,
               text_pos - prev + 1, fields);
           prev = text_pos + 1;
         }
       }
       if (data_size - prev > 0 && data[prev] != 0x00) {
-        parse_insert_string_field ("ISO-8859-1", data + prev,
+        parse_insert_string_field (encoding, data + prev,
             data_size - prev, fields);
       }
 
@@ -729,34 +774,24 @@
     case ID3V2_ENCODING_UTF8:
       for (prev = 0, text_pos = 0; text_pos < data_size; text_pos++) {
         if (data[text_pos] == '\0') {
-          parse_insert_string_field ("UTF-8", data + prev,
+          parse_insert_string_field (encoding, data + prev,
               text_pos - prev + 1, fields);
           prev = text_pos + 1;
         }
       }
       if (data_size - prev > 0 && data[prev] != 0x00) {
-        parse_insert_string_field ("UTF-8", data + prev,
+        parse_insert_string_field (encoding, data + prev,
             data_size - prev, fields);
       }
       break;
     case ID3V2_ENCODING_UTF16:
     case ID3V2_ENCODING_UTF16BE:
     {
-      const gchar *in_encode;
-
-      if (encoding == ID3V2_ENCODING_UTF16)
-        in_encode = "UTF-16";
-      else
-        in_encode = "UTF-16BE";
-
       /* Find '\0\0' terminator */
       for (text_pos = 0; text_pos < data_size - 1; text_pos += 2) {
         if (data[text_pos] == '\0' && data[text_pos + 1] == '\0') {
-          if (has_utf16_bom (data + prev, &in_encode)) {
-            prev += 2;          /* skip BOM */
-          }
           /* found a delimiter */
-          parse_insert_string_field (in_encode, data + prev,
+          parse_insert_string_field (encoding, data + prev,
               text_pos - prev + 2, fields);
           text_pos++;           /* Advance to the 2nd NULL terminator */
           prev = text_pos + 1;
@@ -765,11 +800,8 @@
       }
       if (data_size - prev > 1 &&
           (data[prev] != 0x00 || data[prev + 1] != 0x00)) {
-        if (has_utf16_bom (data + prev, &in_encode)) {
-          prev += 2;            /* skip BOM */
-        }
         /* There were 2 or more non-null chars left, convert those too */
-        parse_insert_string_field (in_encode, data + prev,
+        parse_insert_string_field (encoding, data + prev,
             data_size - prev, fields);
       }
       break;
