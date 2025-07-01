--- tensorflow/tools/pip_package/build_pip_package.sh.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/tools/pip_package/build_pip_package.sh
@@ -183,9 +183,9 @@ function prepare_src() {
       bazel-bin/tensorflow/tools/pip_package/build_pip_package.runfiles/org_tensorflow \
       "${XLA_AOT_RUNTIME_SOURCES}"
     # Copy MKL libs over so they can be loaded at runtime
-    # TODO(b/271299337): shared libraries that depend on libbfloat16.so.so have
+    # TODO(b/271299337): shared libraries that depend on libbfloat16.so have
     # their NEEDED and RUNPATH set corresponding to a dependency on
-    # RUNFILES/_solib_local/libtensorflow_Stsl_Spython_Slib_Score_Slibbfloat16.so.so,
+    # RUNFILES/_solib_local/libtensorflow_Stsl_Spython_Slib_Score_Slibbfloat16.so,
     # which is a symlink to tensorflow/tsl/python/lib/core/libbfloat16.so in
     # the Bazel build tree. We do not export the file in _solib_local (nor
     # symlinks in general, I think Python wheels have poor support for them?)
@@ -193,13 +193,13 @@ function prepare_src() {
     if is_macos; then
       chmod +rw ${TMPDIR}/tensorflow/tsl/python/lib/core/pywrap_bfloat16.so
       chmod +rw ${TMPDIR}/tensorflow/python/_pywrap_tensorflow_internal.so
-      install_name_tool -change "@loader_path/../../../../../${so_lib_dir}//libtensorflow_Stsl_Spython_Slib_Score_Slibbfloat16.so.so" "@loader_path/libbfloat16.so.so" ${TMPDIR}/tensorflow/tsl/python/lib/core/pywrap_bfloat16.so
-      install_name_tool -change "@loader_path/../../${so_lib_dir}//libtensorflow_Stsl_Spython_Slib_Score_Slibbfloat16.so.so" "@loader_path/../tsl/python/lib/core/libbfloat16.so.so" ${TMPDIR}/tensorflow/python/_pywrap_tensorflow_internal.so
+      install_name_tool -change "@loader_path/../../../../../${so_lib_dir}//libtensorflow_Stsl_Spython_Slib_Score_Slibbfloat16.so" "@loader_path/libbfloat16.so" ${TMPDIR}/tensorflow/tsl/python/lib/core/pywrap_bfloat16.so
+      install_name_tool -change "@loader_path/../../${so_lib_dir}//libtensorflow_Stsl_Spython_Slib_Score_Slibbfloat16.so" "@loader_path/../tsl/python/lib/core/libbfloat16.so" ${TMPDIR}/tensorflow/python/_pywrap_tensorflow_internal.so
     else
       chmod +rw ${TMPDIR}/tensorflow/tsl/python/lib/core/pywrap_bfloat16.so
       chmod +rw ${TMPDIR}/tensorflow/python/_pywrap_tensorflow_internal.so
-      patchelf --replace-needed libtensorflow_Stsl_Spython_Slib_Score_Slibbfloat16.so.so libbfloat16.so.so ${TMPDIR}/tensorflow/tsl/python/lib/core/pywrap_bfloat16.so
-      patchelf --replace-needed libtensorflow_Stsl_Spython_Slib_Score_Slibbfloat16.so.so libbfloat16.so.so ${TMPDIR}/tensorflow/python/_pywrap_tensorflow_internal.so
+      patchelf --replace-needed libtensorflow_Stsl_Spython_Slib_Score_Slibbfloat16.so libbfloat16.so ${TMPDIR}/tensorflow/tsl/python/lib/core/pywrap_bfloat16.so
+      patchelf --replace-needed libtensorflow_Stsl_Spython_Slib_Score_Slibbfloat16.so libbfloat16.so ${TMPDIR}/tensorflow/python/_pywrap_tensorflow_internal.so
       patchelf --set-rpath $(patchelf --print-rpath ${TMPDIR}/tensorflow/tsl/python/lib/core/pywrap_bfloat16.so):\$ORIGIN ${TMPDIR}/tensorflow/tsl/python/lib/core/pywrap_bfloat16.so
       patchelf --set-rpath $(patchelf --print-rpath ${TMPDIR}/tensorflow/python/_pywrap_tensorflow_internal.so):\$ORIGIN/../tsl/python/lib/core ${TMPDIR}/tensorflow/python/_pywrap_tensorflow_internal.so
       patchelf --shrink-rpath ${TMPDIR}/tensorflow/tsl/python/lib/core/pywrap_bfloat16.so
