Index: cmulocal/sasl2.m4
diff -u cmulocal/sasl2.m4.orig cmulocal/sasl2.m4
--- cmulocal/sasl2.m4.orig	2009-05-20 21:24:48.000000000 +0900
+++ cmulocal/sasl2.m4	2009-12-22 00:31:16.153536453 +0900
@@ -105,7 +105,7 @@
   if test "$gss_impl" = "auto" -o "$gss_impl" = "heimdal"; then
     gss_failed=0
     AC_CHECK_LIB(gssapi,gss_unwrap,gss_impl="heimdal",gss_failed=1,
-                 ${GSSAPIBASE_LIBS} -lgssapi -lkrb5 -lasn1 -lroken ${LIB_CRYPT} ${LIB_DES} -lcom_err ${LIB_SOCKET})
+                 ${GSSAPIBASE_LIBS} -lgssapi -lkrb5 -lasn1 -lroken ${LIB_CRYPT} ${LIB_DES} -lcom_err ${LIB_SOCKET} -lhx509)
     if test "$gss_impl" != "auto" -a "$gss_failed" = "1"; then
       gss_impl="failed"
     fi
@@ -173,7 +173,7 @@
     GSSAPIBASE_STATIC_LIBS="$GSSAPIBASE_LIBS $gssapi_dir/libgssapi_krb5.a $gssapi_dir/libkrb5.a $gssapi_dir/libk5crypto.a $gssapi_dir/libcom_err.a ${K5SUPSTATIC}"
   elif test "$gss_impl" = "heimdal"; then
     CPPFLAGS="$CPPFLAGS -DKRB5_HEIMDAL"
-    GSSAPIBASE_LIBS="$GSSAPIBASE_LIBS -lgssapi -lkrb5 -lasn1 -lroken ${LIB_CRYPT} ${LIB_DES} -lcom_err"
+    GSSAPIBASE_LIBS="$GSSAPIBASE_LIBS -lgssapi -lkrb5 -lasn1 -lroken ${LIB_CRYPT} ${LIB_DES} -lcom_err -lhx509"
     GSSAPIBASE_STATIC_LIBS="$GSSAPIBASE_STATIC_LIBS $gssapi_dir/libgssapi.a $gssapi_dir/libkrb5.a $gssapi_dir/libasn1.a $gssapi_dir/libroken.a $gssapi_dir/libcom_err.a ${LIB_CRYPT}"
   elif test "$gss_impl" = "cybersafe03"; then
 # Version of CyberSafe with two libraries
