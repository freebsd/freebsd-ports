--- fuse_module/fuse.c.orig	Wed Sep 27 15:49:47 2006
+++ fuse_module/fuse.c	Wed Sep 27 15:52:02 2006
@@ -75,7 +75,7 @@
 };
 
 
-#if USE_OLD_CLONEHANDLER_API
+#ifdef USE_OLD_CLONEHANDLER_API
 static void			 fusedev_clone(void *arg, char *name, int namelen, struct cdev **dev);
 #else
 static void			 fusedev_clone(void *arg, struct ucred *cred, char *name, int namelen, struct cdev **dev);
@@ -120,7 +120,7 @@
 __static void		 	 fuse_insert_message(struct fuse_ticket *tick);
 __static fuse_handler_t		 fuse_standard_handler;
 static fuse_handler_t		 fuse_fsync_handler;
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 static fuse_handler_t		 fuse_forgetful_handler;
 #endif
 
@@ -852,27 +852,27 @@
 	case FUSE_FSYNCDIR:
 		err = blen == 0 ? 0 : EINVAL;
 		break;
-#if FUSE_HAS_GETLK
+#ifdef FUSE_HAS_GETLK
 	case FUSE_GETLK:
 		panic("FUSE_GETLK implementor has forgotten to define a response body format check");
 		break;
 #endif
-#if FUSE_HAS_SETLK
+#ifdef FUSE_HAS_SETLK
 	case FUSE_SETLK:
 		panic("FUSE_SETLK implementor has forgotten to define a response body format check");
 		break;
 #endif
-#if FUSE_HAS_SETLKW
+#ifdef FUSE_HAS_SETLKW
 	case FUSE_SETLKW:
 		panic("FUSE_SETLKW implementor has forgotten to define a response body format check");
 		break;
 #endif
-#if FUSE_HAS_ACCESS
+#ifdef FUSE_HAS_ACCESS
 	case FUSE_ACCESS:
 		err = blen == 0 ? 0 : EINVAL;
 		break;
 #endif
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 	case FUSE_CREATE:
 		err = blen == sizeof(struct fuse_entry_out) + sizeof(struct fuse_open_out) ? 0 : EINVAL;
 		break;
@@ -881,7 +881,7 @@
 		panic("fuse opcodes out of sync");
 	}
 
