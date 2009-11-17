--- ./modules/control/globalhotkeys/xcb.c.orig	2009-05-10 19:03:55.000000000 -0400
+++ ./modules/control/globalhotkeys/xcb.c	2009-11-17 13:39:36.000000000 -0500
@@ -28,6 +28,7 @@
 #include <vlc_interface.h>
 #include <vlc_keys.h>
 #include <ctype.h>
+#include <errno.h>
 
 #include <xcb/xcb.h>
 #include <xcb/xcb_keysyms.h>
@@ -56,7 +57,11 @@
 
 typedef struct
 {
+#ifdef XCB_KEYSYM_OLD_API /* as seen in Debian Lenny */
     xcb_keycode_t i_x11;
+#else
+    xcb_keycode_t *p_keys;
+#endif
     unsigned      i_modifier;
     int           i_action;
 } hotkey_mapping_t;
@@ -96,7 +101,7 @@
     p_sys->p_connection = xcb_connect( psz_display, &i_screen_default );
     free( psz_display );
 
-    if( !p_sys->p_connection )
+    if( xcb_connection_has_error( p_sys->p_connection ) )
         goto error;
 
     /* Get the root windows of the default screen */
@@ -125,6 +130,10 @@
     if( vlc_clone( &p_sys->thread, Thread, p_intf, VLC_THREAD_PRIORITY_LOW ) )
     {
         Unregister( p_intf );
+#ifndef XCB_KEYSYM_OLD_API /* as seen in Debian Lenny */
+        if( p_sys->p_map )
+            free( p_sys->p_map->p_keys );
+#endif
         free( p_sys->p_map );
         goto error;
     }
@@ -133,8 +142,7 @@
 error:
     if( p_sys->p_symbols )
         xcb_key_symbols_free( p_sys->p_symbols );
-    if( p_sys->p_connection )
-        xcb_disconnect( p_sys->p_connection );
+    xcb_disconnect( p_sys->p_connection );
     free( p_sys );
     return VLC_EGENERIC;
 }
@@ -151,6 +159,10 @@
     vlc_join( p_sys->thread, NULL );
 
     Unregister( p_intf );
+#ifndef XCB_KEYSYM_OLD_API /* as seen in Debian Lenny */
+    if( p_sys->p_map )
+        free( p_sys->p_map->p_keys );
+#endif
     free( p_sys->p_map );
 
     xcb_key_symbols_free( p_sys->p_symbols );
@@ -164,16 +176,43 @@
 static unsigned GetModifier( xcb_connection_t *p_connection, xcb_key_symbols_t *p_symbols, xcb_keysym_t sym )
 {
     static const unsigned pi_mask[8] = {
-        XCB_MOD_MASK_SHIFT, XCB_MOD_MASK_LOCK, XCB_MOD_MASK_CONTROL, XCB_MOD_MASK_1,
-        XCB_MOD_MASK_2, XCB_MOD_MASK_3, XCB_MOD_MASK_4, XCB_MOD_MASK_5
+        XCB_MOD_MASK_SHIFT, XCB_MOD_MASK_LOCK, XCB_MOD_MASK_CONTROL,
+        XCB_MOD_MASK_1, XCB_MOD_MASK_2, XCB_MOD_MASK_3,
+        XCB_MOD_MASK_4, XCB_MOD_MASK_5
     };
 
+    if( sym == 0 )
+        return 0; /* no modifier */
+
+#ifdef XCB_KEYSYM_OLD_API /* as seen in Debian Lenny */
     const xcb_keycode_t key = xcb_key_symbols_get_keycode( p_symbols, sym );
     if( key == 0 )
         return 0;
+#else
+    const xcb_keycode_t *p_keys = xcb_key_symbols_get_keycode( p_symbols, sym );
+    if( !p_keys )
+        return 0;
 
-    xcb_get_modifier_mapping_cookie_t r = xcb_get_modifier_mapping( p_connection );
-    xcb_get_modifier_mapping_reply_t *p_map = xcb_get_modifier_mapping_reply( p_connection, r, NULL );
+    int i = 0;
+    bool no_modifier = true;
+    while( p_keys[i] != XCB_NO_SYMBOL )
+    {
+        if( p_keys[i] != 0 )
+        {
+            no_modifier = false;
+            break;
+        }
+        i++;
+    }
+
+    if( no_modifier )
+        return 0;
+#endif
+
+    xcb_get_modifier_mapping_cookie_t r =
+            xcb_get_modifier_mapping( p_connection );
+    xcb_get_modifier_mapping_reply_t *p_map =
+            xcb_get_modifier_mapping_reply( p_connection, r, NULL );
     if( !p_map )
         return 0;
 
@@ -181,20 +220,30 @@
     if( !p_keycode )
         return 0;
 
-    unsigned i_mask = 0;
     for( int i = 0; i < 8; i++ )
-    {
         for( int j = 0; j < p_map->keycodes_per_modifier; j++ )
-        {
+#ifdef XCB_KEYSYM_OLD_API /* as seen in Debian Lenny */
             if( p_keycode[i * p_map->keycodes_per_modifier + j] == key )
-                i_mask = pi_mask[i];
-        }
-    }
+            {
+                free( p_map );
+                return pi_mask[i];
+            }
+#else
+            for( int k = 0; p_keys[k] != XCB_NO_SYMBOL; k++ )
+                if( p_keycode[i*p_map->keycodes_per_modifier + j] == p_keys[k])
+                {
+                    free( p_map );
+                    return pi_mask[i];
+                }
+#endif
 
     free( p_map ); // FIXME to check
-    return i_mask;
+    return 0;
 }
