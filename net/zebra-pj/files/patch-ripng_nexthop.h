--- ripngd/ripng_nexthop.h-	Tue May 27 23:40:25 2003
+++ ripngd/ripng_nexthop.h	Tue May 27 23:40:26 2003
@@ -41,6 +41,7 @@
  **/
 static inline int
 addr6_cmp(struct in6_addr *A, struct in6_addr *B) {
+#define s6_addr32 __u6_addr.__u6_addr32 /* XXX nonstandard */
 #define a(i) A->s6_addr32[i]
 #define b(i) B->s6_addr32[i]
 
