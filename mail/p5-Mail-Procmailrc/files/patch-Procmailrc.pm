--- Procmailrc.pm.orig	Wed Nov 20 22:15:55 2002
+++ Procmailrc.pm	Wed Feb  5 20:48:22 2003
@@ -6,14 +6,12 @@
 package Mail::Procmailrc;
 ##################################
 
-use 5.006;
 use strict;
-use warnings;
 use Carp qw(confess);
 
-our $VERSION 	= '1.03';
-our $Debug   	= 0;
-our %RE         = (
+use vars qw($VERSION); $VERSION 	= '1.03';
+use vars qw($Debug); $Debug   	= 0;
+use vars qw( %RE); %RE         = (
 		   'flags'    => qr/^\s*:0/o,
 		   'flagsm'   => qr/^\s*(:0.*)$/o,
 		   'var'      => qr/^\s*[^#\$=]+=.+/o,
@@ -389,7 +387,7 @@
 
 ## FIXME: handle comments on the assignment line
 
-our $Debug = 0;
+use vars qw($Debug);$Debug = 0;
 
 sub new {
     my $self = bless { }, shift;
@@ -435,10 +433,10 @@
     $line .= shift @$data;
 
     ## check assignment
-    confess "Could not init: bad pattern in '$line'\n" unless $line =~ /$RE{'var'}/;
+    confess "Could not init: bad pattern in '$line'\n" unless $line =~ /$Mail::Procmailrc::RE{'var'}/;
 
     ## check for continuation
-    while( $line =~ /$RE{'cont'}/ ) {
+    while( $line =~ /$Mail::Procmailrc::RE{'cont'}/ ) {
 	$line .= "\n";
 	$line .= shift @$data;
     }
@@ -571,7 +569,7 @@
   FLAGS: {
 	$line = shift @$data;
 	$line =~ s/^\s*//;
-	confess( "Not a recipe: $line\n" ) unless $line =~ /$RE{'flags'}/;
+	confess( "Not a recipe: $line\n" ) unless $line =~ /$Mail::Procmailrc::RE{'flags'}/;
 	$self->flags($line);
     }
 
@@ -582,13 +580,13 @@
 	$line =~ s/^\s*//;
 
 	## comment/info
-	if( $line =~ s/$RE{'comm'}/$1/ ) {
+	if( $line =~ s/$Mail::Procmailrc::RE{'comm'}/$1/ ) {
 	    push @{$self->info}, $line;
 	    redo INFO;
 	}
 
 	## skip empty lines
-	if( $line =~ /$RE{'blank'}/ ) {
+	if( $line =~ /$Mail::Procmailrc::RE{'blank'}/ ) {
 	    redo INFO;
 	}
 
@@ -603,8 +601,8 @@
 	$line =~ s/^\s*//;
 
 	## check for condition
-	if( $line =~ s/$RE{'condm'}/$1/ ) {
-	    while( $line =~ /$RE{'cont'}/ ) {
+	if( $line =~ s/$Mail::Procmailrc::RE{'condm'}/$1/ ) {
+	    while( $line =~ /$Mail::Procmailrc::RE{'cont'}/ ) {
 		$line .= "\n";         ## tack on the newline for quoted lines
 		$line .= shift @$data;
 	    }
@@ -614,12 +612,12 @@
 	}
 
 	## check for embedded comments and skip them
-	if( $line =~ /$RE{'comt'}/ ) {
+	if( $line =~ /$Mail::Procmailrc::RE{'comt'}/ ) {
 	    redo CONDITIONS;
 	}
 
 	## check for empty lines and skip them
-	if( $line =~ /$RE{'blank'}/ ) {
+	if( $line =~ /$Mail::Procmailrc::RE{'blank'}/ ) {
 	    redo CONDITIONS;
 	}
 
@@ -634,7 +632,7 @@
 	$line =~ s/^\s*//;
 
 	## if contains a '{' we pass it to Procmailrc
-	if( $line =~ /$RE{'blkopen'}/ ) {
+	if( $line =~ /$Mail::Procmailrc::RE{'blkopen'}/ ) {
 	    unshift @$data, $line;
 	    $self->action( Mail::Procmailrc->new( { 'data' => $data, 
 						    'level' => $self->defaults('level') } ));
@@ -642,7 +640,7 @@
 
 	## this is a plain old action line
 	else {
-	    while( $line =~ /$RE{'cont'}/ ) {
+	    while( $line =~ /$Mail::Procmailrc::RE{'cont'}/ ) {
 		$line .= "\n";
 		$line .= shift @$data;
 	    }
@@ -761,7 +759,7 @@
   $pmrc = new Mail::Procmailrc("$HOME/.procmail/rc.spam");
 
   ## add a new variable
-  $pmrc->push( new Mail::Procmailrc::Variable("FOO=bar") );
+  $pmrc->push( new Mail::Procmailrc::Variable(["FOO=bar"]) );
 
   ## add a new recipe
   $recipe =<<'_RECIPE_';
