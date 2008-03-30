--- agent/mibgroup/ucd-snmp/memory_freebsd2.c.orig	2008-03-30 14:37:13.262895421 +0900
+++ agent/mibgroup/ucd-snmp/memory_freebsd2.c	2008-03-30 14:37:41.921163790 +0900
@@ -352,7 +352,7 @@
 #ifdef darwin
         long_ret = ptok(mem.v_lookups);
 #else
-        long_ret = ptok(mem.v_cache_count);
+        long_ret = ptok(mem.v_cache_count) + ptok(mem.v_inactive_count);
 #endif
         return ((u_char *) (&long_ret));
 #endif
