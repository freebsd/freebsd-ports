--- src/select.c.orig	Thu Dec 16 02:04:56 1999
+++ src/select.c	Sat Aug 21 12:05:31 2004
@@ -131,6 +131,36 @@
   return 1;
 }
 
+/* escapes the name of a file so that the shell groks it in 'single' q.marks. 
+   The resulting pointer has to be free()ed when not longer used. */
+char *
+shell_escape(const char *fn)
+{
+  size_t len = 0;
+  const char *inp;
+  char *retval, *outp;
+
+  for(inp = fn; *inp; ++inp)
+    switch(*inp)
+    {
+      case '\'': len += 4; break;
+      default:   len += 1; break;
+    }
+
+  outp = retval = malloc(len + 1);
+  if(!outp)
+    return NULL; /* perhaps one should do better error handling here */
+  for(inp = fn; *inp; ++inp)
+    switch(*inp)
+    {
+      case '\'': *outp++ = '\''; *outp++ = '\\'; *outp++ = '\'', *outp++ = '\''; break;
+      default:   *outp++ = *inp; break;
+    }
+  *outp = 0;
+
+  return retval;
+}
+
 /* What says file about the type of a file (result is malloc'd).  NULL
   if could not be run.  */
 
@@ -144,11 +174,15 @@
   if (IS_EMPTY (job->file_command))
     return NULL;
 
+  filename = shell_escape(filename);
+  if(filename == NULL)
+    return NULL;
   /* Call file(1) with the correct option */
-  command = ALLOCA (char, (2
+  command = ALLOCA (char, (4
 			   + strlen (job->file_command)
 			   + ustrlen (filename)));
-  sprintf (command, "%s %s", job->file_command, (const char *) filename);
+  sprintf (command, "%s '%s'", job->file_command, (const char *) filename);
+  free(filename);
   message (msg_tool, (stderr, "Reading pipe: `%s'\n", command));
   file_out = popen (command, "r");
 
