--- src/ssl.c.orig	2014-10-17 14:50:34 UTC
+++ src/ssl.c
@@ -524,12 +524,14 @@ static int ssl_rand_load_file(const char
     if (file == NULL)
         file = RAND_file_name(buffer, sizeof(buffer));
     if (file) {
+#ifndef LIBRESSL_VERSION_NUMBER
         if (strncmp(file, "egd:", 4) == 0) {
             if ((n = RAND_egd(file + 4)) > 0)
                 return n;
             else
                 return -1;
         }
+#endif
         if ((n = RAND_load_file(file, -1)) > 0)
             return n;
     }
@@ -548,9 +550,11 @@ static int ssl_rand_save_file(const char
 
     if (file == NULL)
         file = RAND_file_name(buffer, sizeof(buffer));
+#ifndef LIBRESSL_VERSION_NUMBER
     else if ((n = RAND_egd(file)) > 0) {
         return 0;
     }
+#endif
     if (file == NULL || !RAND_write_file(file))
         return 0;
     else
@@ -680,8 +684,10 @@ TCN_IMPLEMENT_CALL(jint, SSL, initialize
                 && (ee = ssl_try_load_engine(J2S(engine))) == NULL)
                 err = APR_ENOTIMPL;
             else {
+#ifndef LIBRESSL_VERSION_NUMBER
                 if (strcmp(J2S(engine), "chil") == 0)
                     ENGINE_ctrl(ee, ENGINE_CTRL_CHIL_SET_FORKCHECK, 1, 0, 0);
+#endif
                 if (!ENGINE_set_default(ee, ENGINE_METHOD_ALL))
                     err = APR_ENOTIMPL;
             }
