--- src/FLTK/fl_funcs.cpp.orig	2020-11-09 19:05:50.529619000 +0100
+++ src/FLTK/fl_funcs.cpp	2020-11-09 19:14:30.905597000 +0100
@@ -155,7 +155,7 @@
     fl_g->choice_cfg_app->add("VOX");
     fl_g->check_cfg_use_app->value(cfg.main.app_update);
     fl_g->choice_cfg_app->value(cfg.main.app_update_service);
-#elif __linux__ && HAVE_DBUS
+#elif (__linux__ || __FreeBSD__) && HAVE_DBUS
     fl_g->choice_cfg_app->add("Rhythmbox");
     fl_g->choice_cfg_app->add("Banshee");
     fl_g->choice_cfg_app->add("Clementine");
