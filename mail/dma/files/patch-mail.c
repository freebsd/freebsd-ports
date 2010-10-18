--- ./mail.c.orig	2010-10-04 21:03:33.000000000 +0200
+++ ./mail.c	2010-10-18 13:34:03.222470911 +0200
@@ -415,7 +415,7 @@
 					snprintf(line, sizeof(line), "Message-Id: <%"PRIxMAX".%s.%"PRIxMAX"@%s>\n",
 						 (uintmax_t)time(NULL),
 						 queue->id,
-						 random(),
+						 (uintmax_t)random(),
 						 hostname());
 				} else if (!had_from) {
 					had_from = 1;
