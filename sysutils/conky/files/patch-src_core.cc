--- src/core.cc.orig	2019-08-12 21:53:54 UTC
+++ src/core.cc
@@ -1077,7 +1077,7 @@ struct text_object *construct_text_object(char *s, con
       obj->data.s = STRNDUP_ARG;
   obj->callbacks.iftest = &if_existing_iftest;
   obj->callbacks.free = &gen_free_opaque;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
   END OBJ_IF_ARG(if_mounted, 0, "if_mounted needs an argument") obj->data.s =
       STRNDUP_ARG;
   obj->callbacks.iftest = &check_mount;
