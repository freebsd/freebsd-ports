
$FreeBSD$

--- m4/firefox-xpi.m4.orig
+++ m4/firefox-xpi.m4
@@ -16,6 +16,9 @@
 		*linux*)
 			TARGET_PLATFORM="Linux"
 			;;
+		*freebsd*)
+			TARGET_PLATFORM="FreeBSD"
+			;;
 		*)
 			AC_MSG_ERROR([Target os $target_os is unknown.
 				Please add the appropriate string to configure.ac.
@@ -28,7 +31,7 @@
 			TARGET_PLATFORM="$TARGET_PLATFORM"_x86-gcc3
 			INSTALL_ARCH=i586
 			;;
-		x86_64)
+		x86_64|amd64)
 				TARGET_PLATFORM="$TARGET_PLATFORM"_x86_64-gcc3
 			INSTALL_ARCH=x86_64
 			;;
