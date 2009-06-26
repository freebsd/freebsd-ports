--- ./smbd/quotas.c.orig	2009-06-22 21:05:38.000000000 +0000
+++ ./smbd/quotas.c	2009-06-25 20:49:35.000000000 +0000
@@ -1023,6 +1023,8 @@
 	enum clnt_stat clnt_stat;
 	bool ret = True;
 
+	memset(&D, 0, sizeof(D));
+	
 	*bsize = *dfree = *dsize = (SMB_BIG_UINT)0;
 
 	len=strcspn(mnttype, ":");
@@ -1039,7 +1041,7 @@
 	args.gqa_pathp = testpath+1;
 	args.gqa_uid = uid;
 
-	DEBUG(5,("nfs_quotas: Asking for host \"%s\" rpcprog \"%i\" rpcvers \"%i\" network \"%s\"\n", host, RQUOTAPROG, RQUOTAVERS, "udp"));
+	DEBUG(5,("nfs_quotas: Asking for host \"%s\" rpcprog \"%lu\" rpcvers \"%lu\" network \"%s\"\n", host, RQUOTAPROG, RQUOTAVERS, "udp"));
 
 	if ((clnt = clnt_create(host, RQUOTAPROG, RQUOTAVERS, "udp")) == NULL) {
 		ret = False;
