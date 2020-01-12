--- m4/cs_omniorb.m4.orig	2019-12-23 11:17:00 UTC
+++ m4/cs_omniorb.m4
@@ -221,7 +221,7 @@ then
   OMNIORB_IDLPYFLAGS_1='-bpython -nf '
   OMNIORB_IDLPYFLAGS_2=" -I${OMNIORB_ROOT}/idl"
   OMNIORB_IDLPYFLAGS=${OMNIORB_IDLPYFLAGS_1}${OMNIORB_IDLPYFLAGS_2}
-  for p in `cut -d: -f 1- --output-delimiter=$'\n' <<<"$PYTHONPATH"`; do
+  for p in `echo "$PYTHONPATH" | tr ':' $'\n'`; do
     if test -f $p/omniidl_be/python.py; then
       OMNIORB_IDLPYFLAGS="${OMNIORB_IDLPYFLAGS} -p ${p}"
     fi
