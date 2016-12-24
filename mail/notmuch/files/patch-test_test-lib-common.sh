--- test/test-lib-common.sh.orig	2016-12-24 18:44:17 UTC
+++ test/test-lib-common.sh
@@ -24,6 +24,16 @@
 #
 type die >/dev/null 2>&1 || die () { echo "$@" >&2; exit 1; }
 
+# allow using aliases in scripts
+shopt -s expand_aliases
+
+alias date=gdate
+alias base64=gbase64
+alias gdb=$BSD_GDB
+alias wc=gwc
+alias sed=gsed
+alias sha256sum=gsha256sum
+
 find_notmuch_path ()
 {
     dir="$1"
