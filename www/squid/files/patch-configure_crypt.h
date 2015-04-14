--- configure.orig	2015-02-27 14:32:14.424780752 +0300
+++ configure	2015-02-27 14:33:30.345774382 +0300
@@ -31843,7 +31843,7 @@
 ##
 
 BUILD_HELPER="NIS"
-for ac_header in sys/types.h rpc/rpc.h rpcsvc/ypclnt.h rpcsvc/yp_prot.h crypt.h
+for ac_header in sys/types.h rpc/rpc.h rpcsvc/ypclnt.h rpcsvc/yp_prot.h rpcsvc/crypt.h
 do :
   as_ac_Header=`$as_echo "ac_cv_header_$ac_header" | $as_tr_sh`
 ac_fn_cxx_check_header_compile "$LINENO" "$ac_header" "$as_ac_Header" "
@@ -32319,7 +32319,7 @@
 
   # unconditionally requires crypt(3), for now
   if test "x$ac_cv_func_crypt" != "x"; then
-    for ac_header in unistd.h crypt.h shadow.h
+    for ac_header in unistd.h rpcsvc/crypt.h shadow.h
 do :
   as_ac_Header=`$as_echo "ac_cv_header_$ac_header" | $as_tr_sh`
 ac_fn_cxx_check_header_mongrel "$LINENO" "$ac_header" "$as_ac_Header" "$ac_includes_default"
@@ -34263,7 +34263,7 @@
   arpa/nameser.h \
   assert.h \
   bstring.h \
-  crypt.h \
+  rpcsvc/crypt.h \
   ctype.h \
   direct.h \
   errno.h \
