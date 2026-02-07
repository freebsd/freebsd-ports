--- uuencode.c.orig	1996-06-04 13:37:02 UTC
+++ uuencode.c
@@ -116,7 +116,7 @@ encode_uuencode(struct message *m)
   /* Start with uuencode preamble */
   fix_filename(m);
 
-  sprintf(outb,"begin 644 %s\n", m->sd->name);
+  snprintf(outb, sizeof(outb), "begin 644 %s\n", m->sd->name);
   append_data(outbuf, outb, strlen(outb), pz);
   outbuf->lineend += 1;
   i = 0;
@@ -242,7 +242,7 @@ decode_uuencode(struct message *m)
       inb++;
       inbuf->offset += 1;
     }
-  if ((i = sscanf(inb, "begin%*1[ ]%*3[0-7]%*1[ ]%s", filename)) != 1)
+  if ((i = sscanf(inb, "begin%*1[ ]%*3[0-7]%*1[ ]%511s", filename)) != 1)
     {
 #ifdef DEBUG
       if (edebug)
@@ -290,7 +290,7 @@ decode_uuencode(struct message *m)
 	  /* Check for end */
 	  if (strncmp(inb, "end", 3) == 0)
 	    {
-	      inbuf->offset += getline(inbuf);
+	      inbuf->offset += get_line(inbuf);
 	      inbuf->loffset += 1;
 	      inbuf->bodyend = inbuf->offset;
 	      if (process)
