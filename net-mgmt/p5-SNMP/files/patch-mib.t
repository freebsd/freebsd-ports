--- t/mib.t.orig	Tue Jan 11 07:21:08 2000
+++ t/mib.t	Fri Jan 12 10:25:44 2001
@@ -147,13 +147,13 @@
 ######################  15   #########################
 $res = $SNMP::MIB{atNetAddress}{nextNode};
 #print("res is --> $res\n");
-ok($res =~ /^HASH/);
+ok(ref $res eq "HASH");
 #print("\n");
 
 ########################  16   #########################
 $res = $SNMP::MIB{sysDescr}{children};
 #print("res is --> $res\n");
-ok($res =~ /^ARRAY/);
+ok(ref $res eq "ARRAY");
 #print("\n");
 ####################  17   #########################
  
