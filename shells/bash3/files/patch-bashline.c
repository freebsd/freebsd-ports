--- bashline.c.deo	Tue May  7 12:52:42 2002
+++ bashline.c	Sun Sep  8 18:17:30 2002
@@ -1873,10 +1874,6 @@
     }
 }
 
-/* Define NO_FORCE_FIGNORE if you want to match filenames that would
-   otherwise be ignored if they are the only possible matches. */
-/* #define NO_FORCE_FIGNORE */
-
 /* If FIGNORE is set, then don't match files with the given suffixes when
    completing filenames.  If only one of the possibilities has an acceptable
    suffix, delete the others, else just return and let the completer
@@ -1901,10 +1898,15 @@
 {
   char **newnames;
   int idx, nidx;
-#ifdef NO_FORCE_FIGNORE
   char **oldnames;
   int oidx;
-#endif
+  char *no_force_fignore;
+
+
+/* Set NO_FORCE_FIGNORE if you want to match filenames that would
+   otherwise be ignored if they are the only possible matches. */
+  no_force_fignore = get_string_value ("NO_FORCE_FIGNORE");
+//fprintf(stderr, ">NO_FORCE_FIGNORE< is [%s]\n", no_force_fignore);
 
   /* If there is only one completion, see if it is acceptable.  If it is
      not, free it up.  In any case, short-circuit and return.  This is a
@@ -1912,13 +1914,12 @@
      if there is only one completion; it is the completion itself. */
   if (names[1] == (char *)0)
     {
-#ifndef NO_FORCE_FIGNORE
-      if ((*name_func) (names[0]) == 0)
-	{
-	  free (names[0]);
-	  names[0] = (char *)NULL;
-	}
-#endif
+      if (!no_force_fignore)
+	if ((*name_func) (names[0]) == 0)
+	  {
+	    free (names[0]);
+	    names[0] = (char *)NULL;
+	  }
       return;
     }
 
@@ -1927,10 +1928,11 @@
   for (nidx = 1; names[nidx]; nidx++)
     ;
   newnames = strvec_create (nidx + 1);
-#ifdef NO_FORCE_FIGNORE
-  oldnames = strvec_create (nidx - 1);
-  oidx = 0;
-#endif
+  if (no_force_fignore)
+    {
+      oldnames = strvec_create (nidx - 1);
+      oidx = 0;
+    }
 
   newnames[0] = names[0];
   for (idx = nidx = 1; names[idx]; idx++)
@@ -1938,11 +1940,10 @@
       if ((*name_func) (names[idx]))
 	newnames[nidx++] = names[idx];
       else
-#ifndef NO_FORCE_FIGNORE
-	free (names[idx]);
-#else
-	oldnames[oidx++] = names[idx];
-#endif
+	if (no_force_fignore)
+	  oldnames[oidx++] = names[idx];
+	else
+	  free (names[idx]);
     }
 
   newnames[nidx] = (char *)NULL;
@@ -1950,21 +1951,23 @@
   /* If none are acceptable then let the completer handle it. */
   if (nidx == 1)
     {
-#ifndef NO_FORCE_FIGNORE
-      free (names[0]);
-      names[0] = (char *)NULL;
-#else
-      free (oldnames);
-#endif
+      if (no_force_fignore)
+        free (oldnames);
+      else
+	{
+	  free (names[0]);
+	  names[0] = (char *)NULL;
+	}
       free (newnames);
       return;
     }
 
-#ifdef NO_FORCE_FIGNORE
-  while (oidx)
-    free (oldnames[--oidx]);
-  free (oldnames);
-#endif
+  if (no_force_fignore)
+    {
+      while (oidx)
+	free (oldnames[--oidx]);
+      free (oldnames);
+    }
 
   /* If only one is acceptable, copy it to names[0] and return. */
   if (nidx == 2)
