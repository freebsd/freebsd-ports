--- src/conf_yacc.y.orig	Wed May 29 01:04:27 2002
+++ src/conf_yacc.y	Wed Nov  6 17:27:11 2002
@@ -180,7 +180,7 @@
 	    conferror("Error in expression");
 	    YYABORT;
 	  }
-	  }
+	  } ;
 
 other : TRIGHTS { $$ =$1 ;} | TUSER {$$ =$1 ;} 
         | TGROUP {$$ =$1 ;} | TINODE {$$ =$1 ;}
@@ -242,11 +242,11 @@
 beginconfigstmt : TBEGIN_CONFIG TSTRING {
   conf->do_configmd=1;
   conf->old_confmdstr=strdup($2);
-}
+} ;
 
 endconfigstmt : TEND_CONFIG {
   YYACCEPT;
-}
+} ;
 
 acl_no_symlink_follow : TACLNOSYMLINKFOLLOW TTRUE { 
 #ifdef WITH_ACL
@@ -254,7 +254,7 @@
 #else
   error(0,"ACL-support not compiled in.\n");
 #endif
-}
+} ;
 
 acl_no_symlink_follow : TACLNOSYMLINKFOLLOW TFALSE { 
 #ifdef WITH_ACL
@@ -262,15 +262,15 @@
 #else
   error(0,"ACL-support not compiled in.\n");
 #endif
-}
+} ;
 
 warn_dead_symlinks : TWARNDEADSYMLINKS TTRUE {
   conf->warn_dead_symlinks=1;
-}
+} ;
 
 warn_dead_symlinks : TWARNDEADSYMLINKS TFALSE {
   conf->warn_dead_symlinks=0;
-}
+} ;
 
 gzipdbout : TGZIPDBOUT TTRUE { 
 #ifdef WITH_ZLIB
@@ -288,11 +288,11 @@
 recursion_stopper : TRECSTOP TSTRING {
   /* FIXME implement me */  
   
-}
+} ;
 
 config_version : TCONFIG_VERSION TSTRING {
   conf->config_version=strdup($2);
-}
+} ;
 
 %%
 
