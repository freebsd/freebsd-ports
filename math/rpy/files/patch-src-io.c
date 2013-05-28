--- src/io.c
+++ src/io.c
@@ -130,7 +130,7 @@ RPy_ReadConsole(char *prompt,
     PyErr_Clear();
     return 0;
   }
-  snprintf(buf, len, "%s", PyString_AsString(input_data));
+  snprintf( (char*) buf, len, "%s", PyString_AsString(input_data));
   Py_DECREF(input_data);
   return 1;
 }
diff --git src/rpymodule.c src/rpymodule.c
index fe8b39f..fda1881 100644
