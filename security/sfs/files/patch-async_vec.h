--- async/vec.h.orig	Mon Oct 11 16:43:34 2004
+++ async/vec.h	Mon Oct 11 16:39:35 2004
@@ -74,16 +74,16 @@
 template<class T, size_t N = 0> class vec : public vec_base<T, N> {
   typedef typename vec_base<T, N>::elm_t elm_t;
   void move (elm_t *dst) {
-    if (dst == firstp)
+    if (dst == this->firstp)
       return;
-    assert (dst < firstp || dst >= lastp);
-    basep = dst;
-    for (elm_t *src = firstp; src < lastp; src++) {
+    assert (dst < this->firstp || dst >= this->lastp);
+    this->basep = dst;
+    for (elm_t *src = this->firstp; src < this->lastp; src++) {
       new ((void *) (dst++)) elm_t (*src);
       src->~elm_t ();
     }
-    lastp += basep - firstp;
-    firstp = basep;
+    this->lastp += this->basep - this->firstp;
+    this->firstp = this->basep;
   }
 
   static elm_t &construct (elm_t &e)
@@ -92,14 +92,14 @@
     { return *new (implicit_cast<void *> (&e)) elm_t (v); }
   static void destroy (elm_t &e) { e.~elm_t (); }
 
-  void init () { lastp = firstp = basep = def_basep (); limp = def_limp (); }
-  void del () { while (firstp < lastp) firstp++->~elm_t (); bfree (basep); }
+  void init () { this->lastp = this->firstp = this->basep = this->def_basep (); this->limp = this->def_limp (); }
+  void del () { while (this->firstp < this->lastp) (this->firstp)++->~elm_t (); bfree (this->basep); }
 
 #define append(v)						\
 do {								\
   reserve (v.size ());						\
   for (const elm_t *s = v.base (), *e = v.lim (); s < e; s++)	\
-    cconstruct (*lastp++, *s);					\
+    cconstruct (*(this->lastp)++, *s);					\
 } while (0)
 
 #ifdef CHECK_BOUNDS
@@ -125,19 +125,19 @@
     { clear (); append (v); return *this; }
 
   void reserve (size_t n) {
-    if (lastp + n <= limp)
+    if (this->lastp + n <= this->limp)
       return;
-    size_t nalloc = limp - basep;
-    size_t nwanted = lastp - firstp + n;
+    size_t nalloc = this->limp - this->basep;
+    size_t nwanted = this->lastp - this->firstp + n;
     if (nwanted > nalloc / 2) {
       nalloc = 1 << fls (max (nalloc, nwanted));
-      elm_t *obasep = basep;
+      elm_t *obasep = this->basep;
       move (static_cast<elm_t *> (txmalloc (nalloc * sizeof (elm_t))));
-      limp = basep + nalloc;
+      this->limp = this->basep + nalloc;
       bfree (obasep);
     }
     else
-      move (basep);
+      move (this->basep);
   }
   void setsize (size_t n) {
     size_t s = size ();
@@ -145,47 +145,47 @@
       popn_back (s - n);
     else if ((n -= s)) {
       reserve (n);
-      elm_t *sp = lastp;
-      lastp += n;
-      while (sp < lastp)
+      elm_t *sp = this->lastp;
+      this->lastp += n;
+      while (sp < this->lastp)
         construct (*sp++);
     }
   }
 
-  elm_t *base () { return firstp; }
-  const elm_t *base () const { return firstp; }
-  elm_t *lim () { return lastp; }
-  const elm_t *lim () const { return lastp; }
-  size_t size () const { return lastp - firstp; }
-  bool empty () const { return lastp == firstp; }
-
-  elm_t &front () { zcheck (); return *firstp; }
-  const elm_t &front () const { zcheck (); return *firstp; }
-  elm_t &back () { zcheck (); return lastp[-1]; }
-  const elm_t &back () const { zcheck (); return lastp[-1]; }
+  elm_t *base () { return this->firstp; }
+  const elm_t *base () const { return this->firstp; }
+  elm_t *lim () { return this->lastp; }
+  const elm_t *lim () const { return this->lastp; }
+  size_t size () const { return this->lastp - this->firstp; }
+  bool empty () const { return this->lastp == this->firstp; }
+
+  elm_t &front () { zcheck (); return *(this->firstp); }
+  const elm_t &front () const { zcheck (); return *(this->firstp); }
+  elm_t &back () { zcheck (); return this->lastp[-1]; }
+  const elm_t &back () const { zcheck (); return this->lastp[-1]; }
   
-  elm_t &operator[] (ptrdiff_t i) { bcheck (i); return firstp[i]; }
-  const elm_t &operator[] (ptrdiff_t i) const { bcheck (i); return firstp[i]; }
+  elm_t &operator[] (ptrdiff_t i) { bcheck (i); return this->firstp[i]; }
+  const elm_t &operator[] (ptrdiff_t i) const { bcheck (i); return this->firstp[i]; }
 
-  elm_t &push_back () { reserve (1); return construct (*lastp++); }
+  elm_t &push_back () { reserve (1); return construct (*(this->lastp)++); }
   elm_t &push_back (const elm_t &e)
-    { reserve (1); return cconstruct (*lastp++, e); }
+    { reserve (1); return cconstruct (*(this->lastp)++, e); }
 
-  elm_t pop_back () { zcheck (); return destroy_return (*--lastp); }
+  elm_t pop_back () { zcheck (); return destroy_return (*--(this->lastp)); }
   void popn_back (size_t n) {
     pcheck (n);
-    elm_t *sp = lastp;
-    lastp -= n;
-    while (sp > lastp)
+    elm_t *sp = this->lastp;
+    this->lastp -= n;
+    while (sp > this->lastp)
       destroy (*--sp);
   }
 
-  elm_t pop_front () { zcheck (); return destroy_return (*firstp++); }
+  elm_t pop_front () { zcheck (); return destroy_return (*(this->firstp)++); }
   void popn_front (size_t n) {
     pcheck (n);
-    elm_t *sp = firstp;
-    firstp += n;
-    while (sp < firstp)
+    elm_t *sp = this->firstp;
+    this->firstp += n;
+    while (sp < this->firstp)
       destroy (*sp++);
   }
 
