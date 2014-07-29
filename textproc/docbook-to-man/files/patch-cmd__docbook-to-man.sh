--- cmd/docbook-to-man.sh.orig	Mon Jun 17 05:50:30 1996
+++ cmd/docbook-to-man.sh	Fri Oct  5 18:18:22 2001
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
@@ -51,19 +51,16 @@
 doElanPSInclude=true
 
 
-
 # Everything below this line should be pretty standard and not require
 # modification.
 
 #ulimit -c unlimited
 
 PARSER=nsgmls
-INSTANT=instant
+INSTANT=oinstant
 INSTANT_OPT=-d
 
-CATALOG=$DOCBOOK/docbook.cat
-DECL=$DOCBOOK/docbook.dcl
-#PROLOG=$DOCBOOK/docbook.prolog
+CATALOG=$DOCBOOK/catalog
 
 error=false
 
@@ -159,17 +156,8 @@
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
