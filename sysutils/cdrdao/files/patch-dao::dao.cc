--- dao/dao.cc.orig	Thu Feb 12 02:13:31 2004
+++ dao/dao.cc	Tue Mar  2 17:22:11 2004
@@ -388,10 +388,10 @@
         if (cdr->readBufferCapacity(&totalcap, &availcap)) {
           writerFill = (int)((1.0 - ((double)availcap / (double)totalcap))
                              * 100.0);
-          message(1, "Wrote %ld of %ld MB (Buffers %3d%% %3d%%).\n",
+          message(1, "Wrote %ld of %ld MB (Buffers %3d%% %3d%%).\r",
                   cnt >> 20, total >> 20, buffFill, writerFill);
         } else {
-          message(1, "Wrote %ld of %ld MB (Buffer %3d%%).\n",
+          message(1, "Wrote %ld of %ld MB (Buffer %3d%%).\r",
                   cnt >> 20, total >> 20, buffFill);
         }
         lastMb = cntMb;
