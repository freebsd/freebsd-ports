--- support/ethertalk/aarpd_svc.c.orig	Sat Mar 20 13:48:32 2004
+++ support/ethertalk/aarpd_svc.c	Sat Mar 20 13:53:53 2004
@@ -40,7 +40,7 @@
 
 	switch (rqstp->rq_proc) {
 	case NULLPROC:
-		(void)svc_sendreply(transp, xdr_void, (char *)NULL);
+		(void)svc_sendreply(transp, (xdrproc_t)xdr_void, (char *)NULL);
 		return;
 
 	case AARP_RESOLVE:
@@ -74,16 +74,16 @@
 		return;
 	}
 	bzero((char *)&argument, sizeof(argument));
-	if (!svc_getargs(transp, xdr_argument, (caddr_t)&argument)) {
+	if (!svc_getargs(transp, (xdrproc_t)xdr_argument, (caddr_t)&argument)) {
 		svcerr_decode(transp);
 		return;
 	}
 	result = (*local)(&argument, rqstp);
 	if (result != NULL
-	 && !svc_sendreply(transp, xdr_result, (caddr_t)result)) {
+	 && !svc_sendreply(transp, (xdrproc_t)xdr_result, (caddr_t)result)) {
 		svcerr_systemerr(transp);
 	}
-	if (!svc_freeargs(transp, xdr_argument, (caddr_t)&argument)) {
+	if (!svc_freeargs(transp, (xdrproc_t)xdr_argument, (caddr_t)&argument)) {
 		(void)fprintf(stderr, "unable to free arguments\n");
 		exit(1);
 	}
