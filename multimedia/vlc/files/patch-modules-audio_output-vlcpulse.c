--- modules/audio_output/vlcpulse.c.orig
+++ modules/audio_output/vlcpulse.c
@@ -113,10 +113,12 @@ pa_context *vlc_pa_connect (vlc_object_t
             struct passwd pwbuf, *pw;
             char buf[len];
 
-            if (getpwuid_r (getuid (), &pwbuf, buf, sizeof (buf), &pw) == 0
-             && pw != NULL)
-                pa_proplist_sets (props, PA_PROP_APPLICATION_PROCESS_USER,
-                                  pw->pw_name);
+            if (getpwuid_r (getuid (), &pwbuf, buf, sizeof (buf), &pw) == 0) {
+                if (pw != NULL)
+                    pa_proplist_sets (props, PA_PROP_APPLICATION_PROCESS_USER,
+                                      pw->pw_name);
+                break;
+            }
         }
 
         for (size_t max = sysconf (_SC_HOST_NAME_MAX), len = max % 1024 + 1024;
@@ -124,9 +126,11 @@ pa_context *vlc_pa_connect (vlc_object_t
         {
             char hostname[len];
 
-            if (gethostname (hostname, sizeof (hostname)) == 0)
+            if (gethostname (hostname, sizeof (hostname)) == 0) {
                 pa_proplist_sets (props, PA_PROP_APPLICATION_PROCESS_HOST,
                                   hostname);
+                break;
+            }
         }
 
         const char *session = getenv ("XDG_SESSION_COOKIE");
