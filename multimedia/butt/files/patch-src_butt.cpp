--- src/butt.cpp.orig	2026-08-26 23:50:14 UTC
+++ src/butt.cpp
@@ -561,7 +561,7 @@ int main(int argc, char *argv[])
                 return 1;
             }
             break;
-#if !defined(__APPLE__) && !defined(WIN32) && !defined(BUILD_CLIENT)
+#if !defined(__APPLE__) && !defined(WIN32) && !defined(BUILD_CLIENT) && defined(HAVE_JACK)
         case 'j':
             jack_client_name = (char *)malloc((strlen(optarg) + 1) * sizeof(char));
             strcpy(jack_client_name, optarg);
@@ -595,7 +595,7 @@ int main(int argc, char *argv[])
                      "-m\tSet streaming silence threshold (seconds)\n"
                      "-O\tSet recording signal threshold (seconds)\n"
                      "-o\tSet recording silence threshold (seconds)\n"
-#if !defined(__APPLE__) && !defined(WIN32)
+#if !defined(__APPLE__) && !defined(WIN32) && defined(HAVE_JACK)
                      "-j\tSet jack name\n"
 #endif
                      "-U\tConnect via UDP instead of TCP\n"
