--- aclocal.m4.orig	Sat Apr  3 22:30:01 2004
+++ aclocal.m4	Sat Apr  3 22:33:24 2004
@@ -564,89 +564,20 @@
     jm_cv_lib_iconv=""
     jm_cv_giconv=no
     jm_save_LIBS="$LIBS"
-    LIBS="$LIBS -lbiconv"
-    AC_TRY_LINK([#include <stdlib.h>
-#include <biconv.h>],
-        [iconv_t cd = iconv_open("","");
-         iconv(cd,NULL,NULL,NULL,NULL);
-         iconv_close(cd);],
-      jm_cv_func_iconv=yes
-      jm_cv_biconv=yes
-      jm_cv_include="biconv.h"
-      jm_cv_lib_iconv="biconv")
-      LIBS="$jm_save_LIBS"
-
-    dnl Check for include in funny place but no lib needed
-    if test "$jm_cv_func_iconv" != yes; then 
-      AC_TRY_LINK([#include <stdlib.h>
-#include <giconv.h>],
-        [iconv_t cd = iconv_open("","");
-         iconv(cd,NULL,NULL,NULL,NULL);
-         iconv_close(cd);],
-         jm_cv_func_iconv=yes
-         jm_cv_include="giconv.h"
-         jm_cv_giconv="yes"
-         jm_cv_lib_iconv="")
-
-      dnl Standard iconv.h include, lib in glibc or libc ...
-      if test "$jm_cv_func_iconv" != yes; then
-        AC_TRY_LINK([#include <stdlib.h>
+    LIBS="$LIBS -liconv"
+  AC_TRY_LINK([#include <stdlib.h>
 #include <iconv.h>],
-          [iconv_t cd = iconv_open("","");
-           iconv(cd,NULL,NULL,NULL,NULL);
-           iconv_close(cd);],
-           jm_cv_include="iconv.h"
-           jm_cv_func_iconv=yes
-           jm_cv_lib_iconv="")
-
-          if test "$jm_cv_lib_iconv" != yes; then
-            jm_save_LIBS="$LIBS"
-            LIBS="$LIBS -lgiconv"
-            AC_TRY_LINK([#include <stdlib.h>
-#include <giconv.h>],
-              [iconv_t cd = iconv_open("","");
-               iconv(cd,NULL,NULL,NULL,NULL);
-               iconv_close(cd);],
-              jm_cv_lib_iconv=yes
-              jm_cv_func_iconv=yes
-              jm_cv_include="giconv.h"
-              jm_cv_giconv=yes
-              jm_cv_lib_iconv="giconv")
-
-           LIBS="$jm_save_LIBS"
-
-        if test "$jm_cv_func_iconv" != yes; then
-          jm_save_LIBS="$LIBS"
-          LIBS="$LIBS -liconv"
-          AC_TRY_LINK([#include <stdlib.h>
-#include <iconv.h>],
-            [iconv_t cd = iconv_open("","");
-             iconv(cd,NULL,NULL,NULL,NULL);
-             iconv_close(cd);],
-            jm_cv_include="iconv.h"
-            jm_cv_func_iconv=yes
-            jm_cv_lib_iconv="iconv")
-          LIBS="$jm_save_LIBS"
-        fi
-      fi
-    fi
-  fi
+    [iconv_t cd = iconv_open("","");
+     iconv(cd,NULL,NULL,NULL,NULL);
+     iconv_close(cd);],
+    jm_cv_include="iconv.h"
+    jm_cv_func_iconv=yes
+    jm_cv_lib_iconv="iconv")
+    LIBS="$jm_save_LIBS"
   if test "$jm_cv_func_iconv" = yes; then
-    if test "$jm_cv_giconv" = yes; then
-      AC_DEFINE(HAVE_GICONV, 1, [What header to include for iconv() function: giconv.h])
-      AC_MSG_RESULT(yes)
-      ICONV_FOUND=yes
-    else
-      if test "$jm_cv_biconv" = yes; then
-        AC_DEFINE(HAVE_BICONV, 1, [What header to include for iconv() function: biconv.h])
-        AC_MSG_RESULT(yes)
-        ICONV_FOUND=yes
-      else 
-        AC_DEFINE(HAVE_ICONV, 1, [What header to include for iconv() function: iconv.h])
-        AC_MSG_RESULT(yes)
-        ICONV_FOUND=yes
-      fi
-    fi
+    AC_DEFINE(HAVE_ICONV, 1, [What header to include for iconv() function: iconv.h])
+    AC_MSG_RESULT(yes)
+    ICONV_FOUND=yes
   else
     AC_MSG_RESULT(no)
   fi
