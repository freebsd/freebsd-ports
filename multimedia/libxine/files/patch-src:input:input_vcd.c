--- src/input/input_vcd.c.orig	Sat Jan 11 23:50:19 2003
+++ src/input/input_vcd.c	Sat Jan 11 23:54:36 2003
@@ -398,7 +398,7 @@
     return 0;
 
   do {
-    if (lseek (this->fd, this->cur_sector * bsize, SEEK_SET) == -1) {
+    if (lseek (this->fd, this->cls->cur_sector * bsize, SEEK_SET) == -1) {
       printf ("input_vcd: seek error %d\n", errno);
       return 0;
     }
@@ -406,7 +406,7 @@
       printf ("input_vcd: read error %d\n", errno);
       return 0;
     }
-    this->cur_sector++;
+    this->cls->cur_sector++;
   } while ((data.subheader[2]&~0x01)==0x60);
   memcpy (buf, data.data, VCDSECTORSIZE);
   return VCDSECTORSIZE;
@@ -538,7 +538,7 @@
     return NULL;
 
   do {
-    if (lseek (this->fd, this->cur_sector * bsize, SEEK_SET) == -1) {
+    if (lseek (this->fd, this->cls->cur_sector * bsize, SEEK_SET) == -1) {
       printf ("input_vcd: seek error %d\n", errno);
       return NULL;
     }
@@ -546,7 +546,7 @@
       printf ("input_vcd: read error %d\n", errno);
       return NULL;
     }
-    this->cur_sector++;
+    this->cls->cur_sector++;
   } while ((data.subheader[2]&~0x01)==0x60);
 
   buf = fifo->buffer_pool_alloc (fifo);
@@ -695,7 +695,7 @@
 
   start = 
     ntohl(this->cls->tocent
-	  [this->cur_track+1 - this->tochdr.starting_track].addr.lba);
+	  [this->cur_track+1 - this->cls->tochdr.starting_track].addr.lba);
 
   /*  printf("seek: start sector:%lu, origin: %d, offset:%qu\n", 
 	 start, origin, offset);
@@ -704,14 +704,14 @@
   switch (origin) {
   case SEEK_SET:
     dist = offset / VCDSECTORSIZE;
-    this->cur_sector = start + dist;
+    this->cls->cur_sector = start + dist;
     break;
   case SEEK_CUR:
 
     if (offset) 
       printf ("input_vcd: SEEK_CUR not implemented for offset != 0\n");
 
-    sector_pos = this->cur_sector;
+    sector_pos = this->cls->cur_sector;
 
     return sector_pos * VCDSECTORSIZE;
 
@@ -761,10 +761,10 @@
   len = 
     ntohl(this->cls->tocent
 	  [this->cur_track+2 
-	  - this->tochdr.starting_track].addr.lba)
+	  - this->cls->tochdr.starting_track].addr.lba)
     - ntohl(this->cls->tocent
 	    [this->cur_track+1 
-	    - this->tochdr.starting_track].addr.lba);
+	    - this->cls->tochdr.starting_track].addr.lba);
   
   return len * 2352; /*VCDSECTORSIZE;*/
 
@@ -888,9 +888,9 @@
       return 0;
     }
   
-    this->cur_sector = 
+    this->cls->cur_sector = 
       ntohl(this->cls->tocent
-	    [this->cur_track+1 - this->tochdr.starting_track].addr.lba);
+	    [this->cur_track+1 - this->cls->tochdr.starting_track].addr.lba);
     
   }
 #endif
