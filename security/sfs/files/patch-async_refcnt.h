--- async/refcnt.h.orig	Mon Oct 11 16:43:34 2004
+++ async/refcnt.h	Mon Oct 11 16:39:35 2004
@@ -409,7 +409,7 @@
   friend class refpriv;
 
   friend ref<T> mkref<T> (T *);
-  ref (T *pp, refcount *cc) : refpriv (cc) { p = pp; inc (); }
+  ref (T *pp, refcount *cc) : refpriv (cc) { this->p = pp; inc (); }
 
   void inc () const { rinc (c); }
   void dec () const { rdec (c); }
@@ -420,32 +420,32 @@
 
   template<class U, reftype v>
   ref (refcounted<U, v> *pp)
-    : refpriv (rc (pp)) { p = refpriv::rp (pp); inc (); }
+    : refpriv (rc (pp)) { this->p = refpriv::rp (pp); inc (); }
   /* At least with gcc, the copy constructor must be explicitly
    * defined (though it would appear to be redundant given the
    * template constructor bellow). */
-  ref (const ref<T> &r) : refpriv (r.c) { p = r.p; inc (); }
+  ref (const ref<T> &r) : refpriv (r.c) { this->p = r.p; inc (); }
   template<class U>
   ref (const ref<U> &r)
-    : refpriv (rc (r)) { p = refpriv::rp (r); inc (); }
+    : refpriv (rc (r)) { this->p = refpriv::rp (r); inc (); }
   template<class U>
   ref (const ::ptr<U> &r)
-    : refpriv (rc (r)) { p = refpriv::rp (r); inc (); }
+    : refpriv (rc (r)) { this->p = refpriv::rp (r); inc (); }
 
   ~ref () { dec (); }
 
   template<class U, reftype v> ref<T> &operator= (refcounted<U, v> *pp)
-    { rinc (pp); dec (); p = refpriv::rp (pp); c = rc (pp); return *this; }
+    { rinc (pp); dec (); this->p = refpriv::rp (pp); c = rc (pp); return *this; }
 
   /* The copy assignment operator must also explicitly be defined,
    * despite a redundant template. */
   ref<T> &operator= (const ref<T> &r)
-    { r.inc (); dec (); p = r.p; c = r.c; return *this; }
+    { r.inc (); dec (); this->p = r.p; c = r.c; return *this; }
   template<class U> ref<T> &operator= (const ref<U> &r)
-    { rinc (r); dec (); p = refpriv::rp (r); c = rc (r); return *this; }
+    { rinc (r); dec (); this->p = refpriv::rp (r); c = rc (r); return *this; }
   /* Self asignment not possible.  Use ref::inc to cause segfauls on NULL. */
   template<class U> ref<T> &operator= (const ::ptr<U> &r)
-    { dec (); p = refpriv::rp (r); c = rc (r); inc (); return *this; }
+    { dec (); this->p = refpriv::rp (r); c = rc (r); inc (); return *this; }
 };
 
 /* To skip initialization of ptr's in BSS */
@@ -464,13 +464,13 @@
       rinc (pp);
       if (decme)
 	dec ();
-      p = refpriv::rp (pp);
+      this->p = refpriv::rp (pp);
       c = rc (pp);
     }
     else {
       if (decme)
 	dec ();
-      p = NULL;
+      this->p = NULL;
       c = NULL;
     }
   }
@@ -480,31 +480,31 @@
   typedef ref<T> ref;
 
   explicit ptr (__bss_init) {}
-  ptr () : refpriv (NULL) { p = NULL; }
-  ptr (privtype *) : refpriv (NULL) { p = NULL; }
+  ptr () : refpriv (NULL) { this->p = NULL; }
+  ptr (privtype *) : refpriv (NULL) { this->p = NULL; }
   template<class U, reftype v>
   ptr (refcounted<U, v> *pp) { set (pp, false); }
-  ptr (const ptr<T> &r) : refpriv (r.c) { p = r.p; inc (); }
+  ptr (const ptr<T> &r) : refpriv (r.c) { this->p = r.p; inc (); }
   template<class U>
   ptr (const ptr<U> &r)
-    : refpriv (rc (r)) { p = refpriv::rp (r); inc (); }
+    : refpriv (rc (r)) { this->p = refpriv::rp (r); inc (); }
   template<class U>
   ptr (const ::ref<U> &r)
-    : refpriv (rc (r)) { p = refpriv::rp (r); inc (); }
+    : refpriv (rc (r)) { this->p = refpriv::rp (r); inc (); }
 
   ~ptr () { dec (); }
 
   ptr<T> &operator= (privtype *)
-    { dec (); p = NULL; c = NULL; return *this; }
+    { dec (); this->p = NULL; c = NULL; return *this; }
   template<class U, reftype v> ptr<T> &operator= (refcounted<U, v> *pp)
     { set (pp, true); return *this; }
 
   ptr<T> &operator= (const ptr<T> &r)
-    { r.inc (); dec (); p = r.p; c = r.c; return *this; }
+    { r.inc (); dec (); this->p = r.p; c = r.c; return *this; }
   template<class U> ptr<T> &operator= (const ptr<U> &r)
-    { rinc (r); dec (); p = refpriv::rp (r); c = rc (r); return *this; }
+    { rinc (r); dec (); this->p = refpriv::rp (r); c = rc (r); return *this; }
   template<class U> ptr<T> &operator= (const ::ref<U> &r)
-    { rinc (r); dec (); p = refpriv::rp (r); c = rc (r); return *this; }
+    { rinc (r); dec (); this->p = refpriv::rp (r); c = rc (r); return *this; }
 };
 
 template<class T>
@@ -512,7 +512,7 @@
   // Don't initialize (assume we were 0 initialized in the BSS)
   bssptr () : ptr<T> (__bss_init ()) {}
   // Override the effects of destruction
-  ~bssptr () { assert (globaldestruction); if (*this != NULL) Xleak (); }
+  ~bssptr () { assert (globaldestruction); if (*this != NULL) this->Xleak (); }
   ptr<T> &operator= (refpriv::privtype *p) { return ptr<T>::operator= (p); }
   template<class U> ptr<T> &operator= (const ptr<U> &r)
     { return ptr<T>::operator= (r); }
