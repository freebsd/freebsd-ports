--- files/patch-scripts_libast__prereq.sh.orig	2019-08-04 16:51:09 UTC
+++ files/patch-scripts_libast__prereq.sh
@@ -0,0 +1,30 @@
+--- scripts/libast_prereq.sh.orig	2019-08-04 11:56:35 UTC
++++ scripts/libast_prereq.sh
+@@ -10,7 +10,6 @@
+ #
+ set -e
+ bin_dir="$MESON_SOURCE_ROOT/bin"
+-comp_dir="$MESON_SOURCE_ROOT/src/lib/libast/comp"
+ PATH=$bin_dir:$PATH
+ INC_DIRS=""
+ INC_DIRS="$INC_DIRS -I$MESON_BUILD_ROOT"
+@@ -24,19 +23,6 @@ then
+ fi
+ 
+ cd "$MESON_BUILD_ROOT"
+-
+-if cc --version | grep -q "GCC"
+-then
+-    gcc_major_version=$(cc -dumpversion | cut -d. -f1)
+-    if [ "$gcc_major_version" -ge 9 ]
+-    then
+-        extra_flags="-fno-diagnostics-show-line-numbers"
+-    fi
+-fi
+-
+-# Generate the conftab.[ch] source files.
+-# shellcheck disable=SC2086
+-"$comp_dir/conf.sh" $CC -std=gnu99 -D_BLD_DLL $INC_DIRS $extra_flags
+ 
+ # Generate header files whose content depends on the current platform.
+ "$MESON_SOURCE_ROOT/scripts/siglist.sh" > features/siglist.h
