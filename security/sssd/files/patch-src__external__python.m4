--- src/external/python.m4	2020-03-17 09:31:28.000000000 -0400
+++ src/external/python.m4	2022-02-22 22:55:04.425467000 -0500
@@ -37,5 +37,5 @@
         PYTHON_DLOPEN_LIB="` $PYTHON_CONFIG --libs --embed | grep -o -- '-lpython@<:@^ @:>@*' |sed -e 's/^-l/lib/'`"
         if test x"$PYTHON_DLOPEN_LIB" != x; then
-            python_lib_path="` $PYTHON_CONFIG --ldflags | grep -o -- '-L/@<:@^ @:>@*' | sed -e 's/^-L//'`"
+            python_lib_path="` $PYTHON_CONFIG --ldflags | sed -n 's/.*-L\(@<:@^ @:>@*\).*/\1/p'`"
             if test x"$python_lib_path" != x; then
                 PYTHON_DLOPEN_LIB=$python_lib_path"/"$PYTHON_DLOPEN_LIB
