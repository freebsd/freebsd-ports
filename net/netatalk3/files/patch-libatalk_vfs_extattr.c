--- libatalk/vfs/extattr.c	2020-11-17 04:20:13 UTC
+++ libatalk/vfs/extattr.c	
@@ -353,13 +353,13 @@ static ssize_t bsd_attr_list (int type, extattr_arg ar
     }
 
     /* Convert from pascal strings to C strings */
-    len = list[0];
-    memmove(list, list + 1, list_size);
+    len = (unsigned char)list[0];
+    memmove(list, list + 1, list_size - 1);
 
     for(i = len; i < list_size; ) {
         LOG(log_maxdebug, logtype_afpd, "len: %d, i: %d", len, i);
 
-        len = list[i];
+        len = (unsigned char)list[i];
         list[i] = '\0';
         i += len + 1;
     }
