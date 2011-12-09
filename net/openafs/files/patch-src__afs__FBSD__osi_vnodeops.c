commit 8e14168c9c77850ce0603d56f8aa280f73cb3114
Author: Ben Kaduk <kaduk@mit.edu>
Date:   Sun Nov 13 13:12:50 2011 -0500

    FBSD: cleanup dvp locking for ISDOTDOT
    
    This is a more correct version of
    c2ed2577f9c16df3088158fb593d7aab6e8690d0, which was reverted since
    it caused build issues on some versions and kernel panics on others.
    
    We do want to always unlock dvp before calling over the network
    in the ISDOTDOT case, but be sure to use the proper spelling
    for this operation (as the syntax has changed between FreeBSD versions).
    This requires not unlocking dvp right after the afs_lookup() call if
    it succeeds, letting us just lock the "child" vp (which is actually
    the parent starting from '/') first, and then re-lock dvp.
    
    The error case of afs_lookup() was already handled correctly in
    this logic, which is to say that it was incorrect before this change,
    attempting to recursively lock dvp which causes a panic.
    
    Change-Id: Ide29e47991413dadc3a2b5948f0f6c5bfa2911c4
    Reviewed-on: http://gerrit.openafs.org/6127
    Tested-by: BuildBot <buildbot@rampaginggeek.com>
    Reviewed-by: Derrick Brashear <shadow@dementix.org>

diff --git a/src/afs/FBSD/osi_vnodeops.c b/src/afs/FBSD/osi_vnodeops.c
index 311b5a9..a9be0c3 100644
--- a/src/afs/FBSD/osi_vnodeops.c
+++ b/src/afs/FBSD/osi_vnodeops.c
@@ -503,10 +503,8 @@ afs_vop_lookup(ap)
 
     cnp->cn_flags |= MPSAFE; /* steel */
 
-#ifndef AFS_FBSD70_ENV
     if (flags & ISDOTDOT)
-	VOP_UNLOCK(dvp, 0, p);
-#endif
+	MA_VOP_UNLOCK(dvp, 0, p);
 
     AFS_GLOCK();
     error = afs_lookup(VTOAFS(dvp), name, &vcp, cnp->cn_cred);
@@ -531,7 +529,7 @@ afs_vop_lookup(ap)
      * we also always return the vnode locked. */
 
     if (flags & ISDOTDOT) {
-	MA_VOP_UNLOCK(dvp, 0, p);
+	/* vp before dvp since we go root to leaf, and .. comes first */
 	ma_vn_lock(vp, LK_EXCLUSIVE | LK_RETRY, p);
 	ma_vn_lock(dvp, LK_EXCLUSIVE | LK_RETRY, p);
 	/* always return the child locked */
