
$FreeBSD$

--- source-trees/core/source/config/accompiler.m4.orig
+++ source-trees/core/source/config/accompiler.m4
@@ -880,6 +880,47 @@
         lac_CPPFLAGS="$lac_CPPFLAGS -I/sw/include"
         lac_LDFLAGS="$lac_LDFLAGS -L/sw/lib"
       ;;
+    *-freebsd* )
+        dnl All platforms are currently exclusivly 32 or 64 bit.
+	dnl for maintainer sanity, allow anything for unknown platforms.
+	echo "freebsd: $host"
+        if test "$lac_cv_build_64bit" = "yes"; then
+		case ${host} in
+		i386-*|ppc-*)
+			AC_MSG_ERROR(64 bits not supported on this platform)
+			exit 1
+			;;
+		esac
+	else
+		case ${host} in
+		alpha-*)
+			AC_MSG_ERROR(32 bits not supported on this platform)
+			exit 1
+			;;
+		dnl These might support 32-bits some day.
+		amd64-*|ia64-*|sparc64-*|x64_64-*)
+			AC_MSG_ERROR(32 bits not yet supported on this platform)
+		esac
+        fi
+
+        if test "$GLOBUS_CC" = "mpicc"; then
+            AC_PATH_PROGS(lac_cv_CC,  $CC  mpicc)
+            AC_PATH_PROGS(lac_cv_CXX, $CXX mpicxx mpic++ mpiCC)
+            AC_PATH_PROGS(lac_cv_F77, $F77 mpif77)
+            AC_PATH_PROGS(lac_cv_F90, $F90 mpif90)
+        else
+            if test "$GLOBUS_CC" = "gcc"; then
+                AC_PATH_PROGS(lac_cv_CC, $CC gcc)
+            else
+                AC_PATH_PROGS(lac_cv_CC, $CC cc)
+            fi
+            
+            AC_PATH_PROGS(lac_cv_CXX, $CXX $CCC CC c++ g++ gcc)
+            AC_PATH_PROGS(lac_cv_F77, $F77 f77 g77)
+            AC_PATH_PROGS(lac_cv_F90, $F90 f90)
+        fi
+        CC="$lac_cv_CC"
+      ;;
     * )
         dnl No 64bit support yet
         if test "$lac_cv_build_64bit" = "yes"; then
