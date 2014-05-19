--- runtime/queue.c.ori	2013-05-24 20:22:54.000000000 -0600
+++ runtime/queue.c	2013-05-24 20:23:07.000000000 -0600
@@ -1449,7 +1449,7 @@
 DoDeleteBatchFromQStore(qqueue_t *pThis, int nElem)
 {
 	int i;
-	off64_t bytesDel;
+	off_t bytesDel;
 	DEFiRet;
 
 	ISOBJ_TYPE_assert(pThis, qqueue);
