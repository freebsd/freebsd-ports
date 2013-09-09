--- modules/gui/ncurses.c.orig
+++ modules/gui/ncurses.c
@@ -880,6 +880,9 @@ static int DrawHelp(intf_thread_t *intf)
     H(_(" s                      Stop"));
     H(_(" <space>                Pause/Play"));
     H(_(" f                      Toggle Fullscreen"));
+    H(_(" c                      Cycle through audio tracks"));
+    H(_(" v                      Cycle through subtitles tracks"));
+    H(_(" b                      Cycle through video tracks"));
     H(_(" n, p                   Next/Previous playlist item"));
     H(_(" [, ]                   Next/Previous title"));
     H(_(" <, >                   Next/Previous chapter"));
@@ -1543,6 +1546,30 @@ static void InputNavigate(input_thread_t* p_input, const char *var)
         var_TriggerCallback(p_input, var);
 }
 
+static void CycleESTrack(intf_sys_t *sys, const char *var)
+{
+    input_thread_t *input = sys->p_input;
+
+    if (!input)
+        return;
+
+    vlc_value_t val;
+    if (var_Change(input, var, VLC_VAR_GETLIST, &val, NULL) < 0)
+        return;
+
+    vlc_list_t *list = val.p_list;
+    int64_t current = var_GetInteger(input, var);
+
+    int i;
+    for (i = 0; i < list->i_count; i++)
+        if (list->p_values[i].i_int == current)
+            break;
+
+    if (++i >= list->i_count)
+        i = 0;
+    var_SetInteger(input, var, list->p_values[i].i_int);
+}
+
 static void HandleCommonKey(intf_thread_t *intf, int key)
 {
     intf_sys_t *sys = intf->p_sys;
@@ -1611,6 +1638,10 @@ static void HandleCommonKey(intf_thread_t *intf, int key)
     case 'z': playlist_VolumeDown(p_playlist, 1, NULL); break;
     case 'm': playlist_MuteToggle(p_playlist); break;
 
+    case 'c': CycleESTrack(sys, "audio-es"); break;
+    case 'v': CycleESTrack(sys, "spu-es");   break;
+    case 'b': CycleESTrack(sys, "video-es"); break;
+
     case 0x0c:  /* ^l */
     case KEY_CLEAR:
         break;
