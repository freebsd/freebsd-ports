--- libclamav/c++/llvm/include/llvm/Support/CFG.h.orig	2016-04-22 15:02:19 UTC
+++ libclamav/c++/llvm/include/llvm/Support/CFG.h
@@ -27,8 +27,9 @@ namespace llvm {
 
 template <class Ptr, class USE_iterator> // Predecessor Iterator
 class PredIterator : public std::iterator<std::forward_iterator_tag,
-                                          Ptr, ptrdiff_t> {
-  typedef std::iterator<std::forward_iterator_tag, Ptr, ptrdiff_t> super;
+                                          Ptr, ptrdiff_t, Ptr*, Ptr*> {
+  typedef std::iterator<std::forward_iterator_tag, Ptr, ptrdiff_t, Ptr*,
+                                                                    Ptr*> super;
   typedef PredIterator<Ptr, USE_iterator> Self;
   USE_iterator It;
 
@@ -40,6 +41,7 @@ class PredIterator : public std::iterator<std::forward
 
 public:
   typedef typename super::pointer pointer;
+  typedef typename super::reference reference;
 
   explicit inline PredIterator(Ptr *bb) : It(bb->use_begin()) {
     advancePastNonTerminators();
@@ -49,7 +51,7 @@ class PredIterator : public std::iterator<std::forward
   inline bool operator==(const Self& x) const { return It == x.It; }
   inline bool operator!=(const Self& x) const { return !operator==(x); }
 
-  inline pointer operator*() const {
+  inline reference operator*() const {
     assert(!It.atEnd() && "pred_iterator out of range!");
     return cast<TerminatorInst>(*It)->getParent();
   }
@@ -87,10 +89,11 @@ inline const_pred_iterator pred_end(const BasicBlock *
 
 template <class Term_, class BB_>           // Successor Iterator
 class SuccIterator : public std::iterator<std::bidirectional_iterator_tag,
-                                          BB_, ptrdiff_t> {
+                                          BB_, ptrdiff_t, BB_*, BB_*> {
   const Term_ Term;
   unsigned idx;
-  typedef std::iterator<std::bidirectional_iterator_tag, BB_, ptrdiff_t> super;
+  typedef std::iterator<std::bidirectional_iterator_tag, BB_, ptrdiff_t, BB_*,
+                                                                    BB_*> super;
   typedef SuccIterator<Term_, BB_> Self;
 
   inline bool index_is_valid(int idx) {
@@ -99,6 +102,7 @@ class SuccIterator : public std::iterator<std::bidirec
 
 public:
   typedef typename super::pointer pointer;
+  typedef typename super::reference reference;
   // TODO: This can be random access iterator, only operator[] missing.
 
   explicit inline SuccIterator(Term_ T) : Term(T), idx(0) {// begin iterator
@@ -122,7 +126,7 @@ class SuccIterator : public std::iterator<std::bidirec
   inline bool operator==(const Self& x) const { return idx == x.idx; }
   inline bool operator!=(const Self& x) const { return !operator==(x); }
 
-  inline pointer operator*() const { return Term->getSuccessor(idx); }
+  inline reference operator*() const { return Term->getSuccessor(idx); }
   inline pointer operator->() const { return operator*(); }
 
   inline Self& operator++() { ++idx; return *this; } // Preincrement
