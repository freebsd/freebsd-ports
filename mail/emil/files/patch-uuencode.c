--- uuencode.c.orig	1996-06-04 15:37:02.000000000 +0200
+++ uuencode.c	2011-07-25 20:21:13.000000000 +0200
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
