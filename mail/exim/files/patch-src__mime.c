diff -urN ../exim-4.84.orig/src/mime.c ../exim-4.84/src/mime.c
--- ../exim-4.84.orig/src/mime.c	2014-08-09 15:44:29.000000000 +0300
+++ ../exim-4.84/src/mime.c	2014-11-12 02:36:21.000000000 +0200
@@ -620,12 +620,18 @@
 		else
 		  param_value = string_cat(param_value, &size, &ptr, q++, 1);
 		}
-	      param_value[ptr++] = '\0';
-	      param_value_len = ptr;
-
-	      param_value = rfc2047_decode(param_value, check_rfc2047_length, NULL, 32, &param_value_len, &q);
-	      debug_printf("Found %s MIME parameter in %s header, value is '%s'\n", mp->name, mime_header_list[i].name, param_value);
-	      *((uschar **)(mp->value)) = param_value;
+	      if (param_value)
+		{
+		param_value[ptr++] = '\0';
+		param_value_len = ptr;
+
+		param_value = rfc2047_decode(param_value,
+		      check_rfc2047_length, NULL, 32, &param_value_len, &q);
+		debug_printf("Found %s MIME parameter in %s header, "
+		      "value is '%s'\n", mp->name, mime_header_list[i].name,
+		      param_value);
+		}
+	      *mp->value = param_value;
 	      p += (mp->namelen + param_value_len + 1);
 	      goto NEXT_PARAM_SEARCH;
 	    }
diff -urN ../exim-4.84.orig/src/mime.h ../exim-4.84/src/mime.h
--- ../exim-4.84.orig/src/mime.h	2014-08-09 15:44:29.000000000 +0300
+++ ../exim-4.84/src/mime.h	2014-11-12 02:36:13.000000000 +0200
@@ -40,15 +40,15 @@
 
 
 typedef struct mime_parameter {
-  uschar *name;
-  int    namelen;
-  void   *value;
+  uschar *  name;
+  int       namelen;
+  uschar ** value;
 } mime_parameter;
 
 static mime_parameter mime_parameter_list[] = {
-  { US"name=", 5, &mime_filename },
+  { US"name=",     5, &mime_filename },
   { US"filename=", 9, &mime_filename },
-  { US"charset=", 8, &mime_charset },
+  { US"charset=",  8, &mime_charset },
   { US"boundary=", 9, &mime_boundary }
 };
 
