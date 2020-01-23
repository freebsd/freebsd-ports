--- setup.py.orig	2020-01-23 10:17:29 UTC
+++ setup.py
@@ -31,7 +31,7 @@ if sys.platform.startswith('win') and platform.machine
     extra_link_args.append('-Wl,--allow-multiple-definition')
 
 cpp_extra_link_args = extra_link_args
-cpp_extra_compile_args = ["-Wno-cpp", "-Wno-unused-function", "-O2", "-march=native", '-std=c++11']
+cpp_extra_compile_args = ["-Wno-cpp", "-Wno-unused-function", "-O2", '-std=c++11']
 if sys.platform.startswith('darwin'):
     cpp_extra_compile_args.append("-stdlib=libc++")
     cpp_extra_link_args = ["-O2", "-march=native", '-stdlib=libc++']
@@ -189,4 +189,4 @@ setup(
               'get_environment = pymatgen.cli.get_environment:main',
           ]
     }
-)
\ No newline at end of file
+)
