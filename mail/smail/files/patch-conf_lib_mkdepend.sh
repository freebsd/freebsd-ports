
$FreeBSD$

--- conf/lib/mkdepend.sh.orig	Tue Dec 31 01:45:53 2002
+++ conf/lib/mkdepend.sh	Tue Dec 31 01:48:30 2002
@@ -60,6 +60,7 @@
 		# the compiler with the sun 3 produces extra garbage after
 		# the quoted filename.
 		sed -n 's/^#[ 	]*[0-9]*[ 	]*"\(.*\)"[ 0-9]*$/\1/p' |
+		grep -v '^<.*>$' |	# remove GCC3 <built-in> etc
 		sed 's%^\./%%' |	# remove ./ prefixes
 		# next remove 
 		sort | uniq |
