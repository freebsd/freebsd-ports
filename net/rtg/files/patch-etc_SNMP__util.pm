--- etc/SNMP_util.pm.orig	2018-04-02 22:51:02 UTC
+++ etc/SNMP_util.pm
@@ -1129,16 +1129,16 @@ sub snmpMIB_to_OID ($) {
       $buf =~ s/OBJECT-GROUP/OBJECT IDENTIFIER/;
       $buf =~ s/MODULE-IDENTITY/OBJECT IDENTIFIER/;
       $buf =~ s/ IMPORTS .*\;//;
-      $buf =~ s/ SEQUENCE {.*}//;
+      $buf =~ s/ SEQUENCE \{.*}//;
       $buf =~ s/ SYNTAX .*//;
       $buf =~ s/ [\w-]+ ::= OBJECT IDENTIFIER//;
-      $buf =~ s/ OBJECT IDENTIFIER .* ::= {/ OBJECT IDENTIFIER ::= {/;
+      $buf =~ s/ OBJECT IDENTIFIER .* ::= \{/ OBJECT IDENTIFIER ::= {/;
       $buf =~ s/".*"//;
       if ($buf =~ /"/) {
 	$quote = 1;
       }
 
-      if ($buf =~ / ([\w\-]+) OBJECT IDENTIFIER ::= {([^}]+)}/) {
+      if ($buf =~ / ([\w\-]+) OBJECT IDENTIFIER ::= \{([^}]+)}/) {
 	$var = $1;
 	$buf = $2;
 	undef $val;
