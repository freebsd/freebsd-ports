--- vpnd.c.old	Sun Mar 25 01:58:06 2001
+++ vpnd.c	Sun Mar 25 03:02:26 2001
@@ -41,7 +41,8 @@
 	       "       vpnd -c <extended-master-key-file>\n" \
 	       USAGE1 \
 	       "    -h prints this info\n" \
-	       "    -m creates master key file (default is /etc/vpnd.key),\n" \
+	       "    -m creates master key file (default is " ETC_DIR \
+	       "/vpnd.key),\n" \
 	       "       note that the file must not yet exist\n" \
 	       "    -x creates extended master key files named vpnd.lcl.key\n" \
 	       "       and vpnd.rmt.key in the given directory,\n" \
@@ -65,7 +66,7 @@
                "    -l allow dns lookups so host names can be used\n" \
 	       "    -n do not become daemon\n" \
 	       "    -t do modem init chat test\n" \
-	       "    -f use configfile instead of /etc/vpnd.conf\n" \
+	       "    -f use configfile instead of " ETC_DIR "/vpnd.conf\n" \
 	       COMPRESSINFO
 
 /*
