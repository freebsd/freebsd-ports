--- src/complete.c.orig	Wed Nov 13 08:56:41 2002
+++ src/complete.c	Tue Jun 15 03:15:09 2004
@@ -270,7 +270,7 @@
 	*temp = '$';
 	if (isbrace)
 	    temp [1] = '{';
-        strncpy (temp + 1 + isbrace, *env_p, p - *env_p);
+        memcpy (temp + 1 + isbrace, *env_p, p - *env_p);
         if (isbrace)
             strcpy (temp + 2 + (p - *env_p), "}");
         else
@@ -605,8 +605,7 @@
 	    matches = i;
             match_list [matches + 1] = NULL;
 	    match_list[0] = g_malloc (low + 1);
-	    strncpy (match_list[0], match_list[1], low);
-	    match_list[0][low] = 0;
+	    g_strlcpy (match_list[0], match_list[1], low + 1);
 	}
     } else {				/* There were no matches. */
         g_free (match_list);
@@ -806,7 +805,7 @@
 	    	*(p++) = *(q++);
 	    *p = 0;
 	}
-	strncpy (in->buffer + start, text, len - start + end);
+	memcpy (in->buffer + start, text, len - start + end);
 	in->point += len;
 	update_input (in, 1);
 	end += len;
