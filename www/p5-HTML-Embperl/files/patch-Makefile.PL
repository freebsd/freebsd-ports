--- Makefile.PL.orig	Mon Mar 11 21:05:16 2002
+++ Makefile.PL	Sat May  8 00:11:32 2004
@@ -27,49 +27,49 @@
 %neededmodules =
     ( 
       'mod_perl.c' => { name	    => 'perl_module', 
-			path	    => ['$apache_src/modules/perl/libperl.so', '$EPBINDIR/modules/libperl.so', '$apache_src/mod_perl.so'],
+			path	    => ['$apache_src/modules/perl/libperl.so', '$EPBINDIR/modules/libperl.so', '$apache_src/mod_perl.so', '$EPMODDIR/libperl.so'],
 			win32path   => ['$mpdll', '$mpdll/apachemoduleperl.dll', '$mpdll/mod_perl.so', '$EPBINDIR/modules/apachemoduleperl.dll', '$EPBINDIR/modules/mod_perl.so'],
 			file	    => ['libperl.so', 'apachemoduleperl.dll', 'mod_perl.so'],
 			filetext    => 'libperl.so or mod_perl.so',
 			win32filetext   => 'ApacheModulePerl.dll or mod_perl.so',
 		      },
       'mod_dir.c'  => { name	    => 'dir_module', 
-			path	    => ['$apache_src/modules/standard/mod_dir.so', '$EPBINDIR/modules/mod_dir.so', '$apache_src/mod_dir.so'],
+			path	    => ['$apache_src/modules/standard/mod_dir.so', '$EPBINDIR/modules/mod_dir.so', '$apache_src/mod_dir.so', '$EPMODDIR/mod_dir.so'],
 			win32path   => ['$apache_src/modules/standard/apachemoduledir.dll', '$EPBINDIR/modules/apachemoduledir.dll', '$EPBINDIR/modules/mod_dir.so'],
 			file	    => ['mod_dir.so', 'apachemoduledir.dll'],
 			win32filetext   => 'ApacheModuleDir.dll or mod_dir.so',
 		      },
 
       'mod_env.c'  => { name	    => 'env_module', 
-			path	    => ['$apache_src/modules/standard/mod_env.so', '$EPBINDIR/modules/mod_env.so', '$apache_src/mod_env.so'],
+			path	    => ['$apache_src/modules/standard/mod_env.so', '$EPBINDIR/modules/mod_env.so', '$apache_src/mod_env.so', '$EPMODDIR/mod_env.so'],
 			win32path   => ['$apache_src/modules/standard/apachemoduleenv.dll', '$EPBINDIR/modules/apachemoduleenv.dll', '$EPBINDIR/modules/mod_env.so'],
 			file	    => ['mod_env.so', 'apachemoduleenv.dll'],
 			win32filetext   => 'ApacheModuleEnv.dll or mod_env.so',
 		      },
 
       'mod_mime.c'  => { name	    => 'mime_module', 
-			path	    => ['$apache_src/modules/standard/mod_mime.so', '$EPBINDIR/modules/mod_mime.so', '$apache_src/mod_mime.so'],
+			path	    => ['$apache_src/modules/standard/mod_mime.so', '$EPBINDIR/modules/mod_mime.so', '$apache_src/mod_mime.so', '$EPMODDIR/mod_mime.so'],
 			win32path   => ['$apache_src/modules/standard/apachemodulemime.dll', '$EPBINDIR/modules/apachemodulemime.dll', '$EPBINDIR/modules/mod_mime.so'],
 			file	    => ['mod_mime.so', 'apachemodulemime.dll'],
 			win32filetext   => 'ApacheModuleMime.dll or mod_mime.so',
 		      },
 
       'mod_alias.c'  => { name	    => 'alias_module', 
-			path	    => ['$apache_src/modules/standard/mod_alias.so', '$EPBINDIR/modules/mod_alias.so', '$apache_src/mod_alias.so'],
+			path	    => ['$apache_src/modules/standard/mod_alias.so', '$EPBINDIR/modules/mod_alias.so', '$apache_src/mod_alias.so', '$EPMODDIR/mod_alias.so'],
 			win32path   => ['$apache_src/modules/standard/apachemodulealias.dll', '$EPBINDIR/modules/apachemodulealias.dll', '$EPBINDIR/modules/mod_alias.so'],
 			file	    => ['mod_alias.so', 'apachemodulealias.dll'],
 			win32filetext   => 'ApacheModuleAlias.dll or mod_alias.so',
 		      },
 
       'mod_cgi.c'  => { name	    => 'cgi_module', 
-			path	    => ['$apache_src/modules/standard/mod_cgi.so', '$EPBINDIR/modules/mod_cgi.so', '$apache_src/mod_cgi.so'],
+			path	    => ['$apache_src/modules/standard/mod_cgi.so', '$EPBINDIR/modules/mod_cgi.so', '$apache_src/mod_cgi.so', '$EPMODDIR/mod_cgi.so'],
 			win32path   => ['$apache_src/modules/standard/apachemodulecgi.dll', '$EPBINDIR/modules/apachemodulecgi.dll', '$EPBINDIR/modules/mod_cgi.so'],
 			file	    => ['mod_cgi.so', 'apachemodulecgi.dll'],
 			win32filetext   => 'ApacheModuleCgi.dll or mod_cgi.so',
 		      },
 
       'mod_actions.c'  => { name	    => 'action_module', 
-			path	    => ['$apache_src/modules/standard/mod_actions.so', '$EPBINDIR/modules/mod_actions.so', '$apache_src/mod_actions.so'],
+			path	    => ['$apache_src/modules/standard/mod_actions.so', '$EPBINDIR/modules/mod_actions.so', '$apache_src/mod_actions.so', '$EPMODDIR/mod_actions.so'],
 			win32path   => ['$apache_src/modules/standard/apachemoduleactions.dll', '$EPBINDIR/modules/apachemoduleactions.dll', '$EPBINDIR/modules/mod_actions.so'],
 			file	    => ['mod_actions.so','apachemoduleactions.dll'],
 			win32filetext   => 'ApacheModuleActions.dll or mod_actions.so',
@@ -522,8 +522,7 @@
 $base = '..' ;
 $base = $ENV{'ProgramFiles'} if ($win32) ;
 
-
-$apache = GetYesNo ("Build with support for Apache mod_perl?", 'y') if (!$apache) ;
+$apache = GetYesNo ("Build with support for Apache mod_perl?", 'y') if (!$apache && !defined ($ENV{NOAPACHE})) ;
 
 if ($apache && $apache_src ne '')
     {
@@ -780,6 +779,7 @@
     $EPMOD_SSL    = !$EPSTRONGHOLD && grep (/mod_ssl.c/, @modules) ;
 
     $EPBINDIR	  = dirname ($EPHTTPD) ;    
+    $EPMODDIR     = $ENV{EPMODDIR} if (defined ($ENV{EPMODDIR})) ;
     $EPMODPERL	  = '' ;
     
     $addmodpath = '' ;
