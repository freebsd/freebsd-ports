--- setup.py.orig	2018-12-01 15:27:12 UTC
+++ setup.py
@@ -18,9 +18,9 @@ MACOS_FLAG = ['-mmacosx-version-min=10.7']
 FLAGS_POSIX = [
     '-fPIC', '-std=gnu++0x', '-Wall', '-Wno-parentheses', '-Werror=switch',
 ]
-FLAGS_CLANG = ['-c', '-O3'] + FLAGS_POSIX + ['-stdlib=libc++']
+FLAGS_CLANG = ['-c'] + FLAGS_POSIX
 LFLAGS_POSIX = ['-fPIC',  '-lstdc++']
-LFLAGS_CLANG = ['-fPIC', '-stdlib=libc++']
+LFLAGS_CLANG = ['-fPIC']
 
 sources = ['pysass.cpp']
 headers = []
