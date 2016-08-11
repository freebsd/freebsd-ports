--- header.c.orig	1996-06-04 13:36:56 UTC
+++ header.c
@@ -75,7 +75,7 @@ load_header(struct message *m)
     {
       buf = indata->contents + indata->offset;
 
-      if ((linelen = getline(indata)) == 0)
+      if ((linelen = get_line(indata)) == 0)
 	{
 	  /* End of data, illegal header */
 	  indata->offset = startoffset; /* Rewind */
