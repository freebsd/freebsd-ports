tracetop.cc:380:16: error: invalid suffix on literal; C++11 requires a space between literal and identifier [-Wreserved-user-defined-literal]
                                printw("%7"PRIu64"\t%7"PRIu64"\n",
                                           ^

--- tools/tracetop/tracetop.cc.orig	2018-08-25 19:01:36 UTC
+++ tools/tracetop/tracetop.cc
@@ -377,12 +377,12 @@ static void do_report()
 		}
 		switch (display_as) {
 			case BYTES:
-				printw("%7"PRIu64"\t%7"PRIu64"\n",
+				printw("%7" PRIu64 "\t%7" PRIu64 "\n",
 						pq.top().bytes,
 						pq.top().packets);
 				break;
 			case BITS_PER_SEC:
-				printw("%14.03f\t%"PRIu64"\n",
+				printw("%14.03f\t%" PRIu64 "\n",
 						8.0*pq.top().bytes/interval,
 						pq.top().packets);
 				break;
