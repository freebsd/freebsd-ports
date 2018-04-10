- Recognize DragonFly as x86_64-linux-gcc target by default

--- build/make/configure.sh.orig	2018-01-24 22:25:44 UTC
+++ build/make/configure.sh
@@ -767,7 +767,7 @@ process_common_toolchain() {
         [ -z "$tgt_isa" ] && tgt_isa=x86
         tgt_os=win32
         ;;
-      *linux*|*bsd*)
+      *linux*|*dragonfly*|*bsd*)
         tgt_os=linux
         ;;
       *solaris2.10)
