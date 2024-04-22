From d9b3c922d664d03100b9f37da129b382054ea3b2 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?G=C3=A1bor=20Cs=C3=A1rdi?= <csardi.gabor@gmail.com>
Date: Fri, 9 Feb 2024 18:31:01 -0500
Subject: [PATCH] Fix a buffer overflow

It happens if raw_str_used underflows and ends up a very large number,
which is then used as the size of a string.

Closes #285.

https://github.com/WizardMac/ReadStat/issues/285
https://github.com/WizardMac/ReadStat/pull/311

--- src/spss/readstat_sav_read.c.orig	2023-01-15 21:33:14 UTC
+++ src/spss/readstat_sav_read.c
@@ -717,7 +717,7 @@ static readstat_error_t sav_process_row(unsigned char 
             }
             if (++offset == col_info->width) {
                 if (++segment_offset < var_info->n_segments) {
-                    raw_str_used--;
+                    if (raw_str_used > 0) raw_str_used--;
                 }
                 offset = 0;
                 col++;
