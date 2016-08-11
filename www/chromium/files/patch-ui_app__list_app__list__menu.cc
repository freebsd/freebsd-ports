--- ui/app_list/app_list_menu.cc.orig	2016-03-25 13:05:03 UTC
+++ ui/app_list/app_list_menu.cc
@@ -35,7 +35,7 @@ void AppListMenu::InitMenu() {
                                users_[i].email.empty() ? users_[i].name
                                                        : users_[i].email,
                                0 /* group_id */);
-#elif defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#elif defined(OS_WIN) || ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS))
       menu_model_.AddItem(SELECT_PROFILE + i, users_[i].name);
       int menu_index = menu_model_.GetIndexOfCommandId(SELECT_PROFILE + i);
       menu_model_.SetSublabel(menu_index, users_[i].email);
