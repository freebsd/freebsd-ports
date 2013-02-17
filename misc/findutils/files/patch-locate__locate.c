diff locate/locate.c.orig locate/locate.c
--- locate/locate.c.orig
+++ locate/locate.c
@@ -1546,12 +1546,19 @@ opendb (const char *name)
   return fd;
 }
 
+static void
+cleanup_quote_opts (void)
+{
+  free (quote_opts);
+}
+
+
 int
 dolocate (int argc, char **argv, int secure_db_fd)
 {
-  char *path_element;
+  char *path_element = NULL;
   size_t path_element_pos, path_element_len;
-  const char *locate_path;
+  const char *user_selected_locate_path;
   const char *db_name;
   const char *path_separators = ":";
   unsigned long int found = 0uL;
@@ -1565,7 +1572,6 @@ dolocate (int argc, char **argv, int secure_db_fd)
   int stats = 0;
   int op_and = 0;
   FILE *fp;
-  int they_chose_db = 0;
   bool did_stdin = false;       /* Set to prevent rereading stdin. */
 
   if (argv[0])
@@ -1580,19 +1586,19 @@ dolocate (int argc, char **argv, int secure_db_fd)
   textdomain (PACKAGE);
   atexit (close_stdout);
 
+  quote_opts = clone_quoting_options (NULL);
+  atexit (cleanup_quote_opts);
+
   limits.limit = 0;
   limits.items_accepted = 0;
 
-  quote_opts = clone_quoting_options (NULL);
   print_quoted_filename = true;
 
   /* We cannot simultaneously trust $LOCATE_PATH and use the
    * setuid-access-controlled database,, since that could cause a leak
    * of private data.
    */
-  locate_path = getenv ("LOCATE_PATH");
-  if (locate_path)
-    they_chose_db = 1;
+  user_selected_locate_path = getenv ("LOCATE_PATH");
 
   check_existence = ACCEPT_EITHER;
 
@@ -1624,8 +1630,8 @@ dolocate (int argc, char **argv, int secure_db_fd)
           break;
 
         case 'd':
-          locate_path = optarg;
-          they_chose_db = 1;
+          user_selected_locate_path = optarg;
+	  assert (optarg != NULL);
           break;
 
         case 'e':
@@ -1715,7 +1721,7 @@ dolocate (int argc, char **argv, int secure_db_fd)
   /* If the user gave the -d option or set LOCATE_PATH,
    * relinquish access to the secure database.
    */
-  if (they_chose_db)
+  if (user_selected_locate_path)
     {
       if (secure_db_fd >= 0)
         {
@@ -1741,15 +1747,16 @@ dolocate (int argc, char **argv, int secure_db_fd)
         }
     }
 
-
   if (1 == isatty (STDOUT_FILENO))
     stdout_is_a_tty = true;
   else
     stdout_is_a_tty = false;
 
-  if (they_chose_db)
-    splitstring (locate_path, path_separators, true,
-                 &path_element_pos, &path_element_len);
+  if (user_selected_locate_path)
+    {
+      splitstring (user_selected_locate_path, path_separators, true,
+		   &path_element_pos, &path_element_len);
+    }
 
   /* Bail out early if limit already reached. */
   while (!use_limit || limits.limit > limits.items_accepted)
@@ -1765,10 +1772,11 @@ dolocate (int argc, char **argv, int secure_db_fd)
       statistics.newline_count =
       statistics.highbit_filename_count = 0u;
 
-      if (they_chose_db)
+      if (user_selected_locate_path)
         {
           /* Take the next element from the list of databases */
-          if (1 == path_element_len && '-' == locate_path[path_element_pos])
+          if (1 == path_element_len
+	      && '-' == user_selected_locate_path[path_element_pos])
             {
               if (did_stdin)
                 {
@@ -1787,13 +1795,13 @@ dolocate (int argc, char **argv, int secure_db_fd)
             {
               if (0 == path_element_len
                   || (1 == path_element_len
-                      && '.' == locate_path[path_element_pos]))
+                      && '.' == user_selected_locate_path[path_element_pos]))
                 {
                   db_name = LOCATE_DB;
                 }
               else
                 {
-                  path_element = strndup (&locate_path[path_element_pos],
+                  path_element = strndup (&user_selected_locate_path[path_element_pos],
                                           path_element_len);
                   db_name = path_element;
                 }
@@ -1889,11 +1897,20 @@ dolocate (int argc, char **argv, int secure_db_fd)
           free (path_element);
           path_element = NULL;
         }
-      if (!splitstring (locate_path, path_separators, false,
-                        &path_element_pos, &path_element_len))
-        {
-          break;
-        }
+
+       if (!user_selected_locate_path)
+	 {
+	   /* We're not actually iterating through the values in
+	      $LOCATE_PATH so we don't want to check for the next
+	      element in user_selected_locate_path (since we manually set db_name =
+	      LOCATE_DB without using user_selected_locate_path). */
+	   break;
+	 }
+       else if (!splitstring (user_selected_locate_path, path_separators, false,
+			      &path_element_pos, &path_element_len))
+	 {
+	   break;
+	 }
     }
 
   if (just_count)