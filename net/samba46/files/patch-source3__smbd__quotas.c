--- source3/smbd/quotas.c.orig	2017-01-11 07:55:15 UTC
+++ source3/smbd/quotas.c
@@ -125,6 +125,7 @@ static bool nfs_quotas(char *nfspath, ui
 	if (!cutstr)
 		return False;
 
+	memset(&D, '\0', sizeof(D));
 	memset(cutstr, '\0', len+1);
 	host = strncat(cutstr,mnttype, sizeof(char) * len );
 	DEBUG(5,("nfs_quotas: looking for mount on \"%s\"\n", cutstr));
@@ -133,7 +134,7 @@ static bool nfs_quotas(char *nfspath, ui
 	args.gqa_pathp = testpath+1;
 	args.gqa_uid = uid;
 
-	DEBUG(5,("nfs_quotas: Asking for host \"%s\" rpcprog \"%i\" rpcvers \"%i\" network \"%s\"\n", host, RQUOTAPROG, RQUOTAVERS, "udp"));
+	DEBUG(5,("nfs_quotas: Asking for host \"%s\" rpcprog \"%lu\" rpcvers \"%lu\" network \"%s\"\n", host, RQUOTAPROG, RQUOTAVERS, "udp"));
 
 	if ((clnt = clnt_create(host, RQUOTAPROG, RQUOTAVERS, "udp")) == NULL) {
 		ret = False;
