Adapt to local symbols from multimedia/pipewire

PR: 284719

--- src/multimedia/pipewire/qpipewire_symbolloader.cpp.orig	2025-01-24 11:58:42 UTC
+++ src/multimedia/pipewire/qpipewire_symbolloader.cpp
@@ -8,8 +8,8 @@ BEGIN_INIT_FUNCS("pipewire-" PW_API_VERSION, "0")
 //BEGIN_INIT_FUNCS("pipewire-0.3", "0")
 BEGIN_INIT_FUNCS("pipewire-" PW_API_VERSION, "0")
 
-INIT_FUNC(pw_init);
-INIT_FUNC(pw_deinit);
+INIT_FUNC(pipewire_init);
+INIT_FUNC(pipewire_deinit);
 INIT_FUNC(pw_thread_loop_new);
 INIT_FUNC(pw_thread_loop_get_loop);
 INIT_FUNC(pw_context_new);
@@ -37,8 +37,8 @@ END_INIT_FUNCS()
 
 END_INIT_FUNCS()
 
-DEFINE_FUNC(pw_init, 2);
-DEFINE_FUNC(pw_deinit, 0);
+DEFINE_FUNC(pipewire_init, 2);
+DEFINE_FUNC(pipewire_deinit, 0);
 DEFINE_FUNC(pw_thread_loop_new, 2);
 DEFINE_FUNC(pw_thread_loop_get_loop, 1);
 DEFINE_FUNC(pw_context_new, 3);
