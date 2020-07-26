--- platform.m4.orig	2018-07-26 20:17:21 UTC
+++ platform.m4
@@ -97,7 +97,7 @@ AC_DEFUN(OD_CONFIG_PLUGIN, [
 	    PLUGIN_LD="${CC} -shared"
 	    PLUGIN_LD_FLAGS=""
 	    PLUGIN_SUFFIX=".so"
-	    LDFLAGS="-export-dynamic"
+	    LDFLAGS="-rdynamic"
 	    ;;
     esac
 
