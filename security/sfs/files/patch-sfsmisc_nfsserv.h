--- sfsmisc/nfsserv.h.orig	Mon Oct 11 16:43:34 2004
+++ sfsmisc/nfsserv.h	Mon Oct 11 16:39:35 2004
@@ -110,6 +110,19 @@
   template<class T> T *getres () { return static_cast<T *> (getvoidres ()); }
 };
 
+struct nfsserv : public virtual refcount {
+  typedef callback<void, nfscall *>::ref cb_t;
+  static const cb_t stalecb;
+  cb_t cb;
+  const ptr<nfsserv> nextserv;
+  explicit nfsserv (ptr<nfsserv> n = NULL);
+  void setcb (const cb_t &c) { cb = c; }
+  void mkcb (nfscall *nc) { nc->curserv = this; (*cb) (nc); }
+  virtual void getcall (nfscall *nc) { mkcb (nc); }
+  virtual void getreply (nfscall *nc) { nc->sendreply (); }
+  virtual bool encodefh (nfs_fh3 &fh);
+};
+
 template<int N> class nfscall_cb : public nfscall {
   typedef typename nfs3proc<N>::arg_type *arg_type;
   typedef typename nfs3proc<N>::res_type *res_type;
@@ -134,19 +147,6 @@
   svccb *sbp;
   nfscall_rpc (svccb *sbp);
   ~nfscall_rpc ();
-};
-
-struct nfsserv : public virtual refcount {
-  typedef callback<void, nfscall *>::ref cb_t;
-  static const cb_t stalecb;
-  cb_t cb;
-  const ptr<nfsserv> nextserv;
-  explicit nfsserv (ptr<nfsserv> n = NULL);
-  void setcb (const cb_t &c) { cb = c; }
-  void mkcb (nfscall *nc) { nc->curserv = this; (*cb) (nc); }
-  virtual void getcall (nfscall *nc) { mkcb (nc); }
-  virtual void getreply (nfscall *nc) { nc->sendreply (); }
-  virtual bool encodefh (nfs_fh3 &fh);
 };
 
 class nfsserv_udp : public nfsserv {
