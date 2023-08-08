--- core/src/dird/catreq.cc	2022-01-21 09:00:16.883799000 -0500
+++ core/src/dird/catreq.cc	2022-01-21 09:02:08.619060000 -0500
@@ -656,7 +656,7 @@
   bool retval = false;
   int32_t pktsiz;
   size_t nbytes;
-  ssize_t size = 0;
+//  ssize_t size = 0;
   int32_t message_length; /* message length */
   int spool_fd = -1;
   POOLMEM* msg = GetPoolMemory(PM_MESSAGE);
@@ -680,7 +680,7 @@
 
   while ((nbytes = read(spool_fd, (char*)&pktsiz, sizeof(int32_t)))
          == sizeof(int32_t)) {
-    size += sizeof(int32_t);
+    //size += sizeof(int32_t);
     message_length = ntohl(pktsiz);
 
     if (message_length > 0) {
@@ -697,7 +697,7 @@
         goto bail_out;
       }
       msg[nbytes] = '\0';
-      size += nbytes;
+      //size += nbytes;
     }
 
     if (!jcr->IsJobCanceled()) {
