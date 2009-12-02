# NOTES about VLC Knobs:
# Below you will see a number of knobs, if it starts with WITHOUT_ it is
# enabled by default, if it starts with WITH_ it is disabled by default
# and will be autodetected to enable
#
# $FreeBSD$
#   $MCom: ports-stable/multimedia/vlc-devel/Makefile.inc,v 1.4 2009/01/09 23:41:21 mezz Exp $
#      $Id: Makefile.inc 6 2006-09-27 14:05:34Z buhnux $
# If you define for example WITH_FAAD and WITHOUT_FAAD
# the WITHOUT_ will always over ride the WITH_.
#
# Interface Knobs:
#
# WITH_NCURSES=yes
#  Ncurses (console) interface
#
# WITH_SKINS
#  This Interface supports a skinned interface usable with winamp 2.x skins
#  Skins can be found at http://www.videolan.org/vlc/download-skins.html
#
# Audio Knobs:
#
# WITH_ARTS=yes
#  Arts Support
#
# WITHOUT_DTS=yes
#  DTS decoder Support
#  useful for many dvds
#
# WITH_ESOUND=yes
#  Esound Support
#
# WITH_FAAC=yes
#  Faac audio encoder (mp4/aac) Support
#  ** Only enable this if you compiled multimedia/ffmpeg with WITH_FAAC knob **
#
# WITH_FAAD=yes
#  Faad audio decoder (mp4/aac) Support
#
# WITH_FLAC=yes
#  Flac Support
#
# WITHOUT_A52=yes
#  liba52 audio support
#
# WITHOUT_MODDEMUX
#  ModPlug mod-like music support
#
# WITHOUT_MPCDEMUX
#  Musepack audio compression support
#
# WITHOUT_REALAUDIO
#  Real audio(R) support
#
# WITH_SHOUT
#  Libshout2 support
#
# WITH_TREMOR
#  Interger-only Ogg Vorbis decoder
#   !!experimental!!
#
# WITHOUT_MAD=yes
#  Mad mp3 audio decoder Support
#
# WITHOUT_OGG=yes
#  Ogg audio decoder Support
#
# WITHOUT_SPEEX=yes
#  Speex voice codec Support
#
# WITH_TWOLAME=yes
#  Twolame Mpeg layer 2 audio Support
#
# WITHOUT_VORBIS=yes
#  Vorbis Support
#
# Graphics Knobs:
#
# WITH_AALIB=yes
#  Console Graphics Support
#
# WITH_CACA=yes
#  Console Graphics Support (implies WITH_AALIB)
#
# WITH_FRIBIDI=yes
#
# WITH_GGI=yes
#
# WITHOUT_SDL=yes
#  SDL video output
#
# WITH_SVG=yes
#
# WITH_SVGALIB=yes
#  SVGAlib video output
#
# WITH_XOSD=yes
#

