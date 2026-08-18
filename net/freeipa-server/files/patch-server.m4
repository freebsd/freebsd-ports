--- server.m4.orig	2026-06-30 18:28:56 UTC
+++ server.m4
@@ -122,7 +122,21 @@ PKG_CHECK_MODULES([SAMBAUTIL], [samba-util])
 PKG_CHECK_MODULES([NDRNBT], [ndr_nbt])
 PKG_CHECK_MODULES([NDR], [ndr])
 PKG_CHECK_MODULES([SAMBAUTIL], [samba-util])
-SAMBA40EXTRA_LIBPATH="-L`$PKG_CONFIG --variable=libdir samba-util`/samba -Wl,-rpath=`$PKG_CONFIG --variable=libdir samba-util`/samba"
+
+SAMBA40LIBDIR=$($PKG_CONFIG --variable=libdir samba-util)
+SAMBA40EXTRA_LIBPATH="-L${SAMBA40LIBDIR}/samba \
+    -Wl,-rpath=${SAMBA40LIBDIR}/samba"
+
+case "$host_os" in
+freebsd*)
+    SAMBA40EXTRA_LIBPATH="${SAMBA40EXTRA_LIBPATH} \
+        -L${SAMBA40LIBDIR} \
+        -L${SAMBA40LIBDIR}/private \
+        -Wl,-rpath=${SAMBA40LIBDIR} \
+        -Wl,-rpath=${SAMBA40LIBDIR}/private"
+    ;;
+esac
+
 AC_SUBST(SAMBA40EXTRA_LIBPATH)
 
 bck_cflags="$CFLAGS"
