--- src/acl_manager.hpp.orig	2010-06-03 05:38:27.000000000 +0900
+++ src/acl_manager.hpp	2010-06-19 22:48:42.000000000 +0900
@@ -93,7 +93,7 @@
 };
 
 
-struct acl_entry : permissions_t
+struct acl_manager_entry : permissions_t
 {
 	int qualifier; // Group or user
 	string name; // Symbolic name of the qualifier
@@ -118,10 +118,10 @@
 		bool _there_is_mask;
 		permissions_t _mask_acl;
 
-		vector<acl_entry> _user_acl;
-		vector<acl_entry> _group_acl;
-		vector<acl_entry> _default_user_acl;
-		vector<acl_entry> _default_group_acl;
+		vector<acl_manager_entry> _user_acl;
+		vector<acl_manager_entry> _group_acl;
+		vector<acl_manager_entry> _default_user_acl;
+		vector<acl_manager_entry> _default_group_acl;
 
 		permissions_t _default_user; 
 		bool _there_is_default_user;
@@ -143,9 +143,9 @@
 		void get_acl_entries_default();
 		void create_textual_representation();
 		string permission_to_str(permissions_t& p);
-		string write_name(acl_entry& eacl);
-		void set_acl_generic(const string& nom, vector<acl_entry>& llistACL, const permissions_t& perms);
-		void remove_acl_generic(const string& nom, vector<acl_entry>& llistaACL);
+		string write_name(acl_manager_entry& eacl);
+		void set_acl_generic(const string& nom, vector<acl_manager_entry>& llistACL, const permissions_t& perms);
+		void remove_acl_generic(const string& nom, vector<acl_manager_entry>& llistaACL);
 
 		void commit_changes_to_file();
 		void calculate_access_mask();
@@ -160,7 +160,7 @@
 			public:
 				ACLEquivalence(const string& qualif)
 					: _qualifier(qualif) {}
-				bool operator ()(acl_entry& a)
+				bool operator ()(acl_manager_entry& a)
 				{
 					return (a.valid_name && (a.name == _qualifier));
 				}
@@ -203,10 +203,10 @@
 
 		void create_default_acl();
 
-		vector<acl_entry> get_acl_user() const { return _user_acl; }
-		vector<acl_entry> get_acl_group() const { return _group_acl; }
-		vector<acl_entry> get_acl_user_default() const { return _default_user_acl; }
-		vector<acl_entry> get_acl_group_default() const { return _default_group_acl; }
+		vector<acl_manager_entry> get_acl_user() const { return _user_acl; }
+		vector<acl_manager_entry> get_acl_group() const { return _group_acl; }
+		vector<acl_manager_entry> get_acl_user_default() const { return _default_user_acl; }
+		vector<acl_manager_entry> get_acl_group_default() const { return _default_group_acl; }
 		permissions_t get_mask() { return _mask_acl; }
 
 		permissions_t get_user() { return _owner_perms; }
