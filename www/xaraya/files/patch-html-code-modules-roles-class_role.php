--- html/code/modules/roles/class/role.php.orig	2014-02-14 14:13:30.000000000 +0100
+++ html/code/modules/roles/class/role.php	2014-02-14 14:13:38.000000000 +0100
@@ -394,7 +394,7 @@
             return xarVarGetCached($cacheKey,$this->properties['id']->value);
         }
         // We'll have to get it.
-        xarLogMessage("ROLE: getting privileges for id: $this->properties['id']->value");
+        xarLogMessage("ROLE: getting privileges for id: " . $this->properties['id']->value);
         // TODO: propagate the use of 'All'=null for realms through the API instead of the flip-flopping
         $xartable = xarDB::getTables();
         $query = "SELECT  p.id, p.name, r.name, p.module_id, m.name,
