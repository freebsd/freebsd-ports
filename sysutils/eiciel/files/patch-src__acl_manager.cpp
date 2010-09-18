--- src/acl_manager.cpp.orig	2010-06-03 05:38:27.000000000 +0900
+++ src/acl_manager.cpp	2010-06-19 22:52:10.000000000 +0900
@@ -111,7 +111,7 @@
 		{
 			// A user|group entry
 			// Gather the permissions
-			acl_entry new_acl;
+			acl_manager_entry new_acl;
 			new_acl.reading = ACL_GET_PERM(permission_set, ACL_READ);
 			new_acl.writing = ACL_GET_PERM(permission_set, ACL_WRITE);
 			new_acl.execution = ACL_GET_PERM(permission_set, ACL_EXECUTE);
@@ -225,7 +225,7 @@
 		{
 			// An entry of type user/group
             // get all permissions
-			acl_entry new_acl;
+			acl_manager_entry new_acl;
 			new_acl.reading = ACL_GET_PERM(permission_set, ACL_READ);
 			new_acl.writing = ACL_GET_PERM(permission_set, ACL_WRITE);
 			new_acl.execution = ACL_GET_PERM(permission_set, ACL_EXECUTE);
@@ -317,14 +317,14 @@
 	_text_acl_access.clear();
 
 	_text_acl_access += "u::" + permission_to_str(_owner_perms) + "\n";
-	for (vector<acl_entry>::iterator i = _user_acl.begin();
+	for (vector<acl_manager_entry>::iterator i = _user_acl.begin();
 			i != _user_acl.end(); i++)
 	{
 		_text_acl_access += "u:" + write_name(*i) + ":" + permission_to_str(*i) + "\n";
 	}
 	
 	_text_acl_access += "g::" + permission_to_str(_group_perms) + "\n";
-	for (vector<acl_entry>::iterator i = _group_acl.begin();
+	for (vector<acl_manager_entry>::iterator i = _group_acl.begin();
 			i != _group_acl.end(); i++)
 	{
 		_text_acl_access += "g:" + write_name(*i) + ":" + permission_to_str(*i) + "\n";
@@ -352,12 +352,12 @@
 			_text_acl_default += "o::" + permission_to_str(_default_others) + "\n";
 		}
 
-		for (vector<acl_entry>::iterator i = _default_user_acl.begin();
+		for (vector<acl_manager_entry>::iterator i = _default_user_acl.begin();
 				i != _default_user_acl.end(); i++)
 		{
 			_text_acl_default += "u:" + write_name(*i) + ":" + permission_to_str(*i) + "\n";
 		}
-		for (vector<acl_entry>::iterator i = _default_group_acl.begin();
+		for (vector<acl_manager_entry>::iterator i = _default_group_acl.begin();
 				i != _default_group_acl.end(); i++)
 		{
 			_text_acl_default += "g:" + write_name(*i) + ":" + permission_to_str(*i) + "\n";
@@ -370,7 +370,7 @@
 	}
 }
 
-string ACLManager::write_name(acl_entry& eacl)
+string ACLManager::write_name(acl_manager_entry& eacl)
 {
 	if (eacl.valid_name)
 	{
@@ -477,11 +477,11 @@
 	}
 }
 
-void ACLManager::set_acl_generic(const string& name, vector<acl_entry>& acl_list, 
+void ACLManager::set_acl_generic(const string& name, vector<acl_manager_entry>& acl_list, 
         const permissions_t& perms)
 {
 	ACLEquivalence equiv_acl(name);
-	vector<acl_entry>::iterator i = find_if(acl_list.begin(), acl_list.end(), equiv_acl);
+	vector<acl_manager_entry>::iterator i = find_if(acl_list.begin(), acl_list.end(), equiv_acl);
 	if (i != acl_list.end()) // If already there, update
 	{
 		i->reading = perms.reading;
@@ -490,7 +490,7 @@
 	}
 	else // If not there, create
 	{
-		acl_entry eacl;
+		acl_manager_entry eacl;
 		eacl.valid_name = true;
 		eacl.name = name;
 		eacl.reading = perms.reading;
@@ -524,7 +524,7 @@
 	update_changes_acl_default();
 }
 
-void ACLManager::remove_acl_generic(const string& name, vector<acl_entry>& acl_list)
+void ACLManager::remove_acl_generic(const string& name, vector<acl_manager_entry>& acl_list)
 {
 	ACLEquivalence equiv_acl(name);
 	acl_list.erase(remove_if(acl_list.begin(), acl_list.end(), equiv_acl), acl_list.end());
