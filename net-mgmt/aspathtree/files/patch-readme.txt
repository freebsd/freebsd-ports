--- readme.txt.orig	Thu Apr 17 15:58:12 2003
+++ readme.txt	Sun Apr 27 01:53:51 2003
@@ -61,7 +61,7 @@
 without problems on any Unix platform (Linux, etc.) with
 Perl (version equal or greater than 5.0) installed.
 
-The IPv6 BGP tables of external routers are obtained using rsh
+The IPv6 BGP tables of external routers are obtained using rsh or telnet
 commands. The current release works with cisco routers, zebra routers
 and juniper routers running IPv6 capable software versions.
 
@@ -128,10 +128,16 @@
 
 CISCO
 -----
-The cisco router must be configured to accept rsh commands from the
-workstation which is running the ASpath-tree scripts. The
-administrator of the cisco router must perform the following
-configurations:
+The cisco router must be configured to accept rsh commands or telnet
+access from the workstation which is running the ASpath-tree
+scripts. The administrator of the cisco router must perform the
+following configurations:
+
+Option 1: rsh collection
+------------------------
+The router must be configured to accept rsh commands coming from the
+remote workstation which is running the ASpath-tree scripts in the
+following way:
 
   ip rcmd remote-host <router-username> <remote-ip-address> <remote-
   username>
@@ -162,9 +168,28 @@
 scripts to collect the routing information available on the cisco
 router.
 
+Option 2: telnet collection
+---------------------------
+The router must be configured to accept telnet commands coming from the
+remote workstation which is running the ASpath-tree scripts.
+
+<router-username> is the name of the telnet user enabled to show the bgp
+table on the cisco router.
+
+<router-username-password> is the corresponding password of the telnet user
+enabled to show the bgp table on the cisco router.
+
+Consult the Cisco documentations, how to configure such a settings.
+
+If you configure ROUTERUSERPWD then the telnet option automatically selected.
+
+
 JUNIPER
 -------
 
+Option 1: rsh collection
+------------------------
+
 The juniper router must be configured to accept rsh commands from the
 workstation which is running the ASpath-tree scripts. In the case of
 juniper, you have first to enable the rsh service on the router, then
@@ -198,6 +223,13 @@
 This is exactly the rsh command used by the ASpath-tree scripts to
 collect the routing information available on the juniper router.
 
+Option 2: telnet collection
+---------------------------
+
+configure an user <router-username> with password <router-password on
+the Juniper router with view permisssion. Consult your Juniper
+documentation about that.
+
 ZEBRA
 -----
 To use ASpath-tree with zebra routers, the "vtysh" CLI emulator must
@@ -267,7 +299,12 @@
              router have IPv6 capable rsh implementations.
 
 ROUTERUSER   is the username on the router that you have to use to
-             run remote rsh commands.
+             run remote rsh commands or telnet.
+
+ROUTERUSERPASS
+             is an optional parameter to use for telnet collection. If you
+             configure this parameter telnet mode will be used automatically.
+             DO NOT SPECIFY this parameter if you use RSH collection.
 
 HTMLDIR      is the full path to the directory where the generated
              html files have to be placed. If you do not specify this
@@ -794,6 +831,9 @@
         Raffaele D'Albenzio, Ivano Guardini and Paolo Fasano
         <ipv6@tilab.com>
         ----------------------------------------------------
+	Telnet modul addition
+        Janos Mohacsi <mohacsi@niif.hu> - 6NET project
+	----------------------------------------------------
 
 #### ASpath-tree v.4.2 - Released on Thu APR 17 2003, h.16:58:12
 #### File: readme.txt Last modified on Thu APR 17 2003, h.16:45:39
