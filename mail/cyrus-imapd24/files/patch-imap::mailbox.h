--- imap/mailbox.h	2003/03/12 16:38:13	1.68.4.9
+++ imap/mailbox.h	2003/03/31 20:33:45	1.68.4.10
@@ -1,5 +1,5 @@
 /* mailbox.h -- Mailbox format definitions
- * $Id: mailbox.h,v 1.68.4.9 2003/03/12 16:38:13 ken3 Exp $
+ * $Id: mailbox.h,v 1.68.4.10 2003/03/31 20:33:45 ken3 Exp $
  *
  * Copyright (c) 1998-2003 Carnegie Mellon University.  All rights reserved.
  *
@@ -269,7 +269,7 @@
 				     unsigned msgno,
 				     struct index_record *record);
 extern int mailbox_read_quota(struct quota *quota);
-extern void mailbox_hash_quota(char *buf, unsigned size, const char *qr);
+extern void mailbox_hash_quota(char *buf, size_t size, const char *qr);
 extern int mailbox_lock_header(struct mailbox *mailbox);
 extern int mailbox_lock_index(struct mailbox *mailbox);
 extern int mailbox_lock_pop(struct mailbox *mailbox);
