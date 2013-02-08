--- mozilla/content/media/nsAudioStream.cpp~
+++ mozilla/content/media/nsAudioStream.cpp
@@ -298,7 +298,7 @@ static int PrefChanged(const char* aPref, void* aClosure)
       gVolumeScale = NS_MAX<double>(0, PR_strtod(utf8.get(), nullptr));
     }
   } else if (strcmp(aPref, PREF_USE_CUBEB) == 0) {
-#ifdef MOZ_WIDGET_GONK
+#if defined(MOZ_WIDGET_GONK) || defined(__FreeBSD__) && __FreeBSD_version < 800097
     bool value = Preferences::GetBool(aPref, false);
 #else
     bool value = Preferences::GetBool(aPref, true);
