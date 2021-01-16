# https://github.com/pbiering/ipv6calc/commit/6c89a416d5c8979058d9ae4a8b80c7732982c396
--- databases/lib/libipv6calc_db_wrapper.c.orig	2021-01-13 06:59:44 UTC
+++ databases/lib/libipv6calc_db_wrapper.c
@@ -2327,10 +2327,17 @@ int libipv6calc_db_wrapper_registry_num_by_ipv6addr(co
 	DEBUGPRINT_WA(DEBUG_libipv6calc_db_wrapper, "Called: addr=%08x%08x%08x%08x", ipv6addr_getdword(ipv6addrp, 0), ipv6addr_getdword(ipv6addrp, 1), ipv6addr_getdword(ipv6addrp, 2), ipv6addr_getdword(ipv6addrp, 3));
 
 	if ((cache_lu_ipv6addr_valid == 1)
+#ifdef __KAME__ // FreeBSD misses s6_addr8/16/32 in non-kernel include, also union has different name in glibc (__in6_u vs.  __u6_addr) :-(
+	    &&  (&cache_lu_ipv6addr.in6_addr.__u6_addr.__u6_addr32[0] == &ipv6addrp->in6_addr.__u6_addr.__u6_addr32[0])
+	    &&  (&cache_lu_ipv6addr.in6_addr.__u6_addr.__u6_addr32[1] == &ipv6addrp->in6_addr.__u6_addr.__u6_addr32[1])
+	    &&  (&cache_lu_ipv6addr.in6_addr.__u6_addr.__u6_addr32[2] == &ipv6addrp->in6_addr.__u6_addr.__u6_addr32[2])
+	    &&  (&cache_lu_ipv6addr.in6_addr.__u6_addr.__u6_addr32[3] == &ipv6addrp->in6_addr.__u6_addr.__u6_addr32[3])
+#else
 	    &&  (&cache_lu_ipv6addr.in6_addr.s6_addr32[0] == &ipv6addrp->in6_addr.s6_addr32[0])
 	    &&  (&cache_lu_ipv6addr.in6_addr.s6_addr32[1] == &ipv6addrp->in6_addr.s6_addr32[1])
 	    &&  (&cache_lu_ipv6addr.in6_addr.s6_addr32[2] == &ipv6addrp->in6_addr.s6_addr32[2])
 	    &&  (&cache_lu_ipv6addr.in6_addr.s6_addr32[3] == &ipv6addrp->in6_addr.s6_addr32[3])
+#endif
 	) {
 		retval= cache_lu_ipv6addr_registry_num;
 		cache_hit = 1;
