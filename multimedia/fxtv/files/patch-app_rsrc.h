--- app_rsrc.h.orig	2001-02-12 22:17:53.000000000 +0100
+++ app_rsrc.h
@@ -525,96 +525,95 @@ static XtResource Resources[] = {
 };
 
 
-#define OPTION_HELP_STR "\
-                      BSD X TV (fxtv), Version " VERS_STR ".  
-                         Written by Randall Hopper
-
-Please mail Fxtv and Bt848 driver-related comments and help requests to the
-multimedia@freebsd.org list.  Feel free to subscribe and contribute 
-(listserv: majordomo@freebsd.org).
-
-Available options:
-
--driverDefaults             - Use appearance parms from driver on startup
--colorbars                  - Turn on colorbar display (for testing)
--hue [-90...90]             - Initial Hue           ; def=0
--brightness [-50..50]       - Initial Brightness (%); def=0
--contrast [0..200]          - Initial Contrast   (%); def=100
--satU [0..200]              - U Saturation       (%); def=100
--satV [0..284]              - V Saturation       (%); def=100
--aspectlock                 - Enable 4:3 aspect lock on video window
-
--deviceNumber <#>           - bktr/tuner device numbers; def=0      
--inputFormat <fmt>          - Tuner signal input format (ntsc,ntscm,ntscj,
-                                 palbdghi,pal,palm,paln,secam,palncomb,rsvd)
-
--tunerMode [cable|antenna]  - Tuner Mode
--defaultInput <input>       - Startup tuner signal input 
-                                 [tuner|video|svideo|csvideo|dev3]
--defaultAudioInput <input>  - Startup TV card audio input 
-                                 [tuner|external|internal|auto]
--defaultChannel <#>         - Startup Channel Number
--cableStationList   <...>   - List of cable station presets (see rsrc file)
--antennaStationList <...>   - List of antenna station presets
--cableFreqSet   <freqset>   - Freq set for cable   (def = cableirc)
-                              [nabcst|cableirc|cablehrc|weurope|jpnbcst|
-                               jpncable|xussr|australia|france]
--antennaFreqSet <freqset>   - Freq set for antenna (def = nabcst)
-
--noAudio                    - Suppress playing audio through soundcard
--dspDevice                  - Override default DSP device   (def=/dev/dsp)
--mixerDevice                - Override default mixer device (def=/dev/mixer)
--mixerChannel               - Audio mixer (line,line1/2/3,cd,mic,video)
-
--stationInWinTitle          - Display station text in window title
--stationInWinIcon           - Display station text in window icon
-
--stationAnnotFont <fontpat> - Font pattern for station annot (see rsrc file)
--stationAnnotColor <color>  - Color for station annot
--stationAnnotDelay <msec>   - How long to display (0 = never; -1 = always)
--stationAnnotIDOnly         - Display station ID alone (when available)
-
--tunerModeAnnot{Font,Color,Delay}
--inputDevAnnot{Font,Color,Delay}
--volumeDevAnnot{Font,Color,Delay}
--muteDevAnnot{Font,Color,Delay}
-                            - Other annotation options (see stationAnnot)
-
--remoteType                 - Type of attached remote control 
-                              [None|X10|Hauppauge|PixelView]
-
--recCmdMpeg2                - MPEG-2 Audio record command 
--recCmdMpeg3                - MPEG-3 Audio record command
--playCmdMpeg2               - MPEG-2 Audio play   command
--playCmdMpeg3               - MPEG-3 Audio play   command
-
--videoCnvtScript            - Video conversion workhorse script for vid encod.
-
--bswap2Bpp                  - Byte/word swap options for direct video
--nobswap2Bpp                  (used to match driver's pixel format with
--bswap3Bpp                    the video card's)
--nobswap3Bpp
--bswap4Bpp                        2Bpp - 15/16-bpp modes
--nobswap4Bpp                      3Bpp - packed 24bpp modes
--bwwap4Bpp                        4Bpp - unpacked 24bpp modes
--nowswap4Bpp
-
--Bpp24bit [3|4]             - Set frame buffer Bytes-per-pixel for 24bpp mode
--Bpp32bit [3|4]             - Set frame buffer Bytes-per-pixel for 32bpp mode
-
--videoCapFile[1-4]          - Optional paths (0-4) to scratch file paths to 
-                              use for video capture; spreads load across disks
-
--noafc                      - Disable AFC
--disableDirectV             - Disable DMA transfers straight to video card
--debug <area>               - Debug Msgs 
-                              {startup,driver,subproc,events,video,frame}
--help                       - Display program options
-
-NOTE:  All command line options are accessible as X resources as well.
-       The X resources have the same names as the command-line options.
-       See the sample Fxtv class resource file for details.
-"
+#define OPTION_HELP_STR \
+"                      BSD X TV (fxtv), Version " VERS_STR ".\n" \
+"                         Written by Randall Hopper\n" \
+"\n" \
+"Please mail Fxtv and Bt848 driver-related comments and help requests to the\n" \
+"multimedia@freebsd.org list.  Feel free to subscribe and contribute\n" \
+"(listserv: majordomo@freebsd.org).\n" \
+"\n" \
+"Available options:\n" \
+"\n" \
+"-driverDefaults             - Use appearance parms from driver on startup\n" \
+"-colorbars                  - Turn on colorbar display (for testing)\n" \
+"-hue [-90...90]             - Initial Hue           ; def=0\n" \
+"-brightness [-50..50]       - Initial Brightness (%); def=0\n" \
+"-contrast [0..200]          - Initial Contrast   (%); def=100\n" \
+"-satU [0..200]              - U Saturation       (%); def=100\n" \
+"-satV [0..284]              - V Saturation       (%); def=100\n" \
+"-aspectlock                 - Enable 4:3 aspect lock on video window\n" \
+"\n" \
+"-deviceNumber <#>           - bktr/tuner device numbers; def=0\n" \
+"-inputFormat <fmt>          - Tuner signal input format (ntsc,ntscm,ntscj,\n" \
+"                                 palbdghi,pal,palm,paln,secam,palncomb,rsvd)\n" \
+"\n" \
+"-tunerMode [cable|antenna]  - Tuner Mode\n" \
+"-defaultInput <input>       - Startup tuner signal input\n" \
+"                                 [tuner|video|svideo|csvideo|dev3]\n" \
+"-defaultAudioInput <input>  - Startup TV card audio input\n" \
+"                                 [tuner|external|internal|auto]\n" \
+"-defaultChannel <#>         - Startup Channel Number\n" \
+"-cableStationList   <...>   - List of cable station presets (see rsrc file)\n" \
+"-antennaStationList <...>   - List of antenna station presets\n" \
+"-cableFreqSet   <freqset>   - Freq set for cable   (def = cableirc)\n" \
+"                              [nabcst|cableirc|cablehrc|weurope|jpnbcst|\n" \
+"                               jpncable|xussr|australia|france]\n" \
+"-antennaFreqSet <freqset>   - Freq set for antenna (def = nabcst)\n" \
+"\n" \
+"-noAudio                    - Suppress playing audio through soundcard\n" \
+"-dspDevice                  - Override default DSP device   (def=/dev/dsp)\n" \
+"-mixerDevice                - Override default mixer device (def=/dev/mixer)\n" \
+"-mixerChannel               - Audio mixer (line,line1/2/3,cd,mic,video)\n" \
+"\n" \
+"-stationInWinTitle          - Display station text in window title\n" \
+"-stationInWinIcon           - Display station text in window icon\n" \
+"\n" \
+"-stationAnnotFont <fontpat> - Font pattern for station annot (see rsrc file)\n" \
+"-stationAnnotColor <color>  - Color for station annot\n" \
+"-stationAnnotDelay <msec>   - How long to display (0 = never; -1 = always)\n" \
+"-stationAnnotIDOnly         - Display station ID alone (when available)\n" \
+"\n" \
+"-tunerModeAnnot{Font,Color,Delay}\n" \
+"-inputDevAnnot{Font,Color,Delay}\n" \
+"-volumeDevAnnot{Font,Color,Delay}\n" \
+"-muteDevAnnot{Font,Color,Delay}\n" \
+"                            - Other annotation options (see stationAnnot)\n" \
+"\n" \
+"-remoteType                 - Type of attached remote control\n" \
+"                              [None|X10|Hauppauge|PixelView]\n" \
+"\n" \
+"-recCmdMpeg2                - MPEG-2 Audio record command\n" \
+"-recCmdMpeg3                - MPEG-3 Audio record command\n" \
+"-playCmdMpeg2               - MPEG-2 Audio play   command\n" \
+"-playCmdMpeg3               - MPEG-3 Audio play   command\n" \
+"\n" \
+"-videoCnvtScript            - Video conversion workhorse script for vid encod.\n" \
+"\n" \
+"-bswap2Bpp                  - Byte/word swap options for direct video\n" \
+"-nobswap2Bpp                  (used to match driver's pixel format with\n" \
+"-bswap3Bpp                    the video card's)\n" \
+"-nobswap3Bpp\n" \
+"-bswap4Bpp                        2Bpp - 15/16-bpp modes\n" \
+"-nobswap4Bpp                      3Bpp - packed 24bpp modes\n" \
+"-bwwap4Bpp                        4Bpp - unpacked 24bpp modes\n" \
+"-nowswap4Bpp\n" \
+"\n" \
+"-Bpp24bit [3|4]             - Set frame buffer Bytes-per-pixel for 24bpp mode\n" \
+"-Bpp32bit [3|4]             - Set frame buffer Bytes-per-pixel for 32bpp mode\n" \
+"\n" \
+"-videoCapFile[1-4]          - Optional paths (0-4) to scratch file paths to\n" \
+"                              use for video capture; spreads load across disks\n" \
+"\n" \
+"-noafc                      - Disable AFC\n" \
+"-disableDirectV             - Disable DMA transfers straight to video card\n" \
+"-debug <area>               - Debug Msgs\n" \
+"                              {startup,driver,subproc,events,video,frame}\n" \
+"-help                       - Display program options\n" \
+"\n" \
+"NOTE:  All command line options are accessible as X resources as well.\n" \
+"       The X resources have the same names as the command-line options.\n" \
+"       See the sample Fxtv class resource file for details.\n"
 
 static String fallback_resources[] = { 
  /*"Fxtv.geometry: +10+10",*/
