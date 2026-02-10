--- src/3rdparty/chromium/components/sessions/core/session_service_commands.cc.orig	2025-04-23 16:00:55 UTC
+++ src/3rdparty/chromium/components/sessions/core/session_service_commands.cc
@@ -164,8 +164,8 @@ static_assert(ui::SHOW_STATE_END ==
 // Assert to ensure PersistedWindowShowState is updated if ui::WindowShowState
 // is changed.
 static_assert(ui::SHOW_STATE_END ==
-                  (static_cast<ui::WindowShowState>(PERSISTED_SHOW_STATE_END) -
-                   2),
+                  static_cast<ui::WindowShowState>(PERSISTED_SHOW_STATE_END -
+                                                   2),
               "SHOW_STATE_END must equal PERSISTED_SHOW_STATE_END minus the "
               "deprecated entries");
 // Returns the show state to store to disk based |state|.
