--- source3/lib/sysquotas_nfs.c.orig	2013-11-05 12:08:05.568859038 +0000
+++ source3/lib/sysquotas_nfs.c	2013-11-05 12:08:28.560058330 +0000
@@ -154,7 +154,7 @@
 	gq_args.gqa_uid = id.uid;
 
 	DEBUG(10, ("sys_get_nfs_quotas: Asking for quota of path '%s' on "
-		   "host '%s', rpcprog '%i', rpcvers '%i', network '%s'\n",
+		   "host '%s', rpcprog '%li', rpcvers '%li', network '%s'\n",
 		    host, testpath+1, RQUOTAPROG, RQUOTAVERS, "udp"));
 
 	clnt = clnt_create(host, RQUOTAPROG, RQUOTAVERS, "udp");
