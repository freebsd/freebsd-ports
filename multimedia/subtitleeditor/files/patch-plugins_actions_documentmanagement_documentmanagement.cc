--- plugins/actions/documentmanagement/documentmanagement.cc.orig	2014-02-12 22:02:56 UTC
+++ plugins/actions/documentmanagement/documentmanagement.cc
@@ -177,9 +177,9 @@ public:
 
 		ui_id = ui->new_merge_id();
 
-		#define ADD_UI(name) ui->add_ui(ui_id, "/menubar/menu-file/"name, name, name);
-		#define ADD_OPEN_UI(name) ui->add_ui(ui_id, "/menubar/menu-file/menu-open/"name, name, name);
-		#define ADD_SAVE_UI(name) ui->add_ui(ui_id, "/menubar/menu-file/menu-save/"name, name, name);
+		#define ADD_UI(name) ui->add_ui(ui_id, "/menubar/menu-file/" name, name, name);
+		#define ADD_OPEN_UI(name) ui->add_ui(ui_id, "/menubar/menu-file/menu-open/" name, name, name);
+		#define ADD_SAVE_UI(name) ui->add_ui(ui_id, "/menubar/menu-file/menu-save/" name, name, name);
 
 		ADD_UI("new-document");
 		ADD_OPEN_UI("open-document");