-static unsigned GetX11Modifier( xcb_connection_t *p_connection, xcb_key_symbols_t *p_symbols, unsigned i_vlc )
+
+
+static unsigned GetX11Modifier( xcb_connection_t *p_connection,
+        xcb_key_symbols_t *p_symbols, unsigned i_vlc )
 {
     unsigned i_mask = 0;
 
@@ -225,7 +274,6 @@
 
     { XK_Return, KEY_ENTER },
     { XK_KP_Enter, KEY_ENTER },
-    { XK_space, KEY_SPACE },
     { XK_Escape, KEY_ESC },
 
     { XK_Menu, KEY_MENU },
@@ -253,16 +301,16 @@
 };
 static xcb_keysym_t GetX11Key( unsigned i_vlc )
 {
+    /* X11 and VLC use ASCII for printable ASCII characters */
+    if( i_vlc >= 32 && i_vlc <= 127 )
+        return i_vlc;
+
     for( int i = 0; x11keys_to_vlckeys[i].i_vlc != 0; i++ )
     {
         if( x11keys_to_vlckeys[i].i_vlc == i_vlc )
             return x11keys_to_vlckeys[i].i_x11;
     }
 
-    /* Copied from xcb, it seems that xcb use ascii code for ascii characters */
-    if( isascii( i_vlc ) )
-        return i_vlc;
-
     return XK_VoidSymbol;
 }
 
@@ -281,7 +329,7 @@
     p_sys->p_map = NULL;
 
     /* Registering of Hotkeys */
