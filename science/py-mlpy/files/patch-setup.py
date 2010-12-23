--- setup.py.orig	2010-10-18 20:08:13.000000000 +0800
+++ setup.py	2010-12-23 15:19:09.000000000 +0800
@@ -158,11 +158,13 @@
                               "mlpy/liblinear/liblinear/blas/daxpy.c",
                               "mlpy/liblinear/liblinear/blas/ddot.c",
                               "mlpy/liblinear/liblinear/blas/dnrm2.c",
-                              "mlpy/liblinear/liblinear/blas/dscal.c"], 
+                              "mlpy/liblinear/liblinear/blas/dscal.c"],
+                             include_dirs=base_include, 
                              extra_compile_args=extra_compile_args),
                    Extension("mlpy.libsvm",
                              ["mlpy/libsvm/libsvm/svm.cpp",
                               "mlpy/libsvm/libsvm.pyx"],
+                             include_dirs=base_include,
                              extra_compile_args=extra_compile_args)
                    ],
       scripts=["mlpy/tools/mlpy-test"],
