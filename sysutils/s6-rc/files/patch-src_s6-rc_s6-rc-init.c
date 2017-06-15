--- src/s6-rc/s6-rc-init.c.orig	2015-11-07 00:22:15 UTC
+++ src/s6-rc/s6-rc-init.c
@@ -99,8 +99,10 @@ int main (int argc, char const *const *a
     lfn[llen] = 0 ;
     if (symlink(satmp.s + dirlen, lfn) < 0)
     {
+      char tmp[satmp.len - dirlen] ;
+      byte_copy(tmp, satmp.len - dirlen, satmp.s + dirlen) ;
       cleanup() ;
-      strerr_diefu4sys(111, "symlink ", satmp.s + dirlen, " to ", lfn) ;
+      strerr_diefu4sys(111, "symlink ", tmp, " to ", lfn) ;
     }
     
 
