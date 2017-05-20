--- RegressionTests/RunTests.sh.orig	2009-08-05 03:09:24 UTC
+++ RegressionTests/RunTests.sh
@@ -54,7 +54,7 @@ msort -j -q -l -w -c n -Q < CheckOnlyTes
 rstat2=$?
 cmp -s CheckOnlyTest01B.result CheckOnlyTest01.norm
 cstat2=$?
-if [[($rstat1 == 0) && ($cstat1 == 0) && ($cstat2 == 0) && ($rstat2 > 0)]];
+if [ $rstat1 -eq 0 -a $cstat1 -eq 0 -a $cstat2 -eq 0 -a $rstat2 -gt 0 ];
 then echo "PASSED" >> TestResults;
 else echo $'\x1b[1m\x1b[31mFAILED\x1b[0m' >> TestResults;
 fi
