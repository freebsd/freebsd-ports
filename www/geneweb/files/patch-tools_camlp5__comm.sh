--- tools/camlp5_comm.sh.orig	2024-02-11 18:33:15 UTC
+++ tools/camlp5_comm.sh
@@ -1,7 +1,7 @@
 #!/bin/sh
 # $Id: camlp5_comm.sh,v 5.2 2010-09-23 17:16:49 ddr Exp $
 
-ARGS1="$TOP/wserver/pa_macro5.cmo"
+ARGS1="`ocamlfind query camlp5.macro`/pa_macro.cmo"
 FILE=
 while test "" != "$1"; do
 	case $1 in
