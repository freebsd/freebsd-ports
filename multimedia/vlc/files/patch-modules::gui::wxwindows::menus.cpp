--- modules/gui/wxwindows/menus.cpp.orig	Mon Jun 30 15:22:03 2003
+++ modules/gui/wxwindows/menus.cpp	Mon Jun 30 15:24:40 2003
@@ -516,9 +516,8 @@
           menuitem =
               new wxMenuItemExt( menu, ++i_item_id,
                                  text_list.p_list->p_values[i].psz_string ?
-                                 wxU(text_list.p_list->p_values[i].psz_string):
-                                 wxString::Format(wxT("%d"),
-                                 val_list.p_list->p_values[i].i_int),
+                                 (wxString)wxU(text_list.p_list->p_values[i].psz_string):
+                                 (wxString)wxString::Format(wxT("%d"), val_list.p_list->p_values[i].i_int),
                                  wxT(""), wxITEM_RADIO, strdup(psz_var),
                                  p_object->i_object_id,
                                  val_list.p_list->p_values[i], i_type );
