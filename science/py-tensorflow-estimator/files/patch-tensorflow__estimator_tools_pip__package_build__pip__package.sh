--- tensorflow_estimator/tools/pip_package/build_pip_package.sh.orig	2019-06-11 17:18:02 UTC
+++ tensorflow_estimator/tools/pip_package/build_pip_package.sh
@@ -38,7 +38,7 @@ function prepare_src() {
 
   # Verifies all expected files are in pip.
   # Creates init files in all directory in pip.
-  python tensorflow_estimator/tools/pip_package/create_pip_helper.py --pip-root "${TMPDIR}/tensorflow_estimator/" --bazel-root "./tensorflow_estimator"
+  %%PYTHON%% tensorflow_estimator/tools/pip_package/create_pip_helper.py --pip-root "${TMPDIR}/tensorflow_estimator/" --bazel-root "./tensorflow_estimator"
 }
 
 function build_wheel() {
@@ -53,7 +53,7 @@ function build_wheel() {
 
   pushd ${TMPDIR} > /dev/null
   echo $(date) : "=== Building wheel"
-  "${PYTHON_BIN_PATH:-python}" setup.py bdist_wheel --universal --project_name $PROJECT_NAME
+  %%PYTHON%% setup.py bdist_wheel --universal --project_name $PROJECT_NAME
   mkdir -p ${DEST}
   cp dist/* ${DEST}
   popd > /dev/null
