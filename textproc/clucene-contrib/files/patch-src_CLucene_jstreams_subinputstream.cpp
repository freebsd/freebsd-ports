--- src/CLucene/jstreams/subinputstream.cpp	Sat Feb 10 13:56:34 2007
+++ src/CLucene/jstreams/subinputstream.cpp.orig	Fri Nov 24 13:42:02 2006
@@ -31,7 +31,7 @@
     }
     int32_t nread = input->read(start, min, max);
     if (nread < -1) {
-        printf("substream too short.\n");
+        fprintf(stderr, "substream too short.\n");
         status = Error;
         error = input->getError();
     } else if (nread < min) {
@@ -42,9 +42,9 @@
                 size = position;
             }
         } else {
-            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! nread %i min %i max %i size %lli\n", nread, min, max, size);
-            printf("pos %lli parentpos %lli\n", position, input->getPosition());
-            printf("status: %i error: %s\n", input->getStatus(), input->getError());
+//            fprintf(stderr, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! nread %i min %i max %i size %lli\n", nread, min, max, size);
+//            fprintf(stderr, "pos %lli parentpos %lli\n", position, input->getPosition());
+//            fprintf(stderr, "status: %i error: %s\n", input->getStatus(), input->getError());
             // we expected data but didn't get enough so that's an error
             status = Error;
             error = "Premature end of stream\n";
@@ -59,21 +59,18 @@
     return nread;
 }
 int64_t
-SubInputStream::mark(int32_t readlimit) {
-    position = input->mark(readlimit) - offset;
-    return position;
-}
-int64_t
 SubInputStream::reset(int64_t newpos) {
-    //printf("subreset pos: %lli newpos: %lli offset: %lli\n", position,
-    //    newpos, offset);
+    assert(newpos >= 0);
+//    fprintf(stderr, "subreset pos: %lli newpos: %lli offset: %lli\n", position,
+//        newpos, offset);
     position = input->reset(newpos + offset);
     if (position < offset) {
-        printf("###########\n");
+        fprintf(stderr, "########### position %lli newpos %lli\n", position, newpos);
         status = Error;
         error = input->getError();
     } else {
         position -= offset;
+        status = input->getStatus();
     }
     return position;
 }
