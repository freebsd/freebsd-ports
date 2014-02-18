--- siglist.sh	2014-02-12 11:26:07.000000000 +0100
+++ siglist.sh	2014-02-12 11:26:22.000000000 +0100
@@ -23,7 +23,7 @@
 	{ QwErTy SIG\1 , "\1", "\2" },\
 #endif/') > $in
 $CPP $in  > $out
-sed -n 's/{ QwErTy/{/p' < $out | awk '{print NR, $0}' | sort +2n +0n |
+sed -n 's/{ QwErTy/{/p' < $out | awk '{print NR, $0}' | sort -k3n -k1n |
     sed 's/^[0-9]* //' |
     awk 'BEGIN { last=0; nsigs=0; }
 	{
