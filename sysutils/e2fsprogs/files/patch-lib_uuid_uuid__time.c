--- lib/uuid/uuid_time.c.orig	2018-07-10 05:14:26 UTC
+++ lib/uuid/uuid_time.c
@@ -165,7 +165,7 @@ main(int argc, char **argv)
 		printf("Warning: not a time-based UUID, so UUID time "
 		       "decoding will likely not work!\n");
 	}
-	printf("UUID time is: (%ld, %ld): %s\n", tv.tv_sec, (long)tv.tv_usec,
+	printf("UUID time is: (%ld, %ld): %s\n", (long)tv.tv_sec, (long)tv.tv_usec,
 	       ctime(&time_reg));
 
 	return 0;
