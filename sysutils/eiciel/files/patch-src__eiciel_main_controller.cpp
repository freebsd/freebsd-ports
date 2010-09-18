--- src/eiciel_main_controller.cpp.orig	2010-06-03 05:38:27.000000000 +0900
+++ src/eiciel_main_controller.cpp	2010-06-19 22:56:56.000000000 +0900
@@ -125,11 +125,11 @@
 		effective_permissions = _ACL_manager->get_mask();
 	}
 	
-	vector<acl_entry> vACL;
+	vector<acl_manager_entry> vACL;
 	_window->add_non_selectable(Glib::locale_to_utf8(_ACL_manager->get_owner_name()), perms.reading,
 			perms.writing, perms.execution, EK_USER);
 	vACL = _ACL_manager->get_acl_user();
-	for (vector<acl_entry>::iterator i = vACL.begin(); 
+	for (vector<acl_manager_entry>::iterator i = vACL.begin(); 
 			i != vACL.end(); i++)
 	{
 		_window->add_selectable(Glib::locale_to_utf8(i->name), i->reading, 
@@ -153,7 +153,7 @@
 		(!effective_permissions.execution && perms.execution);
 
 	vACL = _ACL_manager->get_acl_group();
-	for (vector<acl_entry>::iterator i = vACL.begin(); 
+	for (vector<acl_manager_entry>::iterator i = vACL.begin(); 
 			i != vACL.end(); i++)
 	{
 		_window->add_selectable(Glib::locale_to_utf8(i->name), i->reading, 
@@ -200,7 +200,7 @@
 		vACL = _ACL_manager->get_acl_user_default();
 
 		there_is_default_acl |= (vACL.size() > 0);
-		for (vector<acl_entry>::iterator i = vACL.begin(); 
+		for (vector<acl_manager_entry>::iterator i = vACL.begin(); 
 				i != vACL.end(); i++)
 		{
 			_window->add_selectable(Glib::locale_to_utf8(i->name), i->reading, 
@@ -231,7 +231,7 @@
 		vACL = _ACL_manager->get_acl_group_default();
 
 		there_is_default_acl |= (vACL.size() > 0);
-		for (vector<acl_entry>::iterator i = vACL.begin(); 
+		for (vector<acl_manager_entry>::iterator i = vACL.begin(); 
 				i != vACL.end(); i++)
 		{
 			_window->add_selectable(Glib::locale_to_utf8(i->name), i->reading, 
