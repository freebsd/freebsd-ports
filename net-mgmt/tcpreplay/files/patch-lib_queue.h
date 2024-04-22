--- lib/queue.h.orig	2024-03-24 16:55:28 UTC
+++ lib/queue.h
@@ -36,8 +36,8 @@
  *	@(#)queue.h	8.5 (Berkeley) 8/20/94
  */

-#ifndef	_SYS_QUEUE_H_
-#define	_SYS_QUEUE_H_
+#ifndef	_QUEUE_H_
+#define	_QUEUE_H_

 /*
  * This file defines five types of data structures: singly-linked lists,
@@ -508,4 +508,4 @@ struct {								\
		(elm2)->field.cqe_prev->field.cqe_next = (elm2);	\
 } while (0)

-#endif /* !_SYS_QUEUE_H_ */
+#endif /* !_QUEUE_H_ */
