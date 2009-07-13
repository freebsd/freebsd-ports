--- fuse_module/fuse_io.c.orig	2008-02-05 00:25:57.000000000 -0500
+++ fuse_module/fuse_io.c	2009-07-13 09:31:24.000000000 -0400
@@ -35,6 +35,10 @@
 #include <vm/vnode_pager.h>
 #include <vm/vm_object.h>
 
+#if (__FreeBSD__ >= 8)
+#define vfs_bio_set_validclean vfs_bio_set_valid
+#endif
+
 #include "fuse.h"
 #include "fuse_session.h"
 #include "fuse_vnode.h"
@@ -157,7 +161,11 @@
 		goto out;
 
 	if (uio->uio_rw == UIO_WRITE && fp->f_flag & O_APPEND) {
-		if ((err = VOP_GETATTR(vp, &va, cred, td)))
+		if ((err = VOP_GETATTR(vp, &va, cred
+#if VOP_GETATTR_TAKES_THREAD
+		    , td
+#endif
+		    )))
 			goto out;
 		uio->uio_offset = va.va_size;
 	} else if ((flags & FOF_OFFSET) == 0)
@@ -227,7 +235,7 @@
 		return (0);
 
 	biosize = vp->v_mount->mnt_stat.f_iosize;
-	bcount = min(MAXBSIZE, biosize);
+	bcount = MIN(MAXBSIZE, biosize);
 
 	DEBUG2G("entering loop\n");
 	do {
@@ -352,7 +360,7 @@
 		fri = fdi.indata;
 		fri->fh = fufh->fh_id;
 		fri->offset = uio->uio_offset;
-		fri->size = min(uio->uio_resid,
+		fri->size = MIN(uio->uio_resid,
 		                fusefs_get_data(vp->v_mount)->max_read);
 	
 		DEBUG2G("fri->fh %llu, fri->offset %d, fri->size %d\n",
@@ -399,7 +407,7 @@
 	while (uio->uio_resid > 0) {
 		int transfersize;
 
-		chunksize = min(iov->iov_len, nmax);
+		chunksize = MIN(iov->iov_len, nmax);
 
 		if (uio->uio_rw == UIO_READ) {
 			struct fuse_read_in *fri;
@@ -464,7 +472,7 @@
 {
 		int err;
 
-		if ((err = uiomove(buf, min(reqsize, bufsize), uio)))
+		if ((err = uiomove(buf, MIN(reqsize, bufsize), uio)))
 			return (err);
 
 		if (bufsize < reqsize)
@@ -502,7 +510,7 @@
 	}
 
 	while (uio->uio_resid > 0) {
-		chunksize = min(uio->uio_resid,
+		chunksize = MIN(uio->uio_resid,
 		                fusefs_get_data(vp->v_mount)->max_write);
 
 		fdi.iosize = sizeof(*fwi) + chunksize;
@@ -569,7 +577,7 @@
 	do {
 		lbn = uio->uio_offset / biosize;
 		on = uio->uio_offset & (biosize-1);
-		n = min((unsigned)(biosize - on), uio->uio_resid);
+		n = MIN((unsigned)(biosize - on), uio->uio_resid);
 		
 		DEBUG2G("lbn %d, on %d, n %d, uio offset %d, uio resid %d\n",
 		        (int)lbn, on, n, (int)uio->uio_offset, uio->uio_resid);
@@ -739,8 +747,8 @@
 		 */
 		if (n) {
 			if (bp->b_dirtyend > 0) {
-				bp->b_dirtyoff = min(on, bp->b_dirtyoff);
-				bp->b_dirtyend = max((on + n), bp->b_dirtyend);
+				bp->b_dirtyoff = MIN(on, bp->b_dirtyoff);
+				bp->b_dirtyend = MAX((on + n), bp->b_dirtyend);
 			} else {
 				bp->b_dirtyoff = on;
 				bp->b_dirtyend = on + n;
@@ -823,7 +831,11 @@
 #if FUSELIB_CONFORM_BIOREAD
 		struct vattr va;
 
-		if ((err = VOP_GETATTR(vp, &va, cred, curthread)))
+		if ((err = VOP_GETATTR(vp, &va, cred
+#if VOP_GETATTR_TAKES_THREAD
+		    , curthread
+#endif
+		    )))
 			goto out;
 #endif
 
@@ -831,7 +843,7 @@
 		bp->b_resid = bp->b_bcount;
 		while (bp->b_resid > 0) {
 			DEBUG2G("starting bio with resid %ld\n", bp->b_resid);	
-			chunksize = min(bp->b_resid,
+			chunksize = MIN(bp->b_resid,
 			                fusefs_get_data(vp->v_mount)->max_read);
 			fdi.iosize = sizeof(*fri);
 			if (! op)
@@ -842,8 +854,8 @@
 			fri->fh = fufh->fh_id;
 			fri->offset = ((off_t)bp->b_blkno) * biosize + ioff;
 #if FUSELIB_CONFORM_BIOREAD
-			chunksize = min(chunksize,
-			                min(fri->offset + bp->b_resid,
+			chunksize = MIN(chunksize,
+			                MIN(fri->offset + bp->b_resid,
 			                    va.va_size) - fri->offset);
 			if (chunksize == 0) {
 				respsize = -1;
@@ -901,7 +913,7 @@
 
 		bufdat = bp->b_data + bp->b_dirtyoff;
 		while (bp->b_dirtyend > bp->b_dirtyoff) {
-			chunksize = min(bp->b_dirtyend - bp->b_dirtyoff,
+			chunksize = MIN(bp->b_dirtyend - bp->b_dirtyoff,
 			                fusefs_get_data(vp->v_mount)->max_write);
 	
 			fdi.iosize = sizeof(*fwi);
