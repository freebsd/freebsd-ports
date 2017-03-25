--- source3/smbd/quotas.c.orig	2016-09-22 06:42:48 UTC
+++ source3/smbd/quotas.c
@@ -144,6 +144,7 @@ static bool nfs_quotas(char *nfspath, ui
 	if (!cutstr)
 		return False;
 
+	memset(&D, '\0', sizeof(D));
 	memset(cutstr, '\0', len+1);
 	host = strncat(cutstr,mnttype, sizeof(char) * len );
 	DEBUG(5,("nfs_quotas: looking for mount on \"%s\"\n", cutstr));
@@ -152,7 +153,7 @@ static bool nfs_quotas(char *nfspath, ui
 	args.gqa_pathp = testpath+1;
 	args.gqa_uid = uid;
 
-	DEBUG(5,("nfs_quotas: Asking for host \"%s\" rpcprog \"%i\" rpcvers \"%i\" network \"%s\"\n", host, RQUOTAPROG, RQUOTAVERS, "udp"));
+	DEBUG(5,("nfs_quotas: Asking for host \"%s\" rpcprog \"%lu\" rpcvers \"%lu\" network \"%s\"\n", host, RQUOTAPROG, RQUOTAVERS, "udp"));
 
 	if ((clnt = clnt_create(host, RQUOTAPROG, RQUOTAVERS, "udp")) == NULL) {
 		ret = False;
