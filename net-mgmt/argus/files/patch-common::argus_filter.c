--- common/argus_filter.c~	Sat Sep 16 22:36:56 2006
+++ common/argus_filter.c	Sat Sep 16 22:38:10 2006
@@ -3713,7 +3713,7 @@
 extern int ether_hostton(char *, struct ether_addr *);
 #endif
 
-#if !defined(HAVE_ETHER_HOSTTON) && !defined(linux) && !defined(CYGWIN) && !defined(__NetBSD__)
+#if !defined(HAVE_ETHER_HOSTTON) && !defined(linux) && !defined(CYGWIN) && !defined(__NetBSD__) &&!defined(__FreeBSD__)
 extern int ether_ntohost(char *, struct ether_addr *);
 extern int ether_hostton(char *, struct ether_addr *);
 #endif
@@ -4680,7 +4680,7 @@
    register u_char *ap;
    u_char a[6];
 
-#if !defined(HAVE_ETHER_HOSTTON) && !defined(__NetBSD__)
+#if !defined(HAVE_ETHER_HOSTTON) && !defined(__NetBSD__) && !defined(__FreeBSD__)
    extern int ether_hostton(char *, struct ether_addr *);
 #endif
 
