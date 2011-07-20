--- ./t_cltsrv.sh.orig	2011-07-20 22:10:38.000000000 +0200
+++ ./t_cltsrv.sh	2011-07-20 22:10:52.000000000 +0200
@@ -33,7 +33,7 @@
 	    echo "###"
 	    echo "### To run the test in a FreeBSD jail, you MUST add an IP alias for the jail's IP."
 	    echo "###"
-	    exit 1
+	    exit 77
 	fi
     fi
     ;;
