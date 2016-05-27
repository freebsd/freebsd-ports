--- src/ui.c.orig	2016-05-10 07:09:15 UTC
+++ src/ui.c
@@ -271,16 +271,9 @@ static void draw_settings_header(int UNU
     setfont(FONT_SELF_NAME);
     drawstr(MAIN_LEFT + SCALE(10), SCALE(10), UTOX_SETTINGS);
     #ifdef GIT_VERSION
-        int x = MAIN_LEFT + SCALE(10) + UTOX_STR_WIDTH(UTOX_SETTINGS) + SCALE(10);
+        int x = MAIN_LEFT + UTOX_SCALE(5 ) + UTOX_STR_WIDTH(UTOX_SETTINGS) + UTOX_SCALE(5 );
         setfont(FONT_TEXT);
-        drawtext(x, SCALE(10), (uint8_t*)GIT_VERSION, strlen(GIT_VERSION));
-        char version_string[64];
-        int count;
-        count = snprintf(version_string, 64, "Core v%u.%u.%u ToxAV v%u.%u.%u ToxES v%u.%u.%u",
-                                    tox_version_major(),   tox_version_minor(),   tox_version_patch(),
-                                    toxav_version_major(), toxav_version_minor(), toxav_version_patch(),
-                                    toxes_version_major(), toxes_version_minor(), toxes_version_patch());
-        drawtextwidth_right(w, textwidth((char_t*)version_string, count), SCALE(10), (uint8_t*)version_string, strlen(version_string));
+        drawtext(x, UTOX_SCALE(5), (uint8_t*)GIT_VERSION, strlen(GIT_VERSION));
     #endif
 }
 
