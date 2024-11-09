--- cmd/docbook-to-man.sh.orig	1996-06-17 03:50:30 UTC
+++ cmd/docbook-to-man.sh
@@ -40,9 +40,9 @@
 # ***** change the following paths if your installation of nsgmls and / or
 # ***** DocBook isn't into the default places.
 
-ROOT=/usr/local
-SGMLS=$ROOT/lib/sgml
-DOCBOOK=$SGMLS/Davenport/dtd
+ROOT=%%PREFIX%%
+SGMLS=$ROOT/share/sgml
+DOCBOOK=$SGMLS/docbook
 
 
 # ***** modify the following line (to "=false") if you're not using the
@@ -57,13 +57,11 @@ doElanPSInclude=true
 
 #ulimit -c unlimited
 
-PARSER=nsgmls
-INSTANT=instant
+PARSER=onsgmls
+INSTANT=oinstant
 INSTANT_OPT=-d
 
-CATALOG=$DOCBOOK/docbook.cat
-DECL=$DOCBOOK/docbook.dcl
-#PROLOG=$DOCBOOK/docbook.prolog
+CATALOG=$DOCBOOK/catalog
 
 error=false
 
@@ -159,17 +157,8 @@ cat >> /tmp/dtm.$$.psinc <<\!
 .ds f4\"
 !
 
-
-#if [ ! -f $PROLOG ]
-#then	cat > $PROLOG <<!
-#<!DOCTYPE RefEntry PUBLIC "-//Davenport//DTD DocBook V2.4.1//EN" [
-#<!ENTITY npzwc "">
-#]>
-#!
-#fi
-
 (cat /tmp/dtm.$$.psinc;
- $PARSER -gl -m$CATALOG $DECL $INSTANCE |
+ $PARSER -gl -c $CATALOG $INSTANCE |
 	$INSTANT $INSTANT_OPT -croff.cmap -sroff.sdata -tdocbook-to-man.ts)
 
-rm -f /tmp/dtm.$$.psinc    
+rm -f /tmp/dtm.$$.psinc
