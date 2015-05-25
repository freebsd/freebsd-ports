--- ui/app_list/app_list_menu.cc.orig	2015-04-28 09:03:36.585517000 -0400
+++ ui/app_list/app_list_menu.cc	2015-04-28 09:04:02.340815000 -0400
@@ -32,7 +32,7 @@
                                users_[i].email.empty() ? users_[i].name
                                                        : users_[i].email,
                                0 /* group_id */);
-#elif defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#elif defined(OS_WIN) || ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS))
       menu_model_.AddItem(SELECT_PROFILE + i, users_[i].name);
       int menu_index = menu_model_.GetIndexOfCommandId(SELECT_PROFILE + i);
       menu_model_.SetSublabel(menu_index, users_[i].email);
