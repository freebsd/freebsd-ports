--- ./plugins/actions/documentsnavigation/documentsnavigation.cc.orig	2011-06-08 19:15:03.000000000 +0200
+++ ./plugins/actions/documentsnavigation/documentsnavigation.cc	2011-07-26 10:12:07.000000000 +0200
@@ -54,22 +54,22 @@
 
 		action_group->add(
 				Gtk::Action::create("documentsnavigation-first-document", Gtk::Stock::GOTO_FIRST, _("_First Document")),
-					sigc::bind(
+					sigc::bind<int>(
 						sigc::mem_fun(*this, &DocumentsNavigationPlugin::on_select_document), FIRST));
 
 		action_group->add(
 				Gtk::Action::create("documentsnavigation-last-document", Gtk::Stock::GOTO_LAST,  _("_Last Document")),
-					sigc::bind(
+					sigc::bind<int>(
 						sigc::mem_fun(*this, &DocumentsNavigationPlugin::on_select_document), LAST));
 
 		action_group->add(
 				Gtk::Action::create("documentsnavigation-previous-document", Gtk::Stock::GO_BACK, _("_Previous Document")),
-					sigc::bind(
+					sigc::bind<int>(
 						sigc::mem_fun(*this, &DocumentsNavigationPlugin::on_select_document), PREVIOUS));
 
 		action_group->add(
 				Gtk::Action::create("documentsnavigation-next-document", Gtk::Stock::GO_FORWARD, _("_Next Document")),
-					sigc::bind(
+					sigc::bind<int>(
 						sigc::mem_fun(*this, &DocumentsNavigationPlugin::on_select_document), NEXT));
 
 		// ui
