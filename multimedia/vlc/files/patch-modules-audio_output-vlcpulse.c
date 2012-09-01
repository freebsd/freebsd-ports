--- modules/audio_output/vlcpulse.c.orig
+++ modules/audio_output/vlcpulse.c
@@ -107,7 +107,12 @@ pa_context *vlc_pa_connect (vlc_object_t
         //pa_proplist_sets (props, PA_PROP_APPLICATION_PROCESS_BINARY,
         //                  PACKAGE_NAME);
 
+#ifdef __FreeBSD__
+        /* sysconf (_SC_GETPW_R_SIZE_MAX) returns -1 on FreeBSD */
+        char buf[LINE_MAX + 1];
+#else
         char buf[sysconf (_SC_GETPW_R_SIZE_MAX)];
+#endif
         struct passwd pwbuf, *pw;
 
         if (getpwuid_r (getuid (), &pwbuf, buf, sizeof (buf), &pw) == 0
