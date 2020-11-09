--- browser.c.orig	2020-11-08 20:52:49 UTC
+++ browser.c
@@ -87,6 +87,12 @@ static int browser_compare_subject (const void *a, con
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = mutt_strcoll (pa->display_name, pb->display_name);
 
   return ((BrowserSort & SORT_REVERSE) ? -r : r);
@@ -97,6 +103,12 @@ static int browser_compare_date (const void *a, const 
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->mtime - pb->mtime;
 
   return ((BrowserSort & SORT_REVERSE) ? -r : r);
@@ -107,6 +119,12 @@ static int browser_compare_size (const void *a, const 
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->size - pb->size;
 
   return ((BrowserSort & SORT_REVERSE) ? -r : r);
@@ -117,6 +135,12 @@ static int browser_compare_count (const void *a, const
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
 
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
+
   int r = pa->msg_count - pb->msg_count;
 
   return ((BrowserSort & SORT_REVERSE) ? -r : r);
@@ -126,6 +150,12 @@ static int browser_compare_unread (const void *a, cons
 {
   struct folder_file *pa = (struct folder_file *) a;
   struct folder_file *pb = (struct folder_file *) b;
+
+  /* Always keep '..' in first menu position */
+  if (!strncmp(pa->display_name, "..", 2))
+	  return(-1);
+  if (!strncmp(pb->display_name, "..", 2))
+	  return(1);
 
   int r = pa->msg_unread - pb->msg_unread;
 
