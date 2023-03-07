--- msg.c.orig	2023-03-07 22:52:52 UTC
+++ msg.c
@@ -194,11 +194,7 @@ parse_preface(const char *template) {
         fmt[p++] = *template;
         if (state == percent) {
             if (*template == 's')
-#if defined(_POSIX_SOURCE)
                 p += sprintf(fmt + p - 2, "%d", msg_severity) - 2;
-#else
-                p = strchr(sprintf(fmt + p - 2, "%d", msg_severity), 0) - fmt;
-#endif
             state = normal;
         } else if (*template == '%')
             state = percent;
