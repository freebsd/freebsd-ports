--- guile-gnome/gnorba-glue.c.orig	Sat Aug 31 14:05:01 2002
+++ guile-gnome/gnorba-glue.c	Sat Aug 31 14:05:06 2002
@@ -41,7 +41,7 @@
 };
 
 GtkTypeInfo sgtk_corba_orb_info_gtk = {
-  "CORBAORB", "sizeof (CORBA_ORB)", 0,
+  "CORBAORB", sizeof (CORBA_ORB), 0,
   (GtkClassInitFunc) NULL,
   (GtkObjectInitFunc) NULL,
   (GtkArgSetFunc) NULL,
@@ -57,7 +57,7 @@
 };
 
 GtkTypeInfo sgtk_corba_environment_info_gtk = {
-  "CORBAEnvironment", "sizeof (CORBA_Environment)", 0,
+  "CORBAEnvironment", sizeof (CORBA_Environment), 0,
   (GtkClassInitFunc) NULL,
   (GtkObjectInitFunc) NULL,
   (GtkArgSetFunc) NULL,
@@ -73,7 +73,7 @@
 };
 
 GtkTypeInfo sgtk_portable_server_poa_info_gtk = {
-  "PortableServerPOA", "sizeof (PortableServer_POA)", 0,
+  "PortableServerPOA", sizeof (PortableServer_POA), 0,
   (GtkClassInitFunc) NULL,
   (GtkObjectInitFunc) NULL,
   (GtkArgSetFunc) NULL,
@@ -89,7 +89,7 @@
 };
 
 GtkTypeInfo sgtk_portable_server_poamanager_info_gtk = {
-  "PortableServerPOAManager", "sizeof (PortableServer_POAManager)", 0,
+  "PortableServerPOAManager", sizeof (PortableServer_POAManager), 0,
   (GtkClassInitFunc) NULL,
   (GtkObjectInitFunc) NULL,
   (GtkArgSetFunc) NULL,
@@ -105,7 +105,7 @@
 };
 
 GtkTypeInfo sgtk_corba_object_info_gtk = {
-  "CORBAObject", "sizeof (CORBA_Object)", 0,
+  "CORBAObject", sizeof (CORBA_Object), 0,
   (GtkClassInitFunc) NULL,
   (GtkObjectInitFunc) NULL,
   (GtkArgSetFunc) NULL,
