--- config/makefiles/rust.mk.orig	2026-09-10 10:00:00 UTC
+++ config/makefiles/rust.mk
@@ -287,7 +287,7 @@
 ifneq (,$(PKG_CONFIG_LIBDIR))
 export PKG_CONFIG_LIBDIR
 endif
-export RUST_BACKTRACE=full
+export RUST_BACKTRACE=0
 export MOZ_TOPOBJDIR=$(topobjdir)
 export MOZ_FOLD_LIBS
 export PYTHON3
