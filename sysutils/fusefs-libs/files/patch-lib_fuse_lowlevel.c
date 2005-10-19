--- lib/fuse_lowlevel.c.orig	Mon Oct  3 17:15:05 2005
+++ lib/fuse_lowlevel.c	Sun Oct  9 22:05:09 2005
@@ -194,7 +194,11 @@
     kstatfs->bavail	= stbuf->f_bavail;
     kstatfs->files	= stbuf->f_files;
     kstatfs->ffree	= stbuf->f_ffree;
+#ifdef __FreeBSD__
+    kstatfs->namelen	= stbuf->f_namemax;
+#else
     kstatfs->namelen	= stbuf->f_namelen;
+#endif
 }
 
 static int send_reply_ok(fuse_req_t req, const void *arg, size_t argsize)
@@ -690,7 +694,11 @@
     req->ch = ch;
 
     if (!f->got_init && in->opcode != FUSE_INIT)
+#ifdef EPROTO
         fuse_reply_err(req, EPROTO);
+#else
+        fuse_reply_err(req, EPROTONOSUPPORT);
+#endif
     else if (f->allow_root && in->uid != f->owner && in->uid != 0 &&
              in->opcode != FUSE_INIT && in->opcode != FUSE_READ &&
              in->opcode != FUSE_WRITE && in->opcode != FUSE_FSYNC &&
