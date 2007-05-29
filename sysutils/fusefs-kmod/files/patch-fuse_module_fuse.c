--- fuse_module/fuse.c.orig	Sat Feb 11 00:31:53 2006
+++ fuse_module/fuse.c	Fri May 25 14:54:26 2007
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
 
@@ -2070,29 +2070,42 @@
 	       M_WAITOK | M_ZERO);
 
 	err = getnewvnode("fuse", mp, &fuse_vnops, &rvp);
+	if (! err) {
+		err = vn_lock(rvp, LK_EXCLUSIVE | LK_RETRY, td);
+#if NEW_VNODES_ADJUSTED_MANUALLY
+		if (err)
+			printf("fuse4bsd: leaking vnode %p\n", rvp);
+#endif
+	}
+
+	if (! err) {
+		/*
+		 * FUSE_ROOT_ID as an inode number will be resolved directly.
+		 * without resorting to the vfs hashing mechanism, thus it also
+		 * can be inserted directly to the v_hash slot.
+		 */
+		rvp->v_hash = FUSE_ROOT_ID;
+		fmnt->rvp = rvp;
+		fuse_vnode_init(rvp, fvdat, FUSE_ROOT_ID, VNON);
+		rvp->v_vflag |= VV_ROOT;
+#if NEW_VNODES_ADJUSTED_MANUALLY
+		err = insmntque(rvp, mp);
+#endif
+	}
 
 	if (err) {
 		fdata_kick_set(data);
 		sx_xunlock(slock);
 		FREE(fvdat, M_FUSEFS);
 	        goto out;
-	}
-
-	/*
-	 * FUSE_ROOT_ID as an inode number will be resolved directly.
-	 * without resorting to the vfs hashing mechanism, thus it also
-	 * can be inserted directly to the v_hash slot.
-	 */
-	rvp->v_hash = FUSE_ROOT_ID;
-	fmnt->rvp = rvp; 	
-	fuse_vnode_init(rvp, fvdat, FUSE_ROOT_ID, VNON);
-	rvp->v_vflag |= VV_ROOT;
+	} else
+		VOP_UNLOCK(rvp, 0, td);
 
 rootdone:
 
 	if (! (fmnt->mntopts & FUSEFS_SECONDARY)) {
 		data->mp = mp;
-#if ! REALTIME_TRACK_UNPRIVPROCDBG
+#ifndef REALTIME_TRACK_UNPRIVPROCDBG
 		fmnt->mntopts &= ~FUSEFS_UNPRIVPROCDBG;
 		fmnt->mntopts |= get_unprivileged_proc_debug(td) ? FUSEFS_UNPRIVPROCDBG : 0;
 #endif
@@ -2380,7 +2393,7 @@
 	return (0);
 }
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 /*
  * Vnode comparison function with which the given vnode always
  * gets inserted, but got marked invalid upon a clash. Caller
@@ -2405,11 +2418,11 @@
 fuse_vget_i(struct mount *mp, struct thread *td, uint64_t nodeid,
 	    enum vtype vtyp, struct vnode **vpp, int wantnew)
 {
+#define myflags LK_EXCLUSIVE | LK_RETRY
 	int err = 0;
 	struct fuse_mnt_data *fmnt;
 	struct fuse_vnode_data *fvdat;
 	struct vnode *vp2;
-	int myflags = LK_EXCLUSIVE;
 
 	DEBUG2G("mp %p: %s\n", mp, mp->mnt_stat.f_mntfromname);
 	DEBUG("been asked for vno #%llu\n", (unsigned long long)nodeid);
@@ -2470,6 +2483,18 @@
 	        return (err);
 	}
 
+#if NEW_VNODES_ADJUSTED_MANUALLY
+	err = vn_lock(*vpp, myflags, td);
+	if (err)
+		printf("fuse4bsd: leaking vnode %p\n", *vpp);
+	else
+		err = insmntque(*vpp, mp);
+	if (err) {
+	        free(fvdat, M_FUSEFS);
+	        return (err);
+	}
+#endif
+
 	/*
 	 * There is no harm in fully initializing the vnode before trying
 	 * at insertion, because vnodes are gc-d anyway. For the same reason,
@@ -2504,6 +2529,7 @@
 	vn_printf(*vpp, " * ");
 #endif
 	return (err);
+#undef myflags
 }
 
 
@@ -2654,7 +2680,7 @@
 
 	fuse_filehandle_gc(vp, td, NULL);		
 
-#if ! DONT_STORE_FS_MAP
+#ifndef DONT_STORE_FS_MAP
 	/*
 	 * Dropping vnodes when they are not in use would mean that
 	 * the respective inode must be freed on the daemon's side
@@ -2751,7 +2777,7 @@
 		int denied;
 
 		if ((denied = cr_candebug(
-#if REALTIME_TRACK_UNPRIVPROCDBG
+#ifdef REALTIME_TRACK_UNPRIVPROCDBG
 		                get_unprivileged_proc_debug(td),
 #else
 				fmnt->mntopts & FUSEFS_UNPRIVPROCDBG, 
@@ -2948,7 +2974,7 @@
 
 	} else {
 		struct sx *devlock = fdi.slock;
-#if FUSE_HAS_ACCESS
+#ifdef FUSE_HAS_ACCESS
 		struct fuse_access_in *fai;
 
 		if (! (facp->facc_flags & FACCESS_DO_ACCESS))
@@ -3056,7 +3082,7 @@
 
 	bzero(&facp, sizeof(facp));
 	if (
-#if NO_EARLY_PERM_CHECK_HACK
+#ifdef NO_EARLY_PERM_CHECK_HACK
 	    1
 #else
 	    dvp->v_vflag & VV_ROOT
@@ -3281,8 +3307,12 @@
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
@@ -3347,7 +3377,7 @@
 			if (islastcn && flags & ISOPEN)
 				((struct fuse_vnode_data *)(*vpp)->v_data)->flags |= FVP_ACCESS_NOOP;
 
-#if ! NO_EARLY_PERM_CHECK_HACK
+#ifndef NO_EARLY_PERM_CHECK_HACK
 			if (! islastcn) {
 				/* We have the attributes of the next item
 				 * *now*, and it's a fact, and we do not have
@@ -3486,7 +3516,7 @@
 	return (0);
 }
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 static __inline int
 create_filehandle(struct vnode *vp, struct thread *td, struct ucred *cred,
                   int mode, struct fuse_dispatcher *fdip)
@@ -3567,7 +3597,20 @@
 	bzero(fvdat, sizeof(*fvdat));
 	fuse_vnode_init(vp, fvdat, feo->nodeid, VREG);
 	vp->v_op = &fuse_vnops;
+#if NEW_VNODES_ADJUSTED_MANUALLY
+	{
+		struct mount *mp = vp->v_mount;
+
+		vp->v_mount = NULL;
+		err = insmntque(vp, mp);
+		if (err) {
+			free(fvdat, M_FUSEFS);
+			return (err);
+		}
+	}
+#else
 	VOP_UNLOCK(vp, 0, td);
+#endif
 	/*
 	 * We can't let the vnode being vput() here, the caller wants
 	 * that do by herself.
@@ -3643,7 +3686,7 @@
 	 * the vnode... if the vnode is a germ, it will be tried to be initialized
 	 * via a dedicated method, but from that on we go on as usual.)
 	 */
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 	if (vp->v_op == &fuse_germ_vnops) {
 		KASSERT(gefhp, ("create_filehandle called without get_filehandle_param"));
 		gone_create = 1;
@@ -3709,7 +3752,7 @@
 	if ((err = fdisp_wait_answ(&fdi)))
 		goto out;
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 setup_filehandle:
 #endif
 	foo = fdi.answ;
@@ -4184,7 +4227,7 @@
 #define BSD_FUSE_PAGENO_BOUND MIN(FUSE_MAX_PAGES_PER_REQ, MAXBSIZE / PAGE_SIZE)
 
 		bcount = MIN(MAXBSIZE, biosize * BSD_FUSE_PAGENO_BOUND);
-#if BIOREAD_CONSIDER_FILE_SIZE 
+#ifdef BIOREAD_CONSIDER_FILE_SIZE 
 		if (vp->v_type != VDIR) {
 			/*
 			 * for directories we can't predict the size, in fact
@@ -4215,11 +4258,9 @@
 #if _DEBUG
 			prettyprint(bp->b_data, 48);
 			printf("\n");
-#if ZERO_PAD_INCOMPLETE_BUFS
 			prettyprint(bp->b_data + PAGE_SIZE, 48);
 			printf("\n");
 #endif
-#endif
 			if (err) {
 				brelse(bp);
 				return (err);
@@ -4493,13 +4534,6 @@
 			break;
 		}
 
-#if ZERO_PAD_INCOMPLETE_BUFS
-		if (isbzero(buf), FUSE_NAME_OFFSET) {
-			err = -1;
-			break;
-		}
-#endif
-
 		/* Sanity checks */
 
 		if (!fudge->namelen || fudge->namelen > MAXNAMLEN) {
@@ -4658,7 +4692,7 @@
 	struct vnode *dvp = ap->a_dvp;
 	struct vnode **vpp = ap->a_vpp;
 	struct vattr *vap = ap->a_vap;
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 	struct fuse_dispatcher fdi;
 	struct fuse_vnode_data *fvdat;
 	int err;
@@ -4683,8 +4717,12 @@
 	if ((err = getnewvnode("fuse", dvp->v_mount, &fuse_vnops, vpp)))
 		return (err);
 
-	if ((err = vn_lock(*vpp, LK_EXCLUSIVE | LK_RETRY, curthread)))
+	if ((err = vn_lock(*vpp, LK_EXCLUSIVE | LK_RETRY, curthread))) {
+#if NEW_VNODES_ADJUSTED_MANUALLY
+		printf("fuse4bsd: leaking vnode %p\n", *vpp);
+#endif
 		return (err);
+	}
 
 	MALLOC(fvdat, struct fuse_vnode_data *, sizeof(*fvdat), M_FUSEFS,
 	       M_WAITOK | M_ZERO);
@@ -4704,6 +4742,9 @@
 	 */
 	(*vpp)->v_op = &fuse_germ_vnops;
 	(*vpp)->v_data = fvdat;
+#if NEW_VNODES_ADJUSTED_MANUALLY
+	(*vpp)->v_mount = dvp->v_mount;
+#endif
 
 	return (0);
 
@@ -4949,7 +4990,7 @@
 	if (err)
 		goto out;
 
-#if ! DONT_DO_CHECKPATH
+#ifndef DONT_DO_CHECKPATH
 	if (doingdirectory && fdvp != tdvp) {
 		/*
 		 * Check for pathname conflict.
@@ -5396,7 +5437,6 @@
 	struct vnode *vp = fioda->vp;
 	struct uio *uio = fioda->uio;
 	struct ucred *cred = fioda->cred;
-	struct fuse_filehandle *fufh = fioda->fufh;
 
 	int biosize;
 
@@ -5506,7 +5546,7 @@
 		if ((bp->b_flags & B_CACHE) == 0) {
 			bp->b_iocmd = BIO_READ;
 			vfs_busy_pages(bp, 0);
-			fuse_strategy_i(vp, bp, fufh, 0);
+			fuse_strategy_i(vp, bp, NULL, 0);
 			if ((err =  bp->b_error)) {
 				brelse(bp);
 				break;
@@ -5741,23 +5781,16 @@
 			        chunksize, (long long unsigned)fri->offset, respsize);
 	
 			if (respsize < chunksize) {
-#if ZERO_PAD_INCOMPLETE_BUFS
 				/*
-				 * "if we don't get enough data, just fill the
-				 * rest with zeros."
-				 * in nfs context this means a hole in the
-				 * file, I don't know what to do with this
-				 * here... [we just get a buch of zeroes
-				 * instead of EOF, baaad]
+				 * if we don't get enough data, just fill the
+				 * rest with zeros.
 				 */ 
 				DEBUG("zeroing tail of %ld bytes\n",
 				      bp->b_resid);
 				bzero((char *)bp->b_data + bp->b_bcount - bp->b_resid,
 				      bp->b_resid);
-				bp->b_resid = 0;
-#else
+
 				break;
-#endif
 			}
 			ticket_refresh(fdi.tick);
 			DEBUG("bp->b_data %p\n", bp->b_data);
@@ -5888,7 +5921,7 @@
 	        "vp=%p, rc=%d", bp, vp, rc));
 }
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 static int
 fuse_germ_access(struct vop_access_args *ap)
 {
@@ -5908,7 +5941,7 @@
 
 /*   Modeled after tunclone() of net/if_tun.c
  */
-#if USE_OLD_CLONEHANDLER_API
+#ifdef USE_OLD_CLONEHANDLER_API
 static void
 fusedev_clone(void *arg, char *name, int namelen, struct cdev **dev)
 #else
@@ -6019,7 +6052,7 @@
 		fuse_fileops.fo_close    = fuse_close_f;
 		fuse_fileops.fo_flags    = DFLAG_PASSABLE | DFLAG_SEEKABLE;
 
-#if FUSE_HAS_CREATE
+#ifdef FUSE_HAS_CREATE
 		memcpy(&fuse_germ_vnops, &dead_vnodeops, sizeof(struct vop_vector));
 		fuse_germ_vnops.vop_access = fuse_germ_access;
 		fuse_germ_vnops.vop_open = fuse_open;
@@ -6089,7 +6092,7 @@
 
 /* Registering the module */
 
-static struct vfsconf fuse_vfsconf = {
+struct vfsconf fuse_vfsconf = {
 	.vfc_version = VFS_VERSION,
 	.vfc_name = "fusefs",
 	.vfc_vfsops = &fuse_vfsops,
