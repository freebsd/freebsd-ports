--- libproto/maildir/mbox.c.orig	2020-05-28 14:03:57 UTC
+++ libproto/maildir/mbox.c
@@ -134,41 +134,67 @@ maildir_name_info_ptr (char *name)
     return p + 3;
   return NULL;
 }
-
 
+/*
+ * Compare two maildir messages A and B.  The purpose is to determine
+ * which one was delivered prior to another.
+ *
+ * Compare seconds, microseconds and number of deliveries, in that
+ * order.  If all match (shouldn't happen), resort to lexicographical
+ * comparison.
+ */
 static int
 maildir_message_cmp (struct _amd_message *a, struct _amd_message *b)
 {
-  char *name_a, *name_b;
-  unsigned long na = strtoul (((struct _maildir_message *) a)->file_name,
-			      &name_a, 10);
-  unsigned long nb = strtoul (((struct _maildir_message *) b)->file_name,
-			      &name_b, 10);
-  int rc;
+  char *name_a = ((struct _maildir_message *) a)->file_name;
+  char *name_b = ((struct _maildir_message *) b)->file_name;
+  char *pa, *pb;
+  unsigned long la, lb;
+  int d;
   
-  if (na > nb)
+  la = strtoul (name_a, &name_a, 10);
+  lb = strtoul (name_b, &name_b, 10);
+
+  if (la > lb)
     return 1;
-  if (na < nb)
+  if (la < lb)
     return -1;
 
-  /* If timestamps are equal, compare rests of the filenames up to the
-     info marker */
+  if ((d = (*name_a - *name_b)) != 0)
+    return d;
+  
+  name_a++;
+  name_b++;
 
-  if (name_a && !name_b)
-    return 1;
-  else if (!name_a)
+  if ((pa = strchr (name_a, 'M')) != 0 && (pb = strchr (name_b, 'M')) != 0)
     {
-      if (name_b)
+      la = strtoul (name_a, &name_a, 10);
+      lb = strtoul (name_b, &name_b, 10);
+
+      if (la > lb)
+	return 1;
+      if (la < lb)
 	return -1;
-      else 
-	return 0;
     }
-  
+
+  if ((pa = strchr (name_a, 'Q')) != 0 && (pb = strchr (name_b, 'Q')) != 0)
+    {
+      la = strtoul (name_a, &name_a, 10);
+      lb = strtoul (name_b, &name_b, 10);
+
+      if (la > lb)
+	return 1;
+      if (la < lb)
+	return -1;
+    }
+
   for (; *name_a && *name_a != ':' && *name_b && *name_b != ':';
        name_a++, name_b++)
-    if ((rc = (*name_a - *name_b)))
-      return rc;
-
+    {
+      if ((d = (*name_a - *name_b)) != 0)
+	return d;
+    }
+  
   if ((*name_a == ':' || *name_a == 0) && (*name_b == ':' || *name_b == 0))
     return 0;
 
