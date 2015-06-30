--- test/testone.sh.orig	2015-06-30 18:06:02 UTC
+++ test/testone.sh
@@ -19,7 +19,7 @@ set +f
 TESTNO=$1
 EXPECTED=$2
 #TIDY=../bin/tidy
-TIDY=../build/cmake/tidy5
+TIDY=../build/cmake/tidy
 if [ ! -f "$TIDY" ]; then
 	echo "$BN: Can NOT locate binary '$TIDY'!"
 	echo "$BN: Fix me with the correct location of the binary to run."