# Multimedia Knobs:
#
# WITH_DIRAC
#  Enable dirac general-purpose video codec
#
# WITHOUT_X264
#  Enable H.264/AVC Video Support
#
# WITHOUT_MATROSKA=yes
#  Matroska Container Format Support
#
# WITHOUT_MPEG2=yes
#  Mpeg-2 A/V Decoder Support
#
# WITH_THEORA=yes
#  Video codec for OGG/Vorbis Support
#
# Streaming Knobs:
#
# WITHOUT_HTTPD=yes
#  Web interface to control streaming media
#
# WITH_LIVEMEDIA=yes
#  Support for rstp/rtp/sdp protocols
#  Only versions 2004.11.11 and higher are supported.
#
# WITHOUT_STREAM_PLUGINS=yes
#  Disable build and install of Streaming plugins
#
# WITH_WIN32_CODECS=yes
#  Support for win32 multimedia DLL's
#
# Other Knobs:
#
# WITHOUT_LUA=yes
#  Support for lua scripting (interfaces, HTML parsers for video websites...)
#
# WITHOUT_AVAHI=yes
#  Avahi (Rendezvous/Bonjour (R) ) networking
#
# WITHOUT_DBUS=yes
#  Disable d-bus support
#
# WITH_DEBUG=yes
#  Enable debuging support
#
# WITHOUT_CDROM=yes
#  Disable cddb and vcd support
#   and other cdrom support
#
# WITHOUT_CDPARANOIA=yes
#  Disable Cdparanoia support
#
# WITHOUT_DVBPSI=yes
#  TS MUX and DEMUX support
#
# WITHOUT_DVDNAV=yes
#  Disable DVD (dvd menus) support
#
# WITH_DVDREAD=yes
#  Enable Regular DVD support (non-menu)
#
# WITH_GECKO= libxul
# WITH_VLC_MOZILLA_PLUGIN= yes
#  Enable A mozilla plugin for VLC
#  See http://www.videolan.org/doc/vlc-user-guide/en/ch07.html#id2529837
#  for more info on using this plugin.
#   defaults to www/firefox/Makefile.webplugins
#
#  NOTE: The www/mplayer-plugin is much more complete.
#
# WITHOUT_GNOMEVFS
#  GnomeVFS support
#
# WITHOUT_HAL=yes
#  Disable HAL support
#
# WITHOUT_SAMBA=yes
#  Enable SAMBA Access module
#
# WITH_SSL=yes
#  Enable TLS/SSL Support for web (httpd) interface
#
# WITH_OCFLAGS=yes
#  Compile with -O3 -ffast-math -fomit-frame-pointer
#
# WITH_DVD_DEVICE=/dev/somedevice
#  default 5.x and above: /dev/acd0
#  default 4.x and below: /dev/acd0c
#  This option changes the default dvd device
#
# WITH_CDROM_DEVICE=/dev/somedevice
#  default 5.x and above: /dev/acd0
#  default 4.x and below: /dev/acd0c
#  This option changes the default cdrom device
#
# WITHOUT_NLS=yes
#  Disable Languarge Support
#
# WITHOUT_STREAM_PLUGINS=yes
#  Disable ALL streaming plugins.
#
# WITH_VLC_DEFAULT_FONT=/path/to/font
#  default: ${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf
#  This option lets you change the default font for subtitles
#
# NOPORTDOCS=yes
#  Do not install Vlc's Documents
#

post-patch:
# Do not assume LOCALBASE is /usr/local
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
# Subtitle default font
	@${REINPLACE_CMD} -e \
	's|/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf|${WITH_VLC_DEFAULT_FONT}|' \
		${WRKSRC}/modules/misc/freetype.c
# mozilla plugin
	@${REINPLACE_CMD} -e 's|$$(libdir)/mozilla/plugins|${FAKEDIR}/mozilla|; \
		s|$$(libdir)/mozilla/components|${FAKEDIR}/mozilla|' \
			${WRKSRC}/projects/mozilla/Makefile.in
# cdrom/dvd support
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${DEFAULT_CDROM_DEVICE}|; \
		s|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/include/vlc_config.h
# binary decoders
	@${REINPLACE_CMD} -e 's|-DWIN32_PATH=\\"\\"|-DWIN32_PATH=\\"${LOCALBASE}/lib/win32\\"|' \
		${WRKSRC}/libs/loader/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/lib/win32|${LOCALBASE}/lib/win32|' \
		${WRKSRC}/libs/loader/module.c

pre-install: build
	${RM} -rf ${PLIST} ${FAKEDIR}
	${MKDIR} ${FAKEDIR}
	${TOUCH} -f ${PLIST}
	${ECHO_CMD} "share/applications/vlc.desktop" >> ${PLIST}
.if !defined(WITHOUT_QT4)
	${ECHO_CMD} "share/pixmaps/qvlc.png" >> ${PLIST}
	${ECHO_CMD} "share/applications/qvlc.desktop" >> ${PLIST}
.endif
.if defined(WITH_SKINS) && !defined(WITHOUT_SKINS)
	${ECHO_CMD} "share/pixmaps/gvlc.png" >> ${PLIST}
	${ECHO_CMD} "share/applications/svlc.desktop" >> ${PLIST}
