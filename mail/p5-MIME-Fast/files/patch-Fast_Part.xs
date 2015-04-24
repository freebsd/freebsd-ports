--- Fast/Part.xs.orig	2004-12-20 17:59:39.603786200 +0300
+++ Fast/Part.xs	2004-12-27 18:05:31.374875000 +0300
@@ -48,7 +48,6 @@
 	XSINTERFACE_FUNC_MIMEFAST_PART_SET
     INTERFACE:
 	set_content_description
-	set_content_md5
 	set_content_location
 	set_content_disposition
 	set_filename
@@ -240,6 +239,9 @@
           g_mime_part_set_content_object(mime_part, mime_data_wrapper);
 
           g_mime_stream_unref(mime_stream);
+        } else if (SvPOKp(svval)) {
+          data = (char *)SvPV(svval, len);
+          g_mime_part_set_content(mime_part, data, len);
 	} else if (svvaltype == SVt_PVMG) { // possible STDIN/STDOUT etc.
           int fd0 = (int)SvIV( svval );
 	  int fd;
@@ -256,9 +258,6 @@
           g_mime_part_set_content_object(mime_part, mime_data_wrapper);
 
           g_mime_stream_unref(mime_stream);
-        } else if (SvPOK(svval)) {
-          data = (char *)SvPV(svval, len);
-          g_mime_part_set_content(mime_part, data, len);
         } else {
           croak("mime_set_content: Unknown type: %d", (int)svvaltype);
         }
