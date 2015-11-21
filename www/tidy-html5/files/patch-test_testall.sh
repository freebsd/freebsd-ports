--- test/testall.sh.orig	2015-11-18 19:02:54 UTC
+++ test/testall.sh
@@ -18,7 +18,7 @@ d_now()
 # testone.sh uses tempall.txt, so
 TMPLOG="tempall.txt"
 # same EXE
-TMPTIDY=../build/cmake/tidy
+TMPTIDY=../tidy
 
 TMPNOW=`d_now`
 TMPINP="testcases.txt"
