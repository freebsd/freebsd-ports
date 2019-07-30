commit a368e0cbfb33d3050dcccccf0bf5a5539d3dac39
Author: Theodore Ts'o <tytso@mit.edu>
Date:   Wed Jul 24 22:25:11 2019 -0400

    e2fsck: set E2FSCK_TIME correctly on a 32-bit arch with a 64-bit time_t
    
    Addresses-Debian-Bug: #932906
    
    Signed-off-by: Theodore Ts'o <tytso@mit.edu>

--- e2fsck/e2fsck.c.orig	2019-07-15 01:03:14 UTC
+++ e2fsck/e2fsck.c
@@ -37,7 +37,7 @@ errcode_t e2fsck_allocate_context(e2fsck_t *ret)
 
 	time_env = getenv("E2FSCK_TIME");
 	if (time_env)
-		context->now = strtoul(time_env, NULL, 0);
+		context->now = (time_t) strtoull(time_env, NULL, 0);
 	else {
 		context->now = time(0);
 		if (context->now < 1262322000) /* January 1 2010 */
