--- m4/nut_check_libltdl.m4.orig	2023-08-01 07:33:24.593954000 -0700
+++ m4/nut_check_libltdl.m4	2023-08-01 07:35:18.506094000 -0700
@@ -10,10 +10,7 @@
 	dnl No NUT_CHECK_PKGCONFIG here: (lib)ltdl.pc was not seen on any OS
 
 	dnl save CFLAGS and LIBS
-	CFLAGS_ORIG="${CFLAGS}"
-	LIBS_ORIG="${LIBS}"
 	LIBS=""
-	CFLAGS=""
 	dnl For fallback below:
 	myCFLAGS=""
 
@@ -71,7 +68,5 @@
 	unset myCFLAGS
 
 	dnl restore original CFLAGS and LIBS
-	CFLAGS="${CFLAGS_ORIG}"
-	LIBS="${LIBS_ORIG}"
 fi
 ])
