--- support/ethertalk/aarpd_clnt.c.orig	Sat Mar 20 12:58:10 2004
+++ support/ethertalk/aarpd_clnt.c	Sat Mar 20 13:12:03 2004
@@ -32,8 +32,8 @@
 {
 	static etheraddr res;
 	bzero((char *)res, sizeof(res));
-	if (clnt_call(clnt, AARP_RESOLVE, xdr_int, (caddr_t)argp,
-	    xdr_etheraddr, (char *)res, TIMEOUT) != RPC_SUCCESS) {
+	if (clnt_call(clnt, AARP_RESOLVE, (xdrproc_t)xdr_int, (caddr_t)argp,
+	    (xdrproc_t)xdr_etheraddr, (char *)res, TIMEOUT) != RPC_SUCCESS) {
 		return (NULL);
 	}
 	return (res);
@@ -50,8 +50,8 @@
 {
 	static bridgeaddr res;
 	bzero((char *)res, sizeof(res));
-	if (clnt_call(clnt, RTMP_GETBADDR, xdr_int, (caddr_t)argp,
-	    xdr_bridgeaddr, (char *)res, TIMEOUT) != RPC_SUCCESS) {
+	if (clnt_call(clnt, RTMP_GETBADDR, (xdrproc_t)xdr_int, (caddr_t)argp,
+	    (xdrproc_t)xdr_bridgeaddr, (char *)res, TIMEOUT) != RPC_SUCCESS) {
 		return (NULL);
 	}
 	return (res);
@@ -68,8 +68,8 @@
 {
 	static bridgeaddr res;
 	bzero((char *)res, sizeof(res));
-	if (clnt_call(clnt, RTMP_SETBADDR, xdr_int, (caddr_t)argp,
-	    xdr_bridgeaddr, (char *)res, TIMEOUT) != RPC_SUCCESS) {
+	if (clnt_call(clnt, RTMP_SETBADDR, (xdrproc_t)xdr_int, (caddr_t)argp,
+	    (xdrproc_t)xdr_bridgeaddr, (char *)res, TIMEOUT) != RPC_SUCCESS) {
 		return (NULL);
 	}
 	return (res);
@@ -87,8 +87,8 @@
 {
 	static bridgeaddr res;	/* convenient size */
 	bzero((char *)res, sizeof(res));
-	if (clnt_call(clnt, NET_RANGE_SET, xdr_int, (caddr_t)argp,
-	    xdr_bridgeaddr, (char *)res, TIMEOUT) != RPC_SUCCESS) {
+	if (clnt_call(clnt, NET_RANGE_SET, (xdrproc_t)xdr_int, (caddr_t)argp,
+	    (xdrproc_t)xdr_bridgeaddr, (char *)res, TIMEOUT) != RPC_SUCCESS) {
 		return (NULL);
 	}
 	return (res);
