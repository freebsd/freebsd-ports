Do not fail the regexp tests if confget was compiled without regexp support.
This patch has already been applied to the confget upstream Subversion repo.

--- t/09-regexp.t.orig
+++ t/09-regexp.t
@@ -38,6 +38,14 @@
 	exit 255
 fi
 
+v=`$CONFGET -f "$T1" -s a -x key1 2>&1`
+if [ "$v" = 'confget: No regular expression support in this confget build' ]; then
+	for i in 1 2 3 4 5 6 7 8; do
+		echo "ok $i # skip No regular expression support in confget"
+	done
+	exit 0
+fi
+
 unset cfg_key1 cfg_key2 cfg_key3 cfg_key6
 eval `$CONFGET -f "$T1" -S -p cfg_ -s a -L -x 'key[23]'`
 if [ "$cfg_key1" = '' ]; then echo 'ok 1'; else echo "not ok 1 cfg_key1 is '$cfg_key1'"; fi
