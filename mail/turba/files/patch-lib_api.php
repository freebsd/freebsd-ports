--- lib/api.php.orig	Tue Dec 25 20:01:35 2001
+++ lib/api.php	Thu Jan 17 23:46:58 2002
@@ -90,7 +90,7 @@
 
     $driver = Turba_Source::factory($addressbook, $cfgSources[$addressbook]);
     $res = $driver->search(array('name' => $name, 'email' => $address), LASTNAME, TURBA_SEARCH_AND);
-    if (PEAR::isError($res) || count($res) > 0) {
+    if (PEAR::isError($res) || count($res->objects) > 0) {
         return PEAR::raiseError(_("This person is already in your addressbook."), HORDE_MESSAGE);
     }
 
