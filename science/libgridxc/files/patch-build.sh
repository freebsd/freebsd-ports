--- build.sh.orig	2018-02-01 10:48:08 UTC
+++ build.sh
@@ -39,14 +39,17 @@
 # libGridXC installations in the old style.
 #
 #
-inPREFIX=${PREFIX}
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
+  #sleep 1
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