.endif
.if defined(WITH_SKINS) || !defined(WITHOUT_QT)
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
.endif
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} prefix=${FAKEDIR}
	${RM} -f ${FAKEDIR}/share/locale/locale.alias
	cd ${FAKEDIR}/bin && ${FIND} -s * | \
		${SED} -e 's|^|bin/|' >> ${PLIST}
	cd ${FAKEDIR}/include && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|include/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm include/|' >> ${PLIST}
	cd ${FAKEDIR}/lib && ${FIND} -s * -type f -o -type l| \
		${SED} -e 's|^|lib/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm lib/|' >> ${PLIST}
.if !defined(WITHOUT_X11)
	cd ${FAKEDIR}/libdata && ${FIND} -s * -type f -o -type l| \
		${SED} -e 's|^|libdata/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrmtry libdata/|' >> ${PLIST}
.endif
.for dir in vlc
	cd ${FAKEDIR}/share/${dir} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/${dir}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm share/${dir}/|' >> ${PLIST}
.endfor
.if !defined(NOPORTDOCS)
	cd ${FAKEDIR}/share/doc && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/doc/|' >> ${PLIST} \
		 && ${FIND} -d * -type d | \
		 ${SED} -e 's|^|@dirrm share/doc/|' >> ${PLIST}
.else
	${RM} -rf ${FAKEDIR}/share/doc
.endif
		${ECHO_MSG} "@dirrm share/vlc" >> ${PLIST}
.if !defined(WITHOUT_NLS)
	cd ${FAKEDIR}/share/locale &&  ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/locale/|' >> ${PLIST}
.endif
.if defined(WITH_VLC_MOZILLA_PLUGIN) && !defined(WITHOUT_VLC_MOZILLA_PLUGIN)
	cd ${FAKEDIR}/mozilla && ${FIND} -s * | \
		${SED} -e 's|^|%%WEBPLUGINS_DIR%%/|' >> ${PLIST}
	${ECHO_CMD} "@dirrmtry %%WEBPLUGINS_DIR%%" >> ${PLIST}
.endif
.for locale in ckb co fur kk km my oc ps tet tl
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/locale/${locale}/LC_MESSAGES 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/locale/${locale} 2>/dev/null || ${TRUE}" >> ${PLIST}
.endfor

do-install:
	cd ${FAKEDIR}/bin && ${FIND} . | \
		${CPIO} -vpdm -R ${BINOWN}:${BINGRP} ${PREFIX}/bin
	cd ${FAKEDIR}/include && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include
	cd ${FAKEDIR}/lib && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib
.if !defined(WITHOUT_X11)
	cd ${FAKEDIR}/libdata && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/libdata
.endif
	cd ${FAKEDIR}/share && ${FIND} . | \
		${CPIO} -vpdm -L -R ${SHAREOWN} ${PREFIX}/share
.if defined(WITH_VLC_MOZILLA_PLUGIN) && !defined(WITHOUT_VLC_MOZILLA_PLUGIN)
	@${MKDIR} ${WEBPLUGINS_DIR}
	${INSTALL_DATA} ${FAKEDIR}/mozilla/* ${WEBPLUGINS_DIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/vlc.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/vlc-config.1 ${MANPREFIX}/man/man1/
.if (defined(WITH_SKINS) && defined(WITHOUT_SKINS)) || !defined(WITHOUT_QT4)
	if [ ! -d ${PREFIX}/share/applications ]; then \
		${MKDIR} ${PREFIX}/share/applications ; \
	fi
	if [ ! -d ${PREFIX}/share/pixmaps ]; then \
		${MKDIR} ${PREFIX}/share/pixmaps ; \
	fi
.if !defined(WITHOUT_QT4)
	${INSTALL_DATA} ${FILESDIR}/qvlc.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${FAKEDIR}/share/vlc/vlc48x48.png ${PREFIX}/share/pixmaps/qvlc.png
.endif
.if defined(WITH_SKINS) && !defined(WITHOUT_SKINS)
	${INSTALL_DATA} ${FILESDIR}/svlc.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${FAKEDIR}/share/vlc/vlc48x48.png ${PREFIX}/share/pixmaps/gvlc.png
.endif
.endif
