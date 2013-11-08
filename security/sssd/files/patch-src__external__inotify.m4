From 558989d6ac329b4036e02873fb7c981c5912040c Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lslebodn@redhat.com>
Date: Thu, 7 Nov 2013 13:28:13 +0100
Subject: [PATCH] patch-src__external__inotify.m4

---
 src/external/inotify.m4 | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git src/external/inotify.m4 src/external/inotify.m4
index 9572f6d2fefedf8a1d6a2468c712a83e7db2969f..2a5a8cf00d80e0979dca50fd102c3dc2872b2970 100644
--- src/external/inotify.m4
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
-- 
1.8.3.1

