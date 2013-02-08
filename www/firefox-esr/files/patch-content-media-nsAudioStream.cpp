--- content/media/nsAudioStream.cpp~
+++ content/media/nsAudioStream.cpp
@@ -298,7 +298,11 @@ static int PrefChanged(const char* aPref
       gVolumeScale = NS_MAX<double>(0, PR_strtod(utf8.get(), nsnull));
     }
   } else if (strcmp(aPref, PREF_USE_CUBEB) == 0) {
+#if defined(__FreeBSD__) && __FreeBSD_version < 800097
+    bool value = Preferences::GetBool(aPref, false);
+#else
     bool value = Preferences::GetBool(aPref, true);
+#endif
     mozilla::MutexAutoLock lock(*gAudioPrefsLock);
     gUseCubeb = value;
   } else if (strcmp(aPref, PREF_CUBEB_LATENCY) == 0) {
