--- crypto.c.orig	Tue Jan 20 09:54:51 1998
+++ crypto.c	Sun Dec  8 11:43:11 2002
@@ -181,7 +181,7 @@
 	if (timestamp != NULL) {
 		/* first, fill array in external byte order: */
 		put_word32(t, timestamp);
-		convert_byteorder(timestamp,4);
+		convert_byteorder(timestamp,SIZEOF_TIMESTAMP);
 				/* convert to internal byteorder */
 	}
 
@@ -850,11 +850,11 @@
    LANG("\n\007Error: System clock/calendar is set wrong.\n"));
 			return -1;
 		}
-		convert_byteorder(timestamp,4); /* convert to external form */
+		convert_byteorder(timestamp,SIZEOF_TIMESTAMP); /* convert to external form */
 
 	/* Finish off message digest calculation with this information */
 	MD_addbuffer (MD, &class, 1, 0);
-	MD_addbuffer (MD, timestamp, 4, md5buf);
+	MD_addbuffer (MD, timestamp, SIZEOF_TIMESTAMP, md5buf);
 /* We wrote the digest to a static variable because we want to keep it around
    for random number generation later.   Also make a note of that fact. */
 	already_have_md5 = 1;
