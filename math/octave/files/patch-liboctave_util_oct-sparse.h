--- liboctave/util/oct-sparse.h.orig	2022-11-02 18:19:56 UTC
+++ liboctave/util/oct-sparse.h
@@ -89,16 +89,27 @@
 #  include <SuiteSparseQR.hpp>
 #endif
 
-// Cope with new SuiteSparse versions
+// Cope with API differences between SuiteSparse versions
 
 #if defined (SUITESPARSE_VERSION)
-#  if (SUITESPARSE_VERSION >= SUITESPARSE_VER_CODE (4, 3))
+#  if (SUITESPARSE_VERSION >= SUITESPARSE_VER_CODE (7, 0))
 #    define SUITESPARSE_NAME(name) SuiteSparse_ ## name
-#    define SUITESPARSE_ASSIGN_FPTR(f_name, f_var, f_assign) (SuiteSparse_config.f_name = f_assign)
-#    define SUITESPARSE_ASSIGN_FPTR2(f_name, f_var, f_assign) (SuiteSparse_config.f_name = SUITESPARSE_NAME (f_assign))
+#    define SUITESPARSE_SET_FCN(name) SuiteSparse_config_ ## name ## _set
+#    define SUITESPARSE_ASSIGN_FPTR(f_name, f_var, f_assign) \
+       SUITESPARSE_SET_FCN(f_name) (f_assign)
+#    define SUITESPARSE_ASSIGN_FPTR2(f_name, f_var, f_assign) \
+       SUITESPARSE_SET_FCN(f_name) (SUITESPARSE_NAME (f_assign))
+#  elif (SUITESPARSE_VERSION >= SUITESPARSE_VER_CODE (4, 3))
+#    define SUITESPARSE_NAME(name) SuiteSparse_ ## name
+#    define SUITESPARSE_ASSIGN_FPTR(f_name, f_var, f_assign) \
+       (SuiteSparse_config.f_name = f_assign)
+#    define SUITESPARSE_ASSIGN_FPTR2(f_name, f_var, f_assign) \
+       (SuiteSparse_config.f_name = SUITESPARSE_NAME (f_assign))
 #  else
-#    define SUITESPARSE_ASSIGN_FPTR(f_name, f_var, f_assign) (f_var = f_assign)
-#    define SUITESPARSE_ASSIGN_FPTR2(f_name, f_var, f_assign) (f_var = CHOLMOD_NAME (f_assign))
+#    define SUITESPARSE_ASSIGN_FPTR(f_name, f_var, f_assign) \
+       (f_var = f_assign)
+#    define SUITESPARSE_ASSIGN_FPTR2(f_name, f_var, f_assign) \
+       (f_var = CHOLMOD_NAME (f_assign))
 #  endif
 #endif
 
