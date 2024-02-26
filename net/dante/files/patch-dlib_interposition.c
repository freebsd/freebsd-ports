--- dlib/interposition.c.orig	2020-11-11 16:11:56 UTC
+++ dlib/interposition.c
@@ -1736,7 +1736,7 @@ getsockopt(s, level, optname, optval, optlen)
    HAVE_PROT_GETSOCKOPT_4 optval;
    HAVE_PROT_GETSOCKOPT_5 optlen;
 {
-   if (socks_issyscall(s, SYMBOL_GETSOCKNAME))
+   if (socks_issyscall(s, SYMBOL_GETSOCKOPT))
       return sys_getsockopt(s, level, optname, optval, optlen);
    return Rgetsockopt(s, level, optname, optval, optlen);
 }
@@ -2168,6 +2168,19 @@ _getsockname(s, name, namelen)
    if (socks_issyscall(s, SYMBOL_GETSOCKNAME))
       return sys_getsockname(s, name, namelen);
    return Rgetsockname(s, name, namelen);
+}
+
+HAVE_PROT_GETSOCKOPT_0
+_getsockopt(s, level, optname, optval, optlen)
+   HAVE_PROT_GETSOCKOPT_1 s;
+   HAVE_PROT_GETSOCKOPT_2 level;
+   HAVE_PROT_GETSOCKOPT_3 optname;
+   HAVE_PROT_GETSOCKOPT_4 optval;
+   HAVE_PROT_GETSOCKOPT_5 optlen;
+{
+   if (socks_issyscall(s, SYMBOL_GETSOCKOPT))
+      return sys_getsockopt(s, level, optname, optval, optlen);
+   return Rgetsockopt(s, level, optname, optval, optlen);
 }
 
 HAVE_PROT_LISTEN_0