-    for( struct hotkey *p_hotkey = p_intf->p_libvlc->p_hotkeys;
+    for( const struct hotkey *p_hotkey = p_intf->p_libvlc->p_hotkeys;
             p_hotkey->psz_action != NULL;
             p_hotkey++ )
     {
@@ -291,23 +339,34 @@
 
         const int i_vlc_action = p_hotkey->i_action;
         const int i_vlc_key = config_GetInt( p_intf, psz_hotkey );
-
         free( psz_hotkey );
 
         if( !i_vlc_key )
             continue;
+#ifdef XCB_KEYSYM_OLD_API /* as seen in Debian Lenny */
+        const xcb_keycode_t key = xcb_key_symbols_get_keycode(
+                p_sys->p_symbols, GetX11Key( i_vlc_key & ~KEY_MODIFIER ) );
+#else
+        xcb_keycode_t *p_keys = xcb_key_symbols_get_keycode(
+                p_sys->p_symbols, GetX11Key( i_vlc_key & ~KEY_MODIFIER ) );
+        if( !p_keys )
+            continue;
+#endif
+        const unsigned i_modifier = GetX11Modifier( p_sys->p_connection,
+                p_sys->p_symbols, i_vlc_key & KEY_MODIFIER );
 
-        const xcb_keycode_t key = xcb_key_symbols_get_keycode( p_sys->p_symbols, GetX11Key( i_vlc_key & ~KEY_MODIFIER ) );
-        const unsigned i_modifier = GetX11Modifier( p_sys->p_connection, p_sys->p_symbols, i_vlc_key & KEY_MODIFIER );
-
-        for( int j = 0; j < sizeof(p_x11_modifier_ignored)/sizeof(*p_x11_modifier_ignored); j++ )
+        const size_t max = sizeof(p_x11_modifier_ignored) /
+                sizeof(*p_x11_modifier_ignored);
+        for( unsigned int i = 0; i < max; i++ )
         {
-            const unsigned i_ignored = GetModifier( p_sys->p_connection, p_sys->p_symbols, p_x11_modifier_ignored[j] );
-            if( j != 0 && i_ignored == 0x00)
+            const unsigned i_ignored = GetModifier( p_sys->p_connection,
+                    p_sys->p_symbols, p_x11_modifier_ignored[i] );
+            if( i != 0 && i_ignored == 0)
                 continue;
 
             hotkey_mapping_t *p_map_old = p_sys->p_map;
-            p_sys->p_map = realloc( p_sys->p_map, sizeof(*p_sys->p_map) * (p_sys->i_map+1) );
+            p_sys->p_map = realloc( p_sys->p_map,
+                    sizeof(*p_sys->p_map) * (p_sys->i_map+1) );
             if( !p_sys->p_map )
             {
                 p_sys->p_map = p_map_old;
@@ -315,7 +374,11 @@
             }
             hotkey_mapping_t *p_map = &p_sys->p_map[p_sys->i_map++];
 
+#ifdef XCB_KEYSYM_OLD_API /* as seen in Debian Lenny */
             p_map->i_x11 = key;
+#else
+            p_map->p_keys = p_keys;
+#endif
             p_map->i_modifier = i_modifier|i_ignored;
             p_map->i_action = i_vlc_action;
         }
@@ -329,9 +392,18 @@
     for( int i = 0; i < p_sys->i_map; i++ )
     {
         const hotkey_mapping_t *p_map = &p_sys->p_map[i];
+#ifdef XCB_KEYSYM_OLD_API /* as seen in Debian Lenny */
         xcb_grab_key( p_sys->p_connection, true, p_sys->root,
                       p_map->i_modifier, p_map->i_x11,
                       XCB_GRAB_MODE_ASYNC, XCB_GRAB_MODE_ASYNC );
+#else
+        for( int j = 0; p_map->p_keys[j] != XCB_NO_SYMBOL; j++ )
+        {
+            xcb_grab_key( p_sys->p_connection, true, p_sys->root,
+                          p_map->i_modifier, p_map->p_keys[j],
+                          XCB_GRAB_MODE_ASYNC, XCB_GRAB_MODE_ASYNC );
+        }
+#endif
     }
 }
 static void Unregister( intf_thread_t *p_intf )
@@ -341,7 +413,14 @@
     for( int i = 0; i < p_sys->i_map; i++ )
     {
         const hotkey_mapping_t *p_map = &p_sys->p_map[i];
-        xcb_ungrab_key( p_sys->p_connection, p_map->i_x11, p_sys->root, p_map->i_modifier );
+#ifdef XCB_KEYSYM_OLD_API /* as seen in Debian Lenny */
+        xcb_ungrab_key( p_sys->p_connection, p_map->i_x11, p_sys->root,
+                p_map->i_modifier );
+#else
+        for( int j = 0; p_map->p_keys[j] != XCB_NO_SYMBOL; j++ )
+            xcb_ungrab_key( p_sys->p_connection, p_map->p_keys[j], p_sys->root,
+                    p_map->i_modifier );
+#endif
     }
 }
 
@@ -387,12 +466,28 @@
             {
                 hotkey_mapping_t *p_map = &p_sys->p_map[i];
 
+#ifdef XCB_KEYSYM_OLD_API /* as seen in Debian Lenny */
                 if( p_map->i_x11 == e->detail &&
                     p_map->i_modifier == e->state )
                 {
-                    var_SetInteger( p_intf->p_libvlc, "key-action", p_map->i_action );
+                    var_SetInteger( p_intf->p_libvlc, "key-action",
+                            p_map->i_action );
                     break;
                 }
+#else
+            bool loop_break = false;
+            for( int j = 0; p_map->p_keys[j] != XCB_NO_SYMBOL; j++ )
+                if( p_map->p_keys[j] == e->detail &&
+                    p_map->i_modifier == e->state )
+                {
+                    var_SetInteger( p_intf->p_libvlc, "key-action",
+                            p_map->i_action );
+                    loop_break = true;
+                    break;
+                }
+            if( loop_break )
+                break;
+#endif
             }
             free( p_event );
         }
