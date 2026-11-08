--- scripts/build_vendored_libffi.sh.orig	2026-10-20 14:29:52 UTC
+++ scripts/build_vendored_libffi.sh
@@ -85,10 +85,10 @@ LIBFFI_MAKE_FLAGS="LIBTOOL='sh ./libtool' AM_MAKEFLAGS
 
 # libffi clears MAKEOVERRIDES, so carry the relative libtool command through both recursive levels.
 LIBFFI_MAKE_FLAGS="LIBTOOL='sh ./libtool' AM_MAKEFLAGS=\"LIBTOOL='sh ./libtool'\""
-if ! make -C "$BUILD" SHELL=sh "AM_MAKEFLAGS=$LIBFFI_MAKE_FLAGS" -j"${NIFT_BUILD_JOBS:-2}" >"$LOG" 2>&1; then
+if ! gmake -C "$BUILD" SHELL=sh "AM_MAKEFLAGS=$LIBFFI_MAKE_FLAGS" -j"${NIFT_BUILD_JOBS:-2}" >"$LOG" 2>&1; then
   fail_build
 fi
-if ! make -C "$BUILD" SHELL=sh "AM_MAKEFLAGS=$LIBFFI_MAKE_FLAGS" install >>"$LOG" 2>&1; then
+if ! gmake -C "$BUILD" SHELL=sh "AM_MAKEFLAGS=$LIBFFI_MAKE_FLAGS" install >>"$LOG" 2>&1; then
   fail_build
 fi
 printf '%s\n' "$FINGERPRINT" > "$BUILD/.nift-fingerprint"
