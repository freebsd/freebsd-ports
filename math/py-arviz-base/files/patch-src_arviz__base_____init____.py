-- Defer the numpyro converter imports until they are actually accessed, so that
-- importing arviz_base does not require jax/jaxlib.  jaxlib is not available
-- as a usable package in FreeBSD Ports, and these converters are optional.
--- src/arviz_base/__init__.py.orig	2026-06-12 15:47:52 UTC
+++ src/arviz_base/__init__.py
@@ -13,14 +13,26 @@ from arviz_base.io_emcee import from_emcee
 from arviz_base.io_cmdstanpy import from_cmdstanpy
 from arviz_base.io_dict import from_dict
 from arviz_base.io_emcee import from_emcee
-from arviz_base.io_numpyro import (
-    from_numpyro,
-    from_numpyro_svi,
-    NumPyroInferenceAdapter,
-    SVIAdapter,
-    MCMCAdapter,
-)
 from arviz_base.io_pystan import from_pystan
+
+
+def __getattr__(name):
+    if name in {
+        "from_numpyro",
+        "from_numpyro_svi",
+        "NumPyroInferenceAdapter",
+        "SVIAdapter",
+        "MCMCAdapter",
+    }:
+        from arviz_base.io_numpyro import (
+            from_numpyro,
+            from_numpyro_svi,
+            NumPyroInferenceAdapter,
+            SVIAdapter,
+            MCMCAdapter,
+        )
+        return locals()[name]
+    raise AttributeError(f"module {__name__!r} has no attribute {name!r}")
 from arviz_base.rcparams import rc_context, rcParams
 from arviz_base.reorg import (
     extract,
@@ -54,11 +66,6 @@ __all__ = [
     "from_cmdstanpy",
     "from_dict",
     "from_emcee",
-    "from_numpyro",
-    "from_numpyro_svi",
-    "NumPyroInferenceAdapter",
-    "SVIAdapter",
-    "MCMCAdapter",
     # labels submodule
     "labels",
     # rcparams
