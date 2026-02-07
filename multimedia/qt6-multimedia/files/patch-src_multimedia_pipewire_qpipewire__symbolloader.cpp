Adapt to local symbols from multimedia/pipewire

PR: 284719

--- src/multimedia/pipewire/qpipewire_symbolloader.cpp.orig	2025-08-15 19:16:13 UTC
+++ src/multimedia/pipewire/qpipewire_symbolloader.cpp
@@ -17,8 +17,8 @@ BEGIN_INIT_FUNCS("pipewire-" PW_API_VERSION, "0")
 //BEGIN_INIT_FUNCS("pipewire-0.3", "0")
 BEGIN_INIT_FUNCS("pipewire-" PW_API_VERSION, "0")
 
-INIT_FUNC(pw_init);
-INIT_FUNC(pw_deinit);
+INIT_FUNC(pipewire_init);
+INIT_FUNC(pipewire_deinit);
 INIT_OPT_FUNC(pw_check_library_version);
 INIT_FUNC(pw_context_new);
 INIT_FUNC(pw_context_destroy);
@@ -52,8 +52,8 @@ END_INIT_FUNCS()
 
 END_INIT_FUNCS()
 
-DEFINE_FUNC(pw_init, 2);
-DEFINE_FUNC(pw_deinit, 0);
+DEFINE_FUNC(pipewire_init, 2);
+DEFINE_FUNC(pipewire_deinit, 0);
 DEFINE_FUNC(pw_check_library_version, 3);
 DEFINE_FUNC(pw_context_new, 3);
 DEFINE_FUNC(pw_context_destroy, 1);
