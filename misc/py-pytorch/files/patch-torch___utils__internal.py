--- torch/_utils_internal.py.orig	2026-04-18 15:44:50 UTC
+++ torch/_utils_internal.py
@@ -265,7 +265,10 @@ USE_GLOBAL_DEPS = True
 USE_GLOBAL_DEPS = True
 # USE_RTLD_GLOBAL_WITH_LIBTORCH controls whether __init__.py tries to load
 # _C.so with RTLD_GLOBAL during the call to dlopen.
-USE_RTLD_GLOBAL_WITH_LIBTORCH = False
+# On FreeBSD, we need RTLD_GLOBAL to ensure weak RTTI typeinfo symbols (e.g.
+# c10::TypeError) are shared across DSO boundaries, enabling correct C++
+# exception translation in JIT-compiled extensions.
+USE_RTLD_GLOBAL_WITH_LIBTORCH = sys.platform.startswith("freebsd")
 # If an op was defined in C++ and extended from Python using the
 # torch.library.register_fake, returns if we require that there be a
 # m.set_python_module("mylib.ops") call from C++ that associates
