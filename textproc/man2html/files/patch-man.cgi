--- man.cgi.orig	1997-08-12 17:19:18 UTC
+++ man.cgi
@@ -59,8 +59,8 @@ $ManPrg		= '/usr/bin/man';
 ##  systems.  If using Tom Christiansen's Perl man program, than
 ##  define use "".
 
-#$SectOpt	= "";
-$SectOpt	= "-s";
+$SectOpt	= "";
+#$SectOpt	= "-s";
 
 ##  man2html program (needs to be a full pathname)
 
@@ -77,15 +77,15 @@ $DoCgiurl	= 1;
 
 #@ConvArgs	= ("-compress");
 #@ConvArgs	= ("-compress", "-leftm", "1", "-topm", "8");
-@ConvArgs	= ("-compress", "-sun");
+#@ConvArgs	= ("-compress", "-sun");
 
 ##  Keyword search processing arguments for man2html.  Normally,
 ##  '-k' is adequate.  However, if on a Solaris system, the
 ##  '-solaris' option should be specified with '-k'.  See
 ##  man2html documentation on information about the '-solaris' option.
 
-#@KeyWArgs	= ("-k");			# Normal
-@KeyWArgs	= ("-k", "-solaris");		# For Solaris
+@KeyWArgs	= ("-k");			# Normal
+#@KeyWArgs	= ("-k", "-solaris");		# For Solaris
 
 ##  Possible manual sections.  This array is used to determine the
 ##  the choices available in an option menu.
@@ -124,9 +124,9 @@ $ArgSep		= '&';
 ##  know about
 
 @ManPath	= qw(
+    /usr/share/man
     /usr/local/man
-    /usr/openwin/man
-    /usr/man
+    /usr/local/share/man
 );
 
 ##  PATH setting.  Modify as see fit.  Once useful modification
@@ -134,7 +134,6 @@ $ArgSep		= '&';
 ##  be invoked over the systems nroff when man formats a manpage.
 
 @Path   	= qw(
-    /opt/FSFgroff/bin
     /bin
     /usr/bin
 );
@@ -270,7 +269,7 @@ sub doit {
 
     # Convert output from man to html
     #--------------------------------
-    close(STDERR);
+    open(STDERR, ">&/dev/null");
     open(MANPRG, "-|") or exec($ManPrg, @manargs);
     $Man2Html::InFH = \*MANPRG;		# set input filehandle
     require $ManConvPrg or
