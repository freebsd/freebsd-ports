--- ./source3/smbd/quotas.c.orig	2010-04-01 15:26:22.000000000 +0200
+++ ./source3/smbd/quotas.c	2010-04-23 01:08:35.000000000 +0200
@@ -1035,6 +1035,7 @@
 	if (!cutstr)
 		return False;
 
+	memset(&D, '\0', sizeof(D));
 	memset(cutstr, '\0', len+1);
 	host = strncat(cutstr,mnttype, sizeof(char) * len );
 	DEBUG(5,("nfs_quotas: looking for mount on \"%s\"\n", cutstr));
@@ -1043,7 +1044,7 @@
 	args.gqa_pathp = testpath+1;
 	args.gqa_uid = uid;
 
-	DEBUG(5,("nfs_quotas: Asking for host \"%s\" rpcprog \"%i\" rpcvers \"%i\" network \"%s\"\n", host, RQUOTAPROG, RQUOTAVERS, "udp"));
+	DEBUG(5,("nfs_quotas: Asking for host \"%s\" rpcprog \"%lu\" rpcvers \"%lu\" network \"%s\"\n", host, RQUOTAPROG, RQUOTAVERS, "udp"));
 
 	if ((clnt = clnt_create(host, RQUOTAPROG, RQUOTAVERS, "udp")) == NULL) {
 		ret = False;
