diff -Nur modules/demux/mkv.cpp.orig modules/demux/mkv.cpp
--- modules/demux/mkv.cpp.orig	2003-12-22 15:27:37.000000000 +0100
+++ modules/demux/mkv.cpp	2004-01-21 17:02:42.000000000 +0100
@@ -543,15 +543,15 @@
                             msg_Dbg( p_input, "|   |   |   + Track Type=%s",
                                      psz_type );
                         }
-                        else  if( EbmlId( *el3 ) == KaxTrackFlagEnabled::ClassInfos.GlobalId )
-                        {
-                            KaxTrackFlagEnabled &fenb = *(KaxTrackFlagEnabled*)el3;
-                            fenb.ReadData( p_sys->es->I_O() );
-
-                            tk.b_enabled = uint32( fenb );
-                            msg_Dbg( p_input, "|   |   |   + Track Enabled=%u",
-                                     uint32( fenb )  );
-                        }
+//                         else  if( EbmlId( *el3 ) == KaxTrackFlagEnabled::ClassInfos.GlobalId )
+//                         {
+//                             KaxTrackFlagEnabled &fenb = *(KaxTrackFlagEnabled*)el3;
+//                             fenb.ReadData( p_sys->es->I_O() );
+
+//                             tk.b_enabled = uint32( fenb );
+//                             msg_Dbg( p_input, "|   |   |   + Track Enabled=%u",
+//                                      uint32( fenb )  );
+//                         }
                         else  if( EbmlId( *el3 ) == KaxTrackFlagDefault::ClassInfos.GlobalId )
                         {
                             KaxTrackFlagDefault &fdef = *(KaxTrackFlagDefault*)el3;
@@ -651,44 +651,44 @@
                             tk.psz_codec_name = UTF8ToStr( UTFstring( cname ) );
                             msg_Dbg( p_input, "|   |   |   + Track Codec Name=%s", tk.psz_codec_name );
                         }
