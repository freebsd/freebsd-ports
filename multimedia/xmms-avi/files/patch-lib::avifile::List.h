--- lib/avifile/List.h.orig	Mon Nov 27 02:43:55 2000
+++ lib/avifile/List.h	Sun Dec  7 02:30:26 2003
@@ -78,7 +78,7 @@
 
 template<class T>
 class ListNode2 : public ListNode {
-friend List2<T>;
+friend class List2<T>;
 public:
 	ListNode2<T>() {}
 	ListNode2<T>(void *pv) : ListNode(pv) {}
