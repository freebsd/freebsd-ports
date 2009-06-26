--- ./m4/aclocal.m4.orig	2009-06-23 09:35:13.000000000 +0000
+++ ./m4/aclocal.m4	2009-06-26 00:41:37.000000000 +0000
@@ -97,14 +97,14 @@
 		build_lib=yes
 		;;
 	*)
-		AC_MSG_RESULT(yes)
+		AC_MSG_RESULT(no)
 		build_lib=no
 		;;
 esac
 ],
 [
 # if unspecified, default is not to build
-AC_MSG_RESULT(yes)
+AC_MSG_RESULT(no)
 build_lib=no
 ]
 )
@@ -416,101 +416,79 @@
   dnl those with the standalone portable libiconv installed).
   AC_MSG_CHECKING(for iconv in $1)
     jm_cv_func_iconv="no"
+    jm_cv_include=""
     jm_cv_lib_iconv=""
-    jm_cv_giconv=no
+    jm_cv_giconv="no"
     jm_save_LIBS="$LIBS"
 
     dnl Check for include in funny place but no lib needed
     if test "$jm_cv_func_iconv" != yes; then 
       AC_TRY_LINK([#include <stdlib.h>
 #include <giconv.h>],
-        [iconv_t cd = iconv_open("","");
-         iconv(cd,NULL,NULL,NULL,NULL);
-         iconv_close(cd);],
-         jm_cv_func_iconv=yes
-         jm_cv_include="giconv.h"
-         jm_cv_giconv="yes"
-         jm_cv_lib_iconv="")
+      [iconv_t cd = iconv_open("","");
+       iconv(cd,NULL,NULL,NULL,NULL);
+       iconv_close(cd);],
+      jm_cv_func_iconv=yes
+      jm_cv_include="giconv.h"
+      jm_cv_lib_iconv=""
+      jm_cv_giconv="yes")
 
       dnl Standard iconv.h include, lib in glibc or libc ...
       if test "$jm_cv_func_iconv" != yes; then
-        AC_TRY_LINK([#include <stdlib.h>
+	AC_TRY_LINK([#include <stdlib.h>
 #include <iconv.h>],
-          [iconv_t cd = iconv_open("","");
-           iconv(cd,NULL,NULL,NULL,NULL);
-           iconv_close(cd);],
-           jm_cv_include="iconv.h"
-           jm_cv_func_iconv=yes
-           jm_cv_lib_iconv="")
+	[iconv_t cd = iconv_open("","");
+         iconv(cd,NULL,NULL,NULL,NULL);
+         iconv_close(cd);],
+	jm_cv_func_iconv=yes
+	jm_cv_include="iconv.h"
+	jm_cv_lib_iconv="")
 
-          if test "$jm_cv_lib_iconv" != yes; then
-            jm_save_LIBS="$LIBS"
-            LIBS="$LIBS -lgiconv"
-            AC_TRY_LINK([#include <stdlib.h>
+	if test "$jm_cv_func_iconv" != yes; then
+	  jm_save_LIBS="$LIBS"
+	  LIBS="$LIBS -lgiconv"
+          AC_TRY_LINK([#include <stdlib.h>
 #include <giconv.h>],
-              [iconv_t cd = iconv_open("","");
-               iconv(cd,NULL,NULL,NULL,NULL);
-               iconv_close(cd);],
-              jm_cv_lib_iconv=yes
-              jm_cv_func_iconv=yes
-              jm_cv_include="giconv.h"
-              jm_cv_giconv=yes
-              jm_cv_lib_iconv="giconv")
+	  [iconv_t cd = iconv_open("","");
+           iconv(cd,NULL,NULL,NULL,NULL);
+           iconv_close(cd);],
+          jm_cv_func_iconv=yes
+          jm_cv_include="giconv.h"
+          jm_cv_lib_iconv="giconv"
+          jm_cv_giconv=yes)
 
-           LIBS="$jm_save_LIBS"
+	  LIBS="$jm_save_LIBS"
 
-        if test "$jm_cv_func_iconv" != yes; then
-          jm_save_LIBS="$LIBS"
-          LIBS="$LIBS -liconv"
-          AC_TRY_LINK([#include <stdlib.h>
+	  if test "$jm_cv_func_iconv" != yes; then
+	    jm_save_LIBS="$LIBS"
+	    LIBS="$LIBS -liconv"
+	    AC_TRY_LINK([#include <stdlib.h>
 #include <iconv.h>],
-            [iconv_t cd = iconv_open("","");
-             iconv(cd,NULL,NULL,NULL,NULL);
-             iconv_close(cd);],
-            jm_cv_include="iconv.h"
-            jm_cv_func_iconv=yes
-            jm_cv_lib_iconv="iconv")
-          LIBS="$jm_save_LIBS"
-
-          if test "$jm_cv_lib_iconv" != yes; then
-            jm_save_LIBS="$LIBS"
-            LIBS="$LIBS -lbiconv"
-            AC_TRY_LINK([#include <stdlib.h>
-#include <biconv.h>],
-              [iconv_t cd = iconv_open("","");
-               iconv(cd,NULL,NULL,NULL,NULL);
-               iconv_close(cd);],
-              jm_cv_lib_iconv=yes
-              jm_cv_func_iconv=yes
-              jm_cv_include="biconv.h"
-              jm_cv_biconv=yes
-              jm_cv_lib_iconv="biconv")
+	    [iconv_t cd = iconv_open("","");
+	     iconv(cd,NULL,NULL,NULL,NULL);
+	     iconv_close(cd);],
+	    jm_cv_func_iconv=yes
+	    jm_cv_include="iconv.h"
+	    jm_cv_lib_iconv="iconv")
 
-            LIBS="$jm_save_LIBS"
+	    LIBS="$jm_save_LIBS"
 	  fi
-        fi
+	fi
       fi
     fi
-  fi
-  if test "$jm_cv_func_iconv" = yes; then
-    if test "$jm_cv_giconv" = yes; then
-      AC_DEFINE(HAVE_GICONV, 1, [What header to include for iconv() function: giconv.h])
-      AC_MSG_RESULT(yes)
-      ICONV_FOUND=yes
-    else
-      if test "$jm_cv_biconv" = yes; then
-        AC_DEFINE(HAVE_BICONV, 1, [What header to include for iconv() function: biconv.h])
-        AC_MSG_RESULT(yes)
-        ICONV_FOUND=yes
+    if test "$jm_cv_func_iconv" = yes; then
+      if test "$jm_cv_giconv" = yes; then
+	AC_DEFINE(HAVE_GICONV, 1, [What header to include for iconv() function: giconv.h])
+	AC_MSG_RESULT(yes)
+	ICONV_FOUND=yes
       else 
         AC_DEFINE(HAVE_ICONV, 1, [What header to include for iconv() function: iconv.h])
         AC_MSG_RESULT(yes)
         ICONV_FOUND=yes
       fi
+    else
+      AC_MSG_RESULT(no)
     fi
-  else
-    AC_MSG_RESULT(no)
-  fi
 ])
 
 AC_DEFUN(rjs_CHARSET,[
@@ -815,6 +793,9 @@
 #include <fcntl.h>
 #include <signal.h>
 
+#ifndef SIGRTMIN
+#define SIGRTMIN NSIG
+#endif
 /* from smbd/notify_kernel.c */
 #ifndef RT_SIGNAL_NOTIFY
 #define RT_SIGNAL_NOTIFY (SIGRTMIN+2)
