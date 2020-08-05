--- src/FLTK/fl_funcs.cpp.orig	2020-07-26 17:47:54 UTC
+++ src/FLTK/fl_funcs.cpp
@@ -147,7 +147,7 @@ void fill_cfg_widgets(void)
     fl_g->choice_cfg_app->add("VOX");
     fl_g->check_cfg_use_app->value(cfg.main.app_update);
     fl_g->choice_cfg_app->value(cfg.main.app_update_service);
-#elif __linux__ && HAVE_DBUS
+#elif (__linux__ || __FreeBSD__) && HAVE_DBUS
     fl_g->choice_cfg_app->add("Rhythmbox");
     fl_g->choice_cfg_app->add("Banshee");
     fl_g->choice_cfg_app->add("Clementine");
