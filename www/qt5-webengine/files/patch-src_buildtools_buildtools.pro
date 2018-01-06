--- src/buildtools/buildtools.pro
+++ src/buildtools/buildtools.pro
@@ -7,7 +7,7 @@ gn.file = gn.pro
 gn.depends = ninja
 SUBDIRS += gn
 
-linux {
+unix {
     # configure_host.pro and configure_target.pro are phony pro files that
     # extract things like compiler and linker from qmake.
     # Only used on Linux as it is only important for cross-building and alternative compilers.
