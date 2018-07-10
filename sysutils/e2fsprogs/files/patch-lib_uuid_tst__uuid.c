--- lib/uuid/tst_uuid.c.orig	2018-07-10 05:14:26 UTC
+++ lib/uuid/tst_uuid.c
@@ -144,7 +144,7 @@ main(int argc ATTR((unused)) , char **ar
 	tv.tv_usec = 0;
 	time_reg = uuid_time(buf, &tv);
 	printf("UUID generated at %lu reports %lu (%ld.%ld)\n",
-	       time_gen, time_reg, tv.tv_sec, (long)tv.tv_usec);
+	       (unsigned long)time_gen, (unsigned long)time_reg, (long)tv.tv_sec, (long)tv.tv_usec);
 	/* allow 1s margin in case of rollover between sampling
 	 * the current time and when the UUID is generated. */
 	if (time_reg > time_gen + 1) {
