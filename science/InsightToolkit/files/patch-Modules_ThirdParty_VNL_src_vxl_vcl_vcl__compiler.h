--- Modules/ThirdParty/VNL/src/vxl/vcl/vcl_compiler.h.orig	2018-12-16 00:16:56 UTC
+++ Modules/ThirdParty/VNL/src/vxl/vcl/vcl_compiler.h
@@ -86,6 +86,9 @@
 #  else
 #   define VCL_GCC_70
 #  endif
+#  elif (__GNUC__==8)
+#   define VCL_GCC_7
+#   define VCL_GCC_73
 # else
 #  error "Dunno about this gcc"
 # endif
