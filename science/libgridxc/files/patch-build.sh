--- build.sh.orig	2018-11-01 22:36:58 UTC
+++ build.sh
@@ -40,14 +40,16 @@
 #
 #
 # Set to "." if empty or unset
-inPREFIX=${PREFIX:-.}
+inPREFIX=${INSTALL_DIR}
 #
 # Build first without MPI
 #
-echo "==> make WITH_LIBXC=${WITH_LIBXC} WITH_MPI= PREFIX=${inPREFIX}/serial"
-sleep 1
-make clean
-make WITH_LIBXC=${WITH_LIBXC} WITH_MPI= PREFIX=${inPREFIX}/serial
+if [ "${WITH_MPI}" = "" ]
+then
+  echo "==> make WITH_LIBXC=${WITH_LIBXC} WITH_MPI= PREFIX=${inPREFIX}/serial"
+  make clean
+  make WITH_LIBXC=${WITH_LIBXC} WITH_MPI= PREFIX=${inPREFIX}/serial
+fi
 #
 # Install the top-level gridxc.mk
 #
@@ -63,7 +66,7 @@ fi
 if [ "${WITH_MPI}" != "" ]
 then
    echo "==> make WITH_LIBXC=${WITH_LIBXC} WITH_MPI=1 PREFIX=${inPREFIX}/mpi"
-   sleep 1
+   #sleep 1
    make clean
    make WITH_LIBXC=${WITH_LIBXC} WITH_MPI=1 PREFIX=${inPREFIX}/mpi
 #
