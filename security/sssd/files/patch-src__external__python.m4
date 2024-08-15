--- src/external/python.m4.orig	2020-03-17 13:31:28 UTC
+++ src/external/python.m4
@@ -36,7 +36,7 @@ --without-$1-bindings when running configure.]))
     if test $? -eq 0; then
         PYTHON_DLOPEN_LIB="` $PYTHON_CONFIG --libs --embed | grep -o -- '-lpython@<:@^ @:>@*' |sed -e 's/^-l/lib/'`"
         if test x"$PYTHON_DLOPEN_LIB" != x; then
-            python_lib_path="` $PYTHON_CONFIG --ldflags | grep -o -- '-L/@<:@^ @:>@*' | sed -e 's/^-L//'`"
+            python_lib_path="` $PYTHON_CONFIG --ldflags | sed -n 's/.*-L\(@<:@^ @:>@*\).*/\1/p'`"
             if test x"$python_lib_path" != x; then
                 PYTHON_DLOPEN_LIB=$python_lib_path"/"$PYTHON_DLOPEN_LIB
             fi
