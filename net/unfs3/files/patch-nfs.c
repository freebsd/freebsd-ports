--- nfs.c.orig	2022-11-17 12:27:52 UTC
+++ nfs.c
@@ -209,7 +209,7 @@ LOOKUP3res *nfsproc3_lookup_3_svc(LOOKUP3args * argp, 
 		strcmp(argp->what.name, "..") == 0) {
 		fh = fh_comp_ptr(obj, rqstp, 0);
 	    } else {
-		gen = backend_get_gen(buf, FD_NONE, obj);
+		gen = backend_get_gen(buf, -1, obj);
 		fh = fh_extend(argp->what.dir, buf.st_dev, buf.st_ino, gen);
 		fh_cache_add(buf.st_dev, buf.st_ino, obj);
 	    }
