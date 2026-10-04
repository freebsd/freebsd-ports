--- config/makefiles/rust.mk.orig	2026-09-24 10:45:34 UTC
+++ config/makefiles/rust.mk
@@ -263,7 +263,7 @@
 ifneq (,$(PKG_CONFIG_LIBDIR))
 export PKG_CONFIG_LIBDIR
 endif
-export RUST_BACKTRACE=full
+export RUST_BACKTRACE=0
 export MOZ_TOPOBJDIR=$(topobjdir)
 export MOZ_FOLD_LIBS
 GLEAN_PYTHON_VENV_DIR = $(GRADLE_GLEAN_PARSER_VENV)
