--- File/KGlob.pm.orig	Wed Apr 17 13:05:33 2002
+++ File/KGlob.pm	Wed Apr 17 13:06:10 2002
@@ -79,7 +79,7 @@
 	    if(  m#(^|[^\\])(\\\\)*[\[\?\*]#  ) {   # Some kind of wildcard:
 		push( @return, &pglob($_) );	    # Find matching files.
 	    } else {		    # Just a string, perhaps with \-quoting:
-		s/\\(.)/\1/g;	    # Remove the \'s used for quoting.
+		s/\\(.)/$1/g;	    # Remove the \'s used for quoting.
 		push( @return, $_ );
 	    }
 	}
@@ -106,8 +106,8 @@
 		$mid= substr( $temp, 0, $pos );	# Part between "{" and "}"  #{
 		$aft= substr( $temp, 1 + $pos );	# Part after "}"
 		if(  $mid =~ m#(^|[^\\])(\\\\)*$#  ) {	#{ The "}" is unquoted:
-		    $mid =~ s/((^|[^\\])(\\\\))*,/\1\0/g; # Most unquoted ","s
-		    $mid =~ s/((^|[^\\])(\\\\))*,/\1\0/g; # Remaining ones
+		    $mid =~ s/((^|[^\\])(\\\\))*,/$1$0/g; # Most unquoted ","s
+		    $mid =~ s/((^|[^\\])(\\\\))*,/$1$0/g; # Remaining ones
 		    return &mcat( $bef, $aft, split(/\0/,$mid) );	# Done!
 		}	# &mcat builds all of the resulting strings.
 	    }		# &mcat also "unbrac"s $bef and $aft.
@@ -228,7 +228,7 @@
 	$nodots= "." ne substr($glob,0,1);	# Skip all .*'s unless explicit
 	chop $glob   if  $onlydirs= "/" eq substr($glob,-1,1);
 	# File::KGlob2RE uses "%" for "any subdir(s)" but we don't so...
-	$glob =~ s#((^|[^\\])(\\\\)*)\%#\1\\%#g;    # quote any unquoted "%"s.
+	$glob =~ s#((^|[^\\])(\\\\)*)\%#$1\\%#g;    # quote any unquoted "%"s.
 	$re= &File::KGlob2RE::kglob2re( $glob );    # Change glob to regexp.
 	$dir= "."   if  "" eq $dir;
 	if(  ! opendir( $hndl, $dir )  ) {