-                        else if( EbmlId( *el3 ) == KaxCodecSettings::ClassInfos.GlobalId )
-                        {
-                            KaxCodecSettings &cset = *(KaxCodecSettings*)el3;
-                            cset.ReadData( p_sys->es->I_O() );
-
-                            tk.psz_codec_settings = UTF8ToStr( UTFstring( cset ) );
-                            msg_Dbg( p_input, "|   |   |   + Track Codec Settings=%s", tk.psz_codec_settings );
-                        }
-                        else if( EbmlId( *el3 ) == KaxCodecInfoURL::ClassInfos.GlobalId )
-                        {
-                            KaxCodecInfoURL &ciurl = *(KaxCodecInfoURL*)el3;
-                            ciurl.ReadData( p_sys->es->I_O() );
-
-                            tk.psz_codec_info_url = strdup( string( ciurl ).c_str() );
-                            msg_Dbg( p_input, "|   |   |   + Track Codec Info URL=%s", tk.psz_codec_info_url );
-                        }
-                        else if( EbmlId( *el3 ) == KaxCodecDownloadURL::ClassInfos.GlobalId )
-                        {
-                            KaxCodecDownloadURL &cdurl = *(KaxCodecDownloadURL*)el3;
-                            cdurl.ReadData( p_sys->es->I_O() );
-
-                            tk.psz_codec_download_url = strdup( string( cdurl ).c_str() );
-                            msg_Dbg( p_input, "|   |   |   + Track Codec Info URL=%s", tk.psz_codec_download_url );
-                        }
-                        else if( EbmlId( *el3 ) == KaxCodecDecodeAll::ClassInfos.GlobalId )
-                        {
-                            KaxCodecDecodeAll &cdall = *(KaxCodecDecodeAll*)el3;
-                            cdall.ReadData( p_sys->es->I_O() );
-
-                            msg_Dbg( p_input, "|   |   |   + Track Codec Decode All=%u <== UNUSED", uint8( cdall ) );
-                        }
-                        else if( EbmlId( *el3 ) == KaxTrackOverlay::ClassInfos.GlobalId )
-                        {
-                            KaxTrackOverlay &tovr = *(KaxTrackOverlay*)el3;
-                            tovr.ReadData( p_sys->es->I_O() );
+//                         else if( EbmlId( *el3 ) == KaxCodecSettings::ClassInfos.GlobalId )
+//                         {
+//                             KaxCodecSettings &cset = *(KaxCodecSettings*)el3;
+//                             cset.ReadData( p_sys->es->I_O() );
+
+//                             tk.psz_codec_settings = UTF8ToStr( UTFstring( cset ) );
+//                             msg_Dbg( p_input, "|   |   |   + Track Codec Settings=%s", tk.psz_codec_settings );
+//                         }
+//                         else if( EbmlId( *el3 ) == KaxCodecInfoURL::ClassInfos.GlobalId )
+//                         {
+//                             KaxCodecInfoURL &ciurl = *(KaxCodecInfoURL*)el3;
+//                             ciurl.ReadData( p_sys->es->I_O() );
+
+//                             tk.psz_codec_info_url = strdup( string( ciurl ).c_str() );
+//                             msg_Dbg( p_input, "|   |   |   + Track Codec Info URL=%s", tk.psz_codec_info_url );
+//                         }
+//                         else if( EbmlId( *el3 ) == KaxCodecDownloadURL::ClassInfos.GlobalId )
+//                         {
+//                             KaxCodecDownloadURL &cdurl = *(KaxCodecDownloadURL*)el3;
+//                             cdurl.ReadData( p_sys->es->I_O() );
+
+//                             tk.psz_codec_download_url = strdup( string( cdurl ).c_str() );
+//                             msg_Dbg( p_input, "|   |   |   + Track Codec Info URL=%s", tk.psz_codec_download_url );
+//                         }
+//                         else if( EbmlId( *el3 ) == KaxCodecDecodeAll::ClassInfos.GlobalId )
+//                         {
+//                             KaxCodecDecodeAll &cdall = *(KaxCodecDecodeAll*)el3;
+//                             cdall.ReadData( p_sys->es->I_O() );
+
+//                             msg_Dbg( p_input, "|   |   |   + Track Codec Decode All=%u <== UNUSED", uint8( cdall ) );
+//                         }
+//                         else if( EbmlId( *el3 ) == KaxTrackOverlay::ClassInfos.GlobalId )
+//                         {
+//                             KaxTrackOverlay &tovr = *(KaxTrackOverlay*)el3;
+//                             tovr.ReadData( p_sys->es->I_O() );
 
-                            msg_Dbg( p_input, "|   |   |   + Track Overlay=%u <== UNUSED", uint32( tovr ) );
-                        }
+//                             msg_Dbg( p_input, "|   |   |   + Track Overlay=%u <== UNUSED", uint32( tovr ) );
+//                         }
                         else  if( EbmlId( *el3 ) == KaxTrackVideo::ClassInfos.GlobalId )
                         {
                             msg_Dbg( p_input, "|   |   |   + Track Video" );
@@ -698,21 +698,22 @@
 
                             while( ( el4 = p_sys->ep->Get() ) != NULL )
                             {
-                                if( EbmlId( *el4 ) == KaxVideoFlagInterlaced::ClassInfos.GlobalId )
-                                {
-                                    KaxVideoFlagInterlaced &fint = *(KaxVideoFlagInterlaced*)el4;
-                                    fint.ReadData( p_sys->es->I_O() );
-
-                                    msg_Dbg( p_input, "|   |   |   |   + Track Video Interlaced=%u", uint8( fint ) );
-                                }
-                                else if( EbmlId( *el4 ) == KaxVideoStereoMode::ClassInfos.GlobalId )
-                                {
-                                    KaxVideoStereoMode &stereo = *(KaxVideoStereoMode*)el4;
-                                    stereo.ReadData( p_sys->es->I_O() );
-
-                                    msg_Dbg( p_input, "|   |   |   |   + Track Video Stereo Mode=%u", uint8( stereo ) );
-                                }
-                                else if( EbmlId( *el4 ) == KaxVideoPixelWidth::ClassInfos.GlobalId )
+//                                 if( EbmlId( *el4 ) == KaxVideoFlagInterlaced::ClassInfos.GlobalId )
+//                                 {
+//                                     KaxVideoFlagInterlaced &fint = *(KaxVideoFlagInterlaced*)el4;
+//                                     fint.ReadData( p_sys->es->I_O() );
+
+//                                     msg_Dbg( p_input, "|   |   |   |   + Track Video Interlaced=%u", uint8( fint ) );
+//                                 }
+//                                 else if( EbmlId( *el4 ) == KaxVideoStereoMode::ClassInfos.GlobalId )
+//                                 {
+//                                     KaxVideoStereoMode &stereo = *(KaxVideoStereoMode*)el4;
+//                                     stereo.ReadData( p_sys->es->I_O() );
+
+//                                     msg_Dbg( p_input, "|   |   |   |   + Track Video Stereo Mode=%u", uint8( stereo ) );
+//                                 }
+//                                 else 
+                              if( EbmlId( *el4 ) == KaxVideoPixelWidth::ClassInfos.GlobalId )
                                 {
                                     KaxVideoPixelWidth &vwidth = *(KaxVideoPixelWidth*)el4;
                                     vwidth.ReadData( p_sys->es->I_O() );
@@ -752,28 +753,28 @@
                                     tk.f_fps = float( vfps );
                                     msg_Dbg( p_input, "   |   |   |   + fps=%f", float( vfps ) );
                                 }
-                                else if( EbmlId( *el4 ) == KaxVideoDisplayUnit::ClassInfos.GlobalId )
-                                {
-                                     KaxVideoDisplayUnit &vdmode = *(KaxVideoDisplayUnit*)el4;
-                                    vdmode.ReadData( p_sys->es->I_O() );
+//                                 else if( EbmlId( *el4 ) == KaxVideoDisplayUnit::ClassInfos.GlobalId )
+//                                 {
+//                                      KaxVideoDisplayUnit &vdmode = *(KaxVideoDisplayUnit*)el4;
+//                                     vdmode.ReadData( p_sys->es->I_O() );
+
+//                                     msg_Dbg( p_input, "|   |   |   |   + Track Video Display Unit=%s",
+//                                              uint8( vdmode ) == 0 ? "pixels" : ( uint8( vdmode ) == 1 ? "centimeters": "inches" ) );
+//                                 }
+//                                 else if( EbmlId( *el4 ) == KaxVideoAspectRatio::ClassInfos.GlobalId )
+//                                 {
+//                                     KaxVideoAspectRatio &ratio = *(KaxVideoAspectRatio*)el4;
+//                                     ratio.ReadData( p_sys->es->I_O() );
+
+//                                     msg_Dbg( p_input, "   |   |   |   + Track Video Aspect Ratio Type=%u", uint8( ratio ) );
+//                                 }
+//                                 else if( EbmlId( *el4 ) == KaxVideoGamma::ClassInfos.GlobalId )
+//                                 {
+//                                     KaxVideoGamma &gamma = *(KaxVideoGamma*)el4;
+//                                     gamma.ReadData( p_sys->es->I_O() );
 
-                                    msg_Dbg( p_input, "|   |   |   |   + Track Video Display Unit=%s",
-                                             uint8( vdmode ) == 0 ? "pixels" : ( uint8( vdmode ) == 1 ? "centimeters": "inches" ) );
-                                }
-                                else if( EbmlId( *el4 ) == KaxVideoAspectRatio::ClassInfos.GlobalId )
-                                {
-                                    KaxVideoAspectRatio &ratio = *(KaxVideoAspectRatio*)el4;
-                                    ratio.ReadData( p_sys->es->I_O() );
-
-                                    msg_Dbg( p_input, "   |   |   |   + Track Video Aspect Ratio Type=%u", uint8( ratio ) );
-                                }
-                                else if( EbmlId( *el4 ) == KaxVideoGamma::ClassInfos.GlobalId )
-                                {
-                                    KaxVideoGamma &gamma = *(KaxVideoGamma*)el4;
-                                    gamma.ReadData( p_sys->es->I_O() );
-
-                                    msg_Dbg( p_input, "   |   |   |   + fps=%f", float( gamma ) );
-                                }
+//                                     msg_Dbg( p_input, "   |   |   |   + fps=%f", float( gamma ) );
+//                                 }
                                 else
                                 {
                                     msg_Dbg( p_input, "|   |   |   |   + Unknown (%s)", typeid(*el4).name() );
