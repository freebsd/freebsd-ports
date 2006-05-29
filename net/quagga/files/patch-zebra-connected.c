--- zebra/connected.c.orig	Mon May 22 11:48:55 2006
+++ zebra/connected.c	Mon May 22 11:49:48 2006
@@ -60,8 +60,11 @@
       UNSET_FLAG (ifc->conf, ZEBRA_IFC_REAL);
     }
 
-  listnode_delete (ifc->ifp->connected, ifc);
-  connected_free (ifc);
+  if (!CHECK_FLAG (ifc->conf, ZEBRA_IFC_CONFIGURED))
+    {
+      listnode_delete (ifc->ifp->connected, ifc);
+      connected_free (ifc);
+    }
 }
 
 static void
@@ -225,7 +228,14 @@
 
   /* Check same connected route. */
   if ((current = connected_check (ifp, (struct prefix *) ifc->address)))
-    connected_withdraw (current); /* implicit withdraw - freebsd does this */
+    {
+      if (CHECK_FLAG(current->conf, ZEBRA_IFC_CONFIGURED))
+	{
+	  SET_FLAG(ifc->conf, ZEBRA_IFC_CONFIGURED);
+	  UNSET_FLAG(current->conf, ZEBRA_IFC_CONFIGURED);
+	}
+      connected_withdraw (current); /* implicit withdraw - freebsd does this */
+    }
   
   connected_announce (ifp, ifc);
 }
@@ -364,7 +374,14 @@
     ifc->label = XSTRDUP (MTYPE_CONNECTED_LABEL, label);
   
   if ((current = connected_check (ifp, (struct prefix *) ifc->address)))
-    connected_withdraw (current); /* implicit update of existing address */
+    {
+      if (CHECK_FLAG(current->conf, ZEBRA_IFC_CONFIGURED))
+	{
+	  SET_FLAG(ifc->conf, ZEBRA_IFC_CONFIGURED);
+	  UNSET_FLAG(current->conf, ZEBRA_IFC_CONFIGURED);
+	}
+      connected_withdraw (current); /* implicit update of existing address */
+    }
   
   connected_announce (ifp, ifc);
 }
