--- keras/tools/pip_package/build_pip_package.sh.orig	2022-04-22 17:34:55 UTC
+++ keras/tools/pip_package/build_pip_package.sh
@@ -39,7 +39,7 @@ function prepare_src() {
 
   # Verifies all expected files are in pip.
   # Creates init files in all directory in pip.
-  python keras/tools/pip_package/create_pip_helper.py --pip-root "${TMPDIR}/keras/" --bazel-root "./keras"
+  %%PYTHON%% keras/tools/pip_package/create_pip_helper.py --pip-root "${TMPDIR}/keras/" --bazel-root "./keras"
 }
 
 function build_wheel() {
@@ -54,7 +54,7 @@ function build_wheel() {
 
   pushd ${TMPDIR} > /dev/null
   echo $(date) : "=== Building wheel"
-  "${PYTHON_BIN_PATH:-python}" setup.py bdist_wheel --universal --project_name $PROJECT_NAME
+  %%PYTHON%% setup.py bdist_wheel --universal --project_name $PROJECT_NAME
   mkdir -p ${DEST}
   cp dist/* ${DEST}
   popd > /dev/null
