--- lib/queue.h.orig	2025-08-27 06:21:35 UTC
+++ lib/queue.h
@@ -36,7 +36,8 @@
  *	@(#)queue.h	8.5 (Berkeley) 8/20/94
  */
 
-#pragma once
+#ifndef	_SYS_QUEUE_H_
+#define	_SYS_QUEUE_H_
 
 /*
  * This file defines five types of data structures: singly-linked lists, 
@@ -506,3 +507,5 @@ struct {								\
 	else								\
 		(elm2)->field.cqe_prev->field.cqe_next = (elm2);	\
 } while (0)
+
+#endif /* !_SYS_QUEUE_H_ */
