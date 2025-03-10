--- m4/ac_check_icu.m4.orig	2021-12-02 14:20:48 UTC
+++ m4/ac_check_icu.m4
@@ -26,7 +26,7 @@ AC_DEFUN([AC_CHECK_ICU],
 			  ICU_VERSION=`$pkgconfigpath --modversion icu-i18n`
 			  ICU_CPPFLAGS=""
 			  ICU_CFLAGS=`$pkgconfigpath --cflags icu-i18n`
-			  ICU_LIBS=`$pkgconfigpath --libs icu-i18n`
+			  ICU_LIBS=`$pkgconfigpath --libs icu-i18n icu-uc`
 		      else
 			  AC_MSG_RESULT([not found])
 		      fi
