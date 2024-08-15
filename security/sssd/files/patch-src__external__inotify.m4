--- src/external/inotify.m4.orig	2020-03-17 13:31:28 UTC
+++ src/external/inotify.m4
@@ -20,10 +20,10 @@ int main () {
     AS_IF([test x"$inotify_works" != xyes],
           [AC_CHECK_LIB([inotify],
                         [inotify_init],
-                        [INOTIFY_LIBS="$sss_extra_libdir -linotify"
+                        [INOTIFY_LIBS="-L$sss_extra_libdir -linotify"
                          inotify_works=yes],
                         [inotify_works=no],
-                        [$sss_extra_libdir])]
+                        [-L$sss_extra_libdir])]
     )
 
     AS_IF([test x"$inotify_works" = xyes],
