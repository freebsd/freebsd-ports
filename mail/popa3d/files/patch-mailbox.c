--- mailbox.c.old	Sun Sep  8 13:52:57 2002
+++ mailbox.c	Sun Jan 26 07:30:26 2003
@@ -227,6 +227,7 @@
 				if (!msg.data_offset) break;
 				msg.raw_size = offset - msg.raw_offset;
 				msg.data_size = offset - body - msg.data_offset;
+				msg.size -= body << 1;
 				MD5_Final(msg.hash, &hash);
 				if (db_op(&msg)) break;
 			}
@@ -319,6 +320,7 @@
 		if (!msg.data_offset) return 1;
 		msg.raw_size = offset - msg.raw_offset;
 		msg.data_size = offset - (blank & body) - msg.data_offset;
+		msg.size -= (blank & body) << 1;
 		MD5_Final(msg.hash, &hash);
 		if (db_op(&msg)) return 1;
 
