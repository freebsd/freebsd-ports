--- idx2ldif.c.orig	Thu Feb  5 01:02:52 2004
+++ idx2ldif.c	Thu Feb 26 16:03:58 2004
@@ -35,6 +35,7 @@
   unsigned long filelen;
   char* fn=argc<2?"data":argv[1];
   char* map=mmap_read(fn,&filelen);
+  uint32 magic,attribute_count,record_count,indices_offset,size_of_string_table;
   if (!map) {
     buffer_puts(buffer_2,"could not open ");
     buffer_puts(buffer_2,fn);
@@ -43,7 +44,6 @@
     buffer_putnlflush(buffer_2);
     return 1;
   }
-  uint32 magic,attribute_count,record_count,indices_offset,size_of_string_table;
   uint32_unpack(map,&magic);
   uint32_unpack(map+4,&attribute_count);
   uint32_unpack(map+2*4,&record_count);
