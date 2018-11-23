--- src/lib-master/test-event-stats.c.orig	2018-11-23 11:06:49 UTC
+++ src/lib-master/test-event-stats.c
@@ -12,6 +12,7 @@
 #include "stats-client.h"
 #include "test-common.h"
 #include <fcntl.h>
+#include <signal.h>
 #include <unistd.h>
 #include <sys/socket.h>
 #include <sys/un.h>
@@ -360,7 +361,7 @@ static void test_no_merging2(void)
 	event_unref(&child_ev);
 	test_assert(
 		compare_test_stats_to(
-			"EVENT	%lu	1	0	0"
+			"EVENT	%"PRIu64"	1	0	0"
 			"	stest-event-stats.c	%d"
 			"	l0	0	ctest2\n", id, l));
 	test_end();
@@ -386,12 +387,12 @@ static void test_no_merging3(void)
 	event_unref(&child_ev);
 	test_assert(
 		compare_test_stats_to(
-			"BEGIN	%lu	0	1	0	0"
+			"BEGIN	%"PRIu64"	0	1	0	0"
 			"	stest-event-stats.c	%d	ctest1\n"
-			"EVENT	%lu	1	1	0"
+			"EVENT	%"PRIu64"	1	1	0"
 			"	stest-event-stats.c	%d"
 			"	l1	0	ctest2\n"
-			"END\t%lu\n", idp, lp, idp, l, idp));
+			"END\t%"PRIu64"\n", idp, lp, idp, l, idp));
 	test_end();
 }
 
@@ -451,7 +452,7 @@ static void test_merge_events2(void)
 	event_unref(&merge_ev2);
 	test_assert(
 		compare_test_stats_to(
-			"EVENT	%lu	1	0	0"
+			"EVENT	%"PRIu64"	1	0	0"
 			"	stest-event-stats.c	%d	l0	0"
 			"	ctest3	ctest2	ctest1	Tkey3"
 			"	10	0	Ikey2	20"
@@ -483,11 +484,11 @@ static void test_skip_parents(void)
 	event_unref(&child_ev);
 	test_assert(
 		compare_test_stats_to(
-			"BEGIN	%lu	0	1	0	0"
+			"BEGIN	%"PRIu64"	0	1	0	0"
 			"	stest-event-stats.c	%d	ctest1\n"
-			"EVENT	%lu	1	3	0	"
+			"EVENT	%"PRIu64"	1	3	0	"
 			"stest-event-stats.c	%d	l3	0"
-			"	ctest2\nEND\t%lu\n", id, lp, id, l, id));
+			"	ctest2\nEND\t%"PRIu64"\n", id, lp, id, l, id));
 	test_end();
 }
 
@@ -525,12 +526,12 @@ static void test_merge_events_skip_parents(void)
 	event_unref(&child2_ev);
 	test_assert(
 		compare_test_stats_to(
-			"BEGIN	%lu	0	1	0	0"
+			"BEGIN	%"PRIu64"	0	1	0	0"
 			"	stest-event-stats.c	%d	ctest1\n"
-			"EVENT	%lu	1	3	0	"
+			"EVENT	%"PRIu64"	1	3	0	"
 			"stest-event-stats.c	%d	l3	0	"
 			"ctest4	ctest5	Tkey3	10	0	Skey4"
-			"	str4\nEND\t%lu\n", id, lp, id, l, id));
+			"	str4\nEND\t%"PRIu64"\n", id, lp, id, l, id));
 	test_end();
 }
 
