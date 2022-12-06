--- src/lib-index/test-mail-index-transaction-update.c.orig	2022-06-14 06:55:03 UTC
+++ src/lib-index/test-mail-index-transaction-update.c
@@ -6,6 +6,7 @@
 #include "test-common.h"
 #include "mail-index-private.h"
 #include "mail-index-transaction-private.h"
+#include "utc-offset.h"
 
 #include <time.h>
 
@@ -630,7 +631,9 @@ static void test_mail_index_update_day_first_uid(void)
 
 	/* daylight savings times were confusing these tests, so we'll now
 	   just assume that TZ=UTC */
-	test_assert(timezone == 0);
+	time_t now = time(NULL);
+	struct tm *local_time = localtime(&now);
+	test_assert(utc_offset(local_time, now) == 0);
 
 	hdr.messages_count = 10;
 	t = mail_index_transaction_new();
@@ -645,13 +648,13 @@ static void test_mail_index_update_day_first_uid(void)
 		i_zero(&hdr);
 		for (j = 0; j < N_ELEMENTS(hdr.day_first_uid); j++)
 			hdr.day_first_uid[j] = 8-j;
-		hdr.day_stamp = tests[i].old_day_stamp + timezone;
+		hdr.day_stamp = tests[i].old_day_stamp;
 		memcpy(t->post_hdr_change, &hdr, sizeof(hdr));
-		mail_index_update_day_headers(t, tests[i].now + timezone);
+		mail_index_update_day_headers(t, tests[i].now);
 
 		struct mail_index_header new_hdr;
 		memcpy(&new_hdr, t->post_hdr_change, sizeof(new_hdr));
-		test_assert_idx(new_hdr.day_stamp == tests[i].new_day_stamp + timezone, i);
+		test_assert_idx(new_hdr.day_stamp == tests[i].new_day_stamp, i);
 		test_assert_idx(memcmp(new_hdr.day_first_uid,
 				       tests[i].new_day_first_uid,
 				       sizeof(uint32_t) * 8) == 0, i);
