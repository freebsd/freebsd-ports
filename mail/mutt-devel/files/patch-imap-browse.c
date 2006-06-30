--- imap/browse.c.orig
+++ imap/browse.c
@@ -505,7 +505,7 @@ static int browse_get_namespace (IMAP_DA
 	    if (*s == '\"')
 	    {
 	      s++;
-	      while (*s && *s != '\"') 
+	      while (*s && *s != '\"' && n < sizeof (ns) - 1) 
 	      {
 		if (*s == '\\')
 		  s++;
@@ -516,12 +516,14 @@ static int browse_get_namespace (IMAP_DA
 		s++;
 	    }
 	    else
-	      while (*s && !ISSPACE (*s)) 
+	      while (*s && !ISSPACE (*s) && n < sizeof (ns) - 1)
 	      {
 		ns[n++] = *s;
 		s++;
 	      }
 	    ns[n] = '\0';
+	    if (n == sizeof (ns) - 1)
+	      dprint (1, (debugfile, "browse_get_namespace: too long: [%s]\n", ns));
 	    /* delim? */
 	    s = imap_next_word (s);
 	    /* delimiter is meaningless if namespace is "". Why does