-#if _DEBUG2G
+#ifdef _DEBUG2G
 	if (err)
 		DEBUG2G("op %s (#%d) with body size %d: invalid body size\n",
 		        (0 <= opcode && opcode <= fuse_opnames_entries) ? fuse_opnames[opcode] : "???",
@@ -904,7 +904,7 @@
                  uint64_t nid, enum fuse_opcode op, size_t blen,
                  struct thread* td, struct ucred *cred)
 {
-	ihead->len = sizeof(ihead) + blen; /* actually not used by lib */
+	ihead->len = sizeof(*ihead) + blen; /* actually not used by lib */
 	ihead->unique = tick->unique;
 	ihead->nodeid = nid;
 	ihead->opcode = op;
@@ -988,7 +988,7 @@
 	return (0);
 }
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 static int
 fuse_forgetful_handler(struct fuse_callback_node *caliban, struct uio *uio)
 {
@@ -1242,7 +1242,7 @@
 static int
 fusedev_write(struct cdev *dev, struct uio *uio, int ioflag)
 {
-#if _DEBUG_MSGING
+#ifdef _DEBUG_MSGING
 	static int counter=0;
 #endif
 	struct fuse_out_header *ohead;
@@ -1415,7 +1415,7 @@
 	if ((err = fuse_callbn_wait_answer(&fdip->tick->callbn))) {
 		/* Uh-huh, we got interrupted... */
 
-#if ! DONT_TRY_HARD_PREVENT_IO_IN_VAIN
+#ifndef DONT_TRY_HARD_PREVENT_IO_IN_VAIN
 		struct fuse_callback_node *fcallbn;
 		unsigned age;
 #endif
@@ -1438,7 +1438,7 @@
 			age = fdip->tick->age;
 			fuse_callbn_set_answered(&fdip->tick->callbn);
 			mtx_unlock(&fdip->tick->callbn.answer_mtx);
-#if ! DONT_TRY_HARD_PREVENT_IO_IN_VAIN
+#ifndef DONT_TRY_HARD_PREVENT_IO_IN_VAIN
 			/*
 			 * If we are willing to pay with one more locking, we
 			 * can save on I/O by getting the device write handler
@@ -1662,7 +1662,7 @@
 /* static vop_pathconf_t fuse_pathconf; */
 static vfs_hash_cmp_t fuse_vnode_cmp;
 static vfs_hash_cmp_t fuse_vnode_bgdrop_cmp;
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 static vfs_hash_cmp_t fuse_vnode_fgdrop_cmp;
 #endif
 /* static vfs_vget_t fuse_vget; */
@@ -1683,7 +1683,7 @@
 static vop_lookup_t fuse_lookup;
 static int iterate_filehandles(struct vnode *vp, struct thread *td, struct ucred *cred, fuse_metrics_t fmetr, void *param);
 static fuse_metrics_t fuse_standard_metrics;
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 static __inline int create_filehandle(struct vnode *vp, struct thread *td, struct ucred *cred, int mode, struct fuse_dispatcher *fdip);
 #endif
 static struct fuse_filehandle *get_filehandle(struct vnode *vp, struct thread *td, struct ucred *cred, int mode, struct get_filehandle_param *gefhp);
@@ -1729,7 +1729,7 @@
 
 static b_strategy_t fuse_bufstrategy;
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 static vop_access_t fuse_germ_access;
 #endif
 
@@ -1773,7 +1773,7 @@
 	.vop_unlock        = fuse_unlock,
 };
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 static struct vop_vector fuse_germ_vnops;
 #endif
 
@@ -2092,7 +2092,7 @@
 
 	if (! (fmnt->mntopts & FUSEFS_SECONDARY)) {
 		data->mp = mp;
-#if ! REALTIME_TRACK_UNPRIVPROCDBG
+#ifndef REALTIME_TRACK_UNPRIVPROCDBG
 		fmnt->mntopts &= ~FUSEFS_UNPRIVPROCDBG;
 		fmnt->mntopts |= get_unprivileged_proc_debug(td) ? FUSEFS_UNPRIVPROCDBG : 0;
 #endif
@@ -2380,7 +2380,7 @@
 	return (0);
 }
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 /*
  * Vnode comparison function with which the given vnode always
  * gets inserted, but got marked invalid upon a clash. Caller
@@ -2654,7 +2654,7 @@
 
 	fuse_filehandle_gc(vp, td, NULL);		
 
-#if ! DONT_STORE_FS_MAP
+#ifndef DONT_STORE_FS_MAP
 	/*
 	 * Dropping vnodes when they are not in use would mean that
 	 * the respective inode must be freed on the daemon's side
@@ -2751,7 +2751,7 @@
 		int denied;
 
 		if ((denied = cr_candebug(
-#if REALTIME_TRACK_UNPRIVPROCDBG
+#ifdef REALTIME_TRACK_UNPRIVPROCDBG
 		                get_unprivileged_proc_debug(td),
 #else
 				fmnt->mntopts & FUSEFS_UNPRIVPROCDBG, 
@@ -2948,7 +2948,7 @@
 
 	} else {
 		struct sx *devlock = fdi.slock;
-#if FUSE_HAS_ACCESS
+#ifdef FUSE_HAS_ACCESS
 		struct fuse_access_in *fai;
 
 		if (! (facp->facc_flags & FACCESS_DO_ACCESS))
@@ -3056,7 +3056,7 @@
 
 	bzero(&facp, sizeof(facp));
 	if (
-#if NO_EARLY_PERM_CHECK_HACK
+#ifdef NO_EARLY_PERM_CHECK_HACK
 	    1
 #else
 	    dvp->v_vflag & VV_ROOT
@@ -3281,8 +3281,12 @@
 		DEBUG("we peacefully found that file\n");
 
 		if (flags & ISDOTDOT) {
-			vn_lock(pdp, LK_EXCLUSIVE | LK_RETRY, td);
+			VOP_UNLOCK(dvp, 0, td);
+			err = vn_lock(pdp, cnp->cn_lkflags, td);
 			VREF(pdp);
+			vn_lock(dvp, LK_EXCLUSIVE | LK_RETRY, td);
+			if (err)
+				goto out;
 			*vpp = pdp;
 		} else if (nid == VTOI(dvp)) {
 			VREF(dvp); /* We want ourself, ie "." */
@@ -3347,7 +3351,7 @@
 			if (islastcn && flags & ISOPEN)
 				((struct fuse_vnode_data *)(*vpp)->v_data)->flags |= FVP_ACCESS_NOOP;
 
-#if ! NO_EARLY_PERM_CHECK_HACK
+#ifndef NO_EARLY_PERM_CHECK_HACK
 			if (! islastcn) {
 				/* We have the attributes of the next item
 				 * *now*, and it's a fact, and we do not have
@@ -3486,7 +3490,7 @@
 	return (0);
 }
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 static __inline int
 create_filehandle(struct vnode *vp, struct thread *td, struct ucred *cred,
                   int mode, struct fuse_dispatcher *fdip)
@@ -3643,7 +3647,7 @@
 	 * the vnode... if the vnode is a germ, it will be tried to be initialized
 	 * via a dedicated method, but from that on we go on as usual.)
 	 */
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 	if (vp->v_op == &fuse_germ_vnops) {
 		KASSERT(gefhp, ("create_filehandle called without get_filehandle_param"));
 		gone_create = 1;
@@ -3709,7 +3713,7 @@
 	if ((err = fdisp_wait_answ(&fdi)))
 		goto out;
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 setup_filehandle:
 #endif
 	foo = fdi.answ;
@@ -4184,7 +4188,7 @@
 #define BSD_FUSE_PAGENO_BOUND MIN(FUSE_MAX_PAGES_PER_REQ, MAXBSIZE / PAGE_SIZE)
 
 		bcount = MIN(MAXBSIZE, biosize * BSD_FUSE_PAGENO_BOUND);
-#if BIOREAD_CONSIDER_FILE_SIZE 
+#ifdef BIOREAD_CONSIDER_FILE_SIZE 
 		if (vp->v_type != VDIR) {
 			/*
 			 * for directories we can't predict the size, in fact
@@ -4493,7 +4497,7 @@
 			break;
 		}
 
-#if ZERO_PAD_INCOMPLETE_BUFS
+#ifdef ZERO_PAD_INCOMPLETE_BUFS
 		if (isbzero(buf), FUSE_NAME_OFFSET) {
 			err = -1;
 			break;
@@ -4658,7 +4662,7 @@
 	struct vnode *dvp = ap->a_dvp;
 	struct vnode **vpp = ap->a_vpp;
 	struct vattr *vap = ap->a_vap;
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 	struct fuse_dispatcher fdi;
 	struct fuse_vnode_data *fvdat;
 	int err;
@@ -4949,7 +4953,7 @@
 	if (err)
 		goto out;
 
-#if ! DONT_DO_CHECKPATH
+#ifndef DONT_DO_CHECKPATH
 	if (doingdirectory && fdvp != tdvp) {
 		/*
 		 * Check for pathname conflict.
@@ -5396,7 +5400,6 @@
 	struct vnode *vp = fioda->vp;
 	struct uio *uio = fioda->uio;
 	struct ucred *cred = fioda->cred;
-	struct fuse_filehandle *fufh = fioda->fufh;
 
 	int biosize;
 
@@ -5506,7 +5509,7 @@
 		if ((bp->b_flags & B_CACHE) == 0) {
 			bp->b_iocmd = BIO_READ;
 			vfs_busy_pages(bp, 0);
-			fuse_strategy_i(vp, bp, fufh, 0);
+			fuse_strategy_i(vp, bp, NULL, 0);
 			if ((err =  bp->b_error)) {
 				brelse(bp);
 				break;
@@ -5741,7 +5744,7 @@
 			        chunksize, (long long unsigned)fri->offset, respsize);
 	
 			if (respsize < chunksize) {
-#if ZERO_PAD_INCOMPLETE_BUFS
+#ifdef ZERO_PAD_INCOMPLETE_BUFS
 				/*
 				 * "if we don't get enough data, just fill the
 				 * rest with zeros."
@@ -5888,7 +5891,7 @@
 	        "vp=%p, rc=%d", bp, vp, rc));
 }
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 static int
 fuse_germ_access(struct vop_access_args *ap)
 {
@@ -5908,7 +5911,7 @@
 
 /*   Modeled after tunclone() of net/if_tun.c
  */
-#if USE_OLD_CLONEHANDLER_API
+#ifdef USE_OLD_CLONEHANDLER_API
 static void
 fusedev_clone(void *arg, char *name, int namelen, struct cdev **dev)
 #else
@@ -6019,7 +6022,7 @@
 		fuse_fileops.fo_close    = fuse_close_f;
 		fuse_fileops.fo_flags    = DFLAG_PASSABLE | DFLAG_SEEKABLE;
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 		memcpy(&fuse_germ_vnops, &dead_vnodeops, sizeof(struct vop_vector));
 		fuse_germ_vnops.vop_access = fuse_germ_access;
 		fuse_germ_vnops.vop_open = fuse_open;
