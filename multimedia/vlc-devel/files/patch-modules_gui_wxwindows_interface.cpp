--- modules/gui/wxwindows/interface.cpp.orig	Mon May 16 13:32:57 2005
+++ modules/gui/wxwindows/interface.cpp	Mon May 16 13:35:29 2005
@@ -94,6 +94,7 @@
 
     wxVolCtrl *gauge;
     int i_y_offset;
+    vlc_bool_t b_mute;
     intf_thread_t *p_intf;
 };
 
@@ -240,6 +241,12 @@
     /* Create a dummy widget that can get the keyboard focus */
     wxWindow *p_dummy = new wxWindow( this, 0, wxDefaultPosition,
                                       wxSize(0,0) );
+#if defined(__WXGTK20__) && wxCHECK_VERSION(2,5,6)
+    /* As ugly as your butt! Please remove when wxWidgets 2.6 fixed their
+     * Accelerators bug. */
+    p_dummy->m_imData = 0;
+    m_imData = 0;
+#endif
     p_dummy->SetFocus();
     frame_sizer->Add( p_dummy, 0, 0 );
 
@@ -351,7 +358,6 @@
 {
     /* Misc updates */
     ((VLCVolCtrl *)volctrl)->UpdateVolume();
-    
 }
 
 void Interface::OnControlEvent( wxCommandEvent& event )
@@ -498,7 +504,7 @@
     }
 
     wxToolBarToolBase *p_tool = toolbar->AddTool( PlayStream_Event, wxT(""),
-                      wxBitmap( play_xpm ), wxU(_(HELP_PLAY)) );
+                      wxBitmap( play_xpm ), wxU(_(HELP_PLAY)), wxITEM_CHECK );
     p_tool->SetClientData( p_tool );
 
     if (!minimal)
@@ -692,27 +698,23 @@
 
         //prevent continuous layout
         if( slider_frame->IsShown() ) return;
-
-        slider_frame->Show();
-        frame_sizer->Show( slider_frame );
     }
     else
     {
         //prevent continuous layout
         if( !slider_frame->IsShown() ) return;
-
-        slider_frame->Hide();
-        frame_sizer->Hide( slider_frame );
     }
 
+    if( layout && p_intf->p_sys->b_video_autosize )
+        UpdateVideoWindow( p_intf, video_window );
+
+    slider_frame->Show( show );
+    frame_sizer->Show( slider_frame, show );
+
     if( layout )
     {
         frame_sizer->Layout();
-        if( p_intf->p_sys->b_video_autosize )
-        {
-            UpdateVideoWindow( p_intf, video_window );
-            frame_sizer->Fit( this );
-        }
+        if( p_intf->p_sys->b_video_autosize ) frame_sizer->Fit( this );
     }
 }
 
@@ -730,27 +732,24 @@
 
         //prevent continuous layout
         if( disc_frame->IsShown() ) return;
-
-        disc_frame->Show();
-        slider_sizer->Show( disc_frame );
     }
     else
     {
         //prevent continuous layout
         if( !disc_frame->IsShown() ) return;
-
-        disc_frame->Hide();
-        slider_sizer->Hide( disc_frame );
     }
 
+    if( layout && p_intf->p_sys->b_video_autosize )
+        UpdateVideoWindow( p_intf, video_window );
+
+    disc_frame->Show( show );
+    slider_sizer->Show( disc_frame, show );
+
     if( layout )
     {
         slider_sizer->Layout();
         if( p_intf->p_sys->b_video_autosize )
-        {
-            UpdateVideoWindow( p_intf, video_window );
             slider_sizer->Fit( slider_frame );
-        }
     }
 }
 
@@ -759,6 +758,9 @@
  *****************************************************************************/
 void Interface::OnControlsTimer( wxTimerEvent& WXUNUSED(event) )
 {
+    if( p_intf->p_sys->b_video_autosize )
+        UpdateVideoWindow( p_intf, video_window );
+
     /* Hide slider and Disc Buttons */
     //postpone layout, we'll do it ourselves
     HideDiscFrame( false );
@@ -768,7 +770,6 @@
     if( p_intf->p_sys->b_video_autosize )
     {
         slider_sizer->Fit( slider_frame );
-        UpdateVideoWindow( p_intf, video_window );
         frame_sizer->Fit( this );
     }
 }
@@ -1259,22 +1260,22 @@
         GetToolBar()->GetToolClientData( PlayStream_Event );
     if( !p_tool ) return;
 
-    GetToolBar()->DeleteTool( p_tool->GetId() );
-
     if( i_playing_status == PLAYING_S )
     {
-        p_tool = GetToolBar()->InsertTool(2, PlayStream_Event, wxT(""),
-                      wxBitmap( pause_xpm ), wxU(_(HELP_PAUSE)) );
-        p_tool->SetClientData( p_tool );
+        p_tool->SetNormalBitmap( wxBitmap( pause_xpm ) );
+        p_tool->SetLabel( wxU(_("Pause")) );
+        p_tool->SetShortHelp( wxU(_(HELP_PAUSE)) );
     }
     else
     {
-        p_tool = GetToolBar()->InsertTool(2, PlayStream_Event, wxT(""),
-                      wxBitmap( play_xpm ), wxU(_(HELP_PLAY)) );
-        p_tool->SetClientData( p_tool );
+        p_tool->SetNormalBitmap( wxBitmap( play_xpm ) );
+        p_tool->SetLabel( wxU(_("Play")) );
+        p_tool->SetShortHelp( wxU(_(HELP_PLAY)) );
     }
 
     GetToolBar()->Realize();
+    GetToolBar()->ToggleTool( PlayStream_Event, true );
+    GetToolBar()->ToggleTool( PlayStream_Event, false );
 
     i_old_playing_status = i_playing_status;
 }
@@ -1374,6 +1375,7 @@
     virtual ~wxVolCtrl() {};
 
     void UpdateVolume();
+    int GetVolume();
 
     void OnChange( wxMouseEvent& event );
 
@@ -1428,7 +1430,7 @@
   :wxControl( p_parent, -1, wxDefaultPosition, wxSize(64, VLCVOL_HEIGHT ),
               wxBORDER_NONE ),
    i_y_offset((VLCVOL_HEIGHT - TOOLBAR_BMP_HEIGHT) / 2),
-   p_intf(_p_intf)
+   b_mute(0), p_intf(_p_intf)
 {
     gauge = new wxVolCtrl( p_intf, this, -1, wxPoint( 18, i_y_offset ),
                            wxSize( 44, TOOLBAR_BMP_HEIGHT ) );
@@ -1436,11 +1438,8 @@
 
 void VLCVolCtrl::OnPaint( wxPaintEvent &evt )
 {
-    int i_volume;
-    i_volume = (audio_volume_t)config_GetInt( p_intf, "volume" );
-
     wxPaintDC dc( this );
-    wxBitmap mPlayBitmap( i_volume ? speaker_xpm : speaker_mute_xpm );
+    wxBitmap mPlayBitmap( b_mute ? speaker_mute_xpm : speaker_xpm );
     dc.DrawBitmap( mPlayBitmap, 0, i_y_offset, TRUE );
 }
 
@@ -1450,12 +1449,19 @@
     {
         int i_volume;
         aout_VolumeMute( p_intf, (audio_volume_t *)&i_volume );
+
+        b_mute = !b_mute;
+        Refresh();
     }
 }
 
 void VLCVolCtrl::UpdateVolume()
 {
     gauge->UpdateVolume();
+
+    int i_volume = gauge->GetValue();
+    if( !!i_volume == !b_mute ) return;
+    b_mute = !b_mute;
     Refresh();
 }
 
