--- main.pro.orig	2026-09-17 12:05:47 UTC
+++ main.pro
@@ -184,8 +184,8 @@ win32 {
 !win32 {
    # Flags for g++ or clang (in g++ emulation mode on linux)
    OPTFLAGS_OFF = -O2
-   OPTFLAGS_ON = -Ofast -ffast-math -march=native
-   QMAKE_CXXFLAGS += -Wno-deprecated-copy -Wno-class-memaccess -Wno-implicit-fallthrough -Wno-unknown-pragmas -fmax-errors=10
+   OPTFLAGS_ON = -Ofast -ffast-math
+   QMAKE_CXXFLAGS += -Wno-deprecated-copy -Wno-class-memaccess -Wno-implicit-fallthrough -Wno-unknown-pragmas
    # DEFINES += _GLIBCXX_PARALLEL
    # ^-- Interesting, see: https://gcc.gnu.org/onlinedocs/libstdc++/manual/parallel_mode_using.html
    #     But still not sure what to think about this. In any case, we
