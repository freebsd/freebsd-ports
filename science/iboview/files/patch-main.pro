--- main.pro.orig	2015-04-27 21:30:39 UTC
+++ main.pro
@@ -1,5 +1,5 @@
 # /usr/bin/qmake-qt4 -o Makefile main.pro && make -j 4
-MKLDIR = $$(MKLROOT)
+#MKLDIR = $$(MKLROOT)
 # MKLDIR = /opt/intel/composerxe/mkl
 # ^- FIXME: adjust path of MKL here if MKLROOT environment variable is not set.
 # (e.g., 
@@ -8,8 +8,9 @@ MKLDIR = $$(MKLROOT)
 
 # LIBS += -L$$MKLDIR/lib/em64t -lmkl_intel_ilp64 -lmkl_sequential -lmkl_core -lmkl_lapack -Wl,-rpath,$$MKLDIR/lib/em64t
 # LIBS += -L$$MKLDIR/lib/intel64 -lmkl_gf_ilp64 -lmkl_sequential -lmkl_core -Wl,-rpath,$$MKLDIR/lib/intel64
-LIBS += -L$$MKLDIR/lib/intel64 -fopenmp -lmkl_gf_ilp64 -lmkl_gnu_thread -lmkl_core -Wl,-rpath,$$MKLDIR/lib/intel64
+#LIBS += -L$$MKLDIR/lib/intel64 -fopenmp -lmkl_gf_ilp64 -lmkl_gnu_thread -lmkl_core -Wl,-rpath,$$MKLDIR/lib/intel64
 # LIBS += -LC:\Users\cgk\Develop\Libraries\OpenBLAS\bin -lopenblas
+LIBS += -lopenblas
 
 # MICROSCF = ../wmme
 
@@ -52,14 +53,14 @@ HEADERS += $$GL/glew.h $$GL/glxew.h $$GL/wglew.h
 #    from.)
 
 # OpenMP
-msvc {
-   QMAKE_CXXFLAGS += /openmp
-   QMAKE_LFLAGS += /openmp
-}
-!msvc {
-   QMAKE_CXXFLAGS += -fopenmp
-   QMAKE_LFLAGS += -fopenmp
-}
+#msvc {
+#   QMAKE_CXXFLAGS += /openmp
+#   QMAKE_LFLAGS += /openmp
+#}
+#!msvc {
+#   QMAKE_CXXFLAGS += -fopenmp
+#   QMAKE_LFLAGS += -fopenmp
+#}
 # ^- warning: need to replace all OpenMP loop variables by "int". Otherwise won't work
 #    in vc or gcc <= 4.4 (unsigned integral types only allowed since OpenMP 3.0... wtf
 #    were they thinking?!)
