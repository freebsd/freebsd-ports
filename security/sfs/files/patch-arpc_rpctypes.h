--- arpc/rpctypes.h.orig	Mon Oct 11 16:43:34 2004
+++ arpc/rpctypes.h	Mon Oct 11 16:39:35 2004
@@ -129,7 +129,7 @@
   if (&v != this)				\
     assign (v)
 
-  void init () { mode = NOFREE; nelm = 0; vec = NULL; }
+  void init () { mode = freemode::NOFREE; nelm = 0; vec = NULL; }
   void del () {
     switch (mode) {
     case NOFREE:
@@ -266,6 +266,8 @@
   a.swap (b);
 }
 
+extern const str rpc_emptystr;
+
 template<size_t max = RPC_INFINITY> struct rpc_str : str
 {
   enum { maxsize = max };
@@ -301,12 +303,12 @@
 };
 
 template<size_t n = RPC_INFINITY> struct rpc_opaque : array<char, n> {
-  rpc_opaque () { bzero (base (), size ()); }
+  rpc_opaque () { bzero (this->base (), this->size ()); }
 };
 template<size_t n = RPC_INFINITY> struct rpc_bytes : rpc_vec<char, n> {
-  void setstrmem (const str &s) { set (s.cstr (), s.len (), NOFREE); }
+  void setstrmem (const str &s) { set (s.cstr (), s.len (), freemode::NOFREE); }
   rpc_bytes &operator= (const str &s)
-    { setsize (s.len ()); memcpy (base (), s.cstr (), size ()); return *this; }
+    { setsize (s.len ()); memcpy (this->base (), s.cstr (), this->size ()); return *this; }
   template<size_t m> rpc_bytes &operator= (const rpc_vec<char, m> &v)
     { rpc_vec<char, n>::operator= (v); return *this; }
   template<size_t m> rpc_bytes &operator= (const array<char, m> &v)
@@ -519,7 +521,6 @@
 
 struct rpc_clear_t {};
 extern struct rpc_clear_t _rpcclear;
-extern const str rpc_emptystr;
 
 inline bool
 rpc_traverse (rpc_clear_t &, u_int32_t &obj)
