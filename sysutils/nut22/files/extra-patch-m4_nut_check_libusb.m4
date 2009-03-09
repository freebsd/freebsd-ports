--- m4/nut_check_libusb.m4.orig	2009-03-07 23:56:24.000000000 +0300
+++ m4/nut_check_libusb.m4	2009-03-07 23:57:04.000000000 +0300
@@ -17,24 +17,12 @@
 
    dnl Check for libusb libs and flags
    AC_MSG_CHECKING(for libusb cflags)
-   CFLAGS=`libusb-config --cflags 2>/dev/null`
-   if (test "$?" != "0")
-   then
-	AC_MSG_RESULT(not found)
-	nut_have_libusb=no
-   else
-	AC_MSG_RESULT(${CFLAGS})
-   fi
+   CFLAGS=""
+   AC_MSG_RESULT(${CFLAGS})
 
    AC_MSG_CHECKING(for libusb libs)
-   LDFLAGS=`libusb-config --libs 2>/dev/null`
-   if (test "$?" != "0")
-   then
-	AC_MSG_RESULT(not found)
-	nut_have_libusb=no
-   else
-	AC_MSG_RESULT(${LDFLAGS})
-   fi
+   LDFLAGS="-lusb"
+   AC_MSG_RESULT(${LDFLAGS})
 
    if test "${nut_have_libusb}" = "yes"; then
 	LIBUSB_CFLAGS="${CFLAGS}"
