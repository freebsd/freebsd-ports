# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vlc
DISTVERSION=	1.1.0
PORTEPOCH=	3
CATEGORIES=	multimedia audio ipv6 net www
MASTER_SITES=	http://download.videolan.org/pub/videolan/${PORTNAME}/${DISTVERSION}/ \
		http://ftp.snt.utwente.nl/pub/software/videolan/${PORTNAME}/${DISTVERSION}/ \
		ftp://ftp.crans.org/pub/videolan/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	jsa@wickedmachine.net
COMMENT=	Qt4 based multimedia player and streaming server

LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	A52 "A52 DVD audio decoder" On \
		AALIB "Aalib Console Graphics Support" Off \
		AVAHI "Enable Avahi mDNS networking" On \
		CACA "Libcaca Console Graphics Support (requires AALIB)" Off \
		DBUS "Enable D-Bus control support" On \
		DIRAC "Enable Dirac support" Off \
		DTS "DTS DVD audio decoder" On \
		DVDREAD "DVD Playback support" On \
		DVDNAV "DVD menu navigation" On \
		DVBPSI "DVBPSI mux/demux support" Off \
		FAAD "Faad audio decoder (mp4/aac) support" On \
		FLAC "Flac audio codec support" On \
		FLUID "Enable Fluidsynth MIDI support" Off \
		FRIBIDI "FriBidi bidirectional unicode support" Off \
		GGI "General Graphic Interface support" Off \
		GLX "X11 OpenGL rendering (requires XCB)" On \
		GNOMEVFS "Gnome VFS support" Off \
		GNUTLS "Enable viewing/transmission of encrypted streams" On \
		HTTPD "Streaming media control via http" On \
		JACK "Jack audio support" Off \
		LIVEMEDIA "Support for rstp/rtp/sdp protocols" On \
		LUA "Enable Lua scripting" On \
		MAD "Mad mp3 audio decoder support" On \
		MATROSKA "Matroska Container Format support" On \
		MODPLUG "Mod audio suport" Off \
		MPEG2 "Mpeg-2 audio/video decoder Support" On \
		MUSEPACK "Musepack audio support" Off \
		NCURSES "Enable ncurses (console) interface" Off \
		NLS "Native Language Support" On \
		NOTIFY "Enable tray notifications" Off \
		OCFLAGS "Optimized CFLAGS" Off \
		OGG "Ogg audio decoder support" On \
		OPENGL "OpenGL acceleration support" Off \
		PNG "PNG graphics format support" On \
		PULSE "Pulse Audio support" Off \
		QT4 "Qt4 Interface" On \
		REALAUDIO "Real Audio(R) support" On \
		SAMBA "SAMBA Access module" On \
		SCHROED "Enable Schroedinger decoder" Off \
		SDL "SDL video output" On \
		SHOUT "Shout2 support" Off \
		SKINS "Enable winamp skins interface (requires QT4)" On \
		STREAM "Enable stream output" On \
		SPEEX "Speex voice codec support" On \
		SQLITE "Enable SQLite database support" Off \
		SVG "SVG graphics support" Off \
		SVGALIB "SVGALIB video output" Off \
		TAGLIB "ID3 tag and Ogg comment support" On \
		THEORA "OGG/Vorbis video codec support" On \
		TREMOR "Tremor voice audio (redundant with Vorbis)" Off \
		TWOLAME "Twolame mpeg2 audio encoder support" On \
		UPNP "Enable UPnP network device control" Off \
		V4L "Enable Video for Linux & DVB support" On \
		VCD "Video CD support" On \
		VORBIS "Vorbis audio decoder support" On \
		X264 "Enable H.264/AVC codec support" On \
		XCB "Use X C Bindings for X11 output" On \
		XOSD "X11 On Screen Display support" Off \
		XVIDEO "X11 video rendering (requires XCB)" On \
		ZVBI "VBI decoding support" Off

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5_BUILD=	yes
WANT_GNOME=	yes

FAKEDIR=	${WRKDIR}/fake${PREFIX}
PLIST=		${WRKDIR}/plist

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${FAKEDIR}/include -I${WRKSRC}/include ${CPPFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/ffmpeg ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${FAKEDIR}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS} -lc" \
		LIBS="-lc"

CONFIGURE_ARGS+=	--enable-vlc \
			--enable-avcodec \
			--enable-avformat \
			--enable-oss \
			--enable-postproc \
			--enable-sftp \
			--disable-alsa \
			--disable-directfb \
			--disable-loader \
			--disable-telx \
			--disable-update-check \
			--disable-v4l2

MAN1=		vlc.1 \
		vlc-config.1 \
		vlc-wrapper.1

.include <bsd.port.options.mk>

# Macro section
# Use these for batch control of certain types of builds

# Disable DVD specific features
.if defined(WITHOUT_DVD)
WITHOUT_A52=yes
WITHOUT_DTS=yes
WITHOUT_DVDREAD=yes
WITHOUT_DVDNAV=yes
.endif

# Use this to disable all UI and output modules
.if defined(WITH_SERVER_ONLY)
WITHOUT_LUA=yes
WITHOUT_QT4=yes
WITHOUT_V4L=yes
WITHOUT_XCB=yes
.endif

# WITH_UNSAFE_PLUGINS
# This knob allows installation of misbehaving plugins that do not function as
# intended on FreeBSD. They are considered unsupported. Use if you would like to
# help fix them.

# This was the pre-1.1.0 DEBUG option. It differs in function than bsd.port.mk's
# knob and is not needed by most users. Put here for those who need/want it.
.if defined(WITH_VERBOSE)
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

# End Macro section

# Qt bits must be included before bsd.port.pre.mk
.if defined(WITHOUT_QT4)
CONFIGURE_ARGS+=--disable-qt4
.else
USE_QT_VER=	4
QT_COMPONENTS=	gui corelib moc_build rcc_build uic_build
CONFIGURE_ARGS+=--enable-qt4
.endif

.include <bsd.port.pre.mk>

# OS specific hacks
.if (${OSVERSION} < 800040)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules__misc__inhibit__xdg.c \
		${FILESDIR}/extra-patch-modules__misc__inhibit__xscreensaver.c
.endif

.if (${OSVERSION} < 703100)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules__access__file.c \
		${FILESDIR}/extra-patch-modules__access__fs.c
.endif

.if (${OSVERSION} < 700042) && defined(WITH_QT4)
IGNORE=	does not build on FreeBSD 6.x with Qt4.x, set this OPTION to off or\
	define WITHOUT_QT4 to build CLI only version
.endif

.if (${OSVERSION} < 701000)
CFLAGS+=	-DHAVE_SYS_MOUNT_H
.endif

.if (${OSVERSION} < 700000)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules_access_v4l2.c
.endif

.if ${PERL_LEVEL} < 500800
BROKEN=	Does not compile with perl ${PERL_VERSION}
.endif
# End OS specific hacks

# User tunables

# Define these to override
WITH_CDROM_DEVICE?=/dev/acd0
WITH_DVD_DEVICE?=/dev/acd0

# If you change this value, the dependancy will not be recorded
.if !defined(WITH_VLC_DEFAULT_FONT)
WITH_VLC_DEFAULT_FONT=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera
.endif

# OPTIONS
# Keep these organized!

.if defined(WITHOUT_A52)
CONFIGURE_ARGS+=--disable-a52
.else
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
CONFIGURE_ARGS+=--enable-a52
.endif

.if defined(WITH_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
CONFIGURE_ARGS+=--enable-aa
.else
CONFIGURE_ARGS+=--disable-aa
.endif

.if defined(WITH_AVAHI)
LIB_DEPENDS+=	avahi-common.3:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=--enable-bonjour
.else
CONFIGURE_ARGS+=--disable-bonjour
.endif

.if defined(WITH_CACA) && defined(WITH_AALIB)
LIB_DEPENDS+=	caca.0:${PORTSDIR}/graphics/libcaca
CONFIGURE_ARGS+=--enable-caca
.else
CONFIGURE_ARGS+=--disable-caca
.endif

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=--disable-dbus
.else
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=--enable-dbus
.endif

.if defined(WITH_DIRAC)
LIB_DEPENDS+=	dirac_decoder.1:${PORTSDIR}/multimedia/dirac
CONFIGURE_ARGS+=--enable-dirac
CPPFLAGS+=	-I${LOCALBASE}/include/dirac
.else
CONFIGURE_ARGS+=--disable-dirac
.endif

.if defined(WITHOUT_DTS)
CONFIGURE_ARGS+=--disable-dca
.else
LIB_DEPENDS+=	dca.0:${PORTSDIR}/multimedia/libdca
CONFIGURE_ARGS+=--enable-dca
.endif

.if defined(WITH_DVBPSI)
LIB_DEPENDS+=	dvbpsi.5:${PORTSDIR}/multimedia/libdvbpsi
CONFIGURE_ARGS+=--enable-dvbpsi \
		--with-dvbpsi=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-dvbpsi
.endif

.if defined(WITHOUT_DVDREAD)
CONFIGURE_ARGS+=--disable-dvdread
.else
LIB_DEPENDS+=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
CONFIGURE_ARGS+=--enable-dvdread
.endif

.if defined(WITHOUT_DVDNAV)
CONFIGURE_ARGS+=--disable-dvdnav
.else
LIB_DEPENDS+=	dvdnav.4:${PORTSDIR}/multimedia/libdvdnav
CONFIGURE_ARGS+=--enable-dvdnav
.endif

.if defined(WITHOUT_FAAD)
CONFIGURE_ARGS+=--disable-faad
.else
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
CONFIGURE_ARGS+=--enable-faad
.endif

.if defined(WITHOUT_FLAC)
CONFIGURE_ARGS+=--disable-flac
.else
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--enable-flac
.endif

.if defined(WITH_FLUID)
LIB_DEPENDS+=	fluidsynth.4:${PORTSDIR}/audio/fluidsynth
CONFIGURE_ARGS+=--enable-fluidsynth
.else
CONFIGURE_ARGS+=--disable-fluidsynth
.endif

.if defined(WITHOUT_FRIBIDI)
CONFIGURE_ARGS+=--disable-fribidi
.else
LIB_DEPENDS+=	fribidi.3:${PORTSDIR}/converters/fribidi
CONFIGURE_ARGS+=--enable-fribidi
.endif

.if defined(WITH_GGI)
LIB_DEPENDS+=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--enable-ggi
.else
CONFIGURE_ARGS+=--disable-ggi
.endif

.if defined(WITHOUT_GLX)
CONFIGURE_ARGS+=--disable-glx
.else
CONFIGURE_ARGS+=--enable-glx
.endif

.if defined(WITH_GNOMEVFS)
USE_GNOME=	gnomevfs2
CONFIGURE_ARGS+=--enable-gnomevfs
.else
COFIGURE_ARGS+=--disable-gnomevfs
.endif

.if defined(WITHOUT_GNUTLS)
CONFIGURE_ARGS+=--disable-gnutls
.else
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=--enable-gnutls
.endif

.if defined(WITHOUT_HTTPD)
CONFIGURE_ARGS+=--disable-httpd
.else
CONFIGURE_ARGS+=--enable-httpd
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=--enable-jack
.else
CONFIGURE_ARGS+=--disable-jack
.endif

.if defined(WITHOUT_LIVEMEDIA)
CONFIGURE_ARGS+=--disable-live555
.else
BUILD_DEPENDS+=	${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
CONFIGURE_ARGS+=--enable-live555 \
		--with-live555-tree=${LOCALBASE}/live
.endif

# This may become mandantory in the future
.if defined(WITHOUT_LUA)
CONFIGURE_ARGS+=--disable-lua
.else
USE_LUA=5.1+
WANT_LUA_VER=5.1
CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
CONFIGURE_ARGS+=--enable-lua LUAC=luac-${WANT_LUA_VER}
.endif

.if defined(WITHOUT_MAD)
CONFIGURE_ARGS+=--disable-mad
.else
LIB_DEPENDS+=	id3tag.0:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--enable-mad --with-mad=${LOCALBASE}
.endif

.if defined(WITHOUT_MATROSKA)
CONFIGURE_ARGS+=--disable-mkv
.else
LIB_DEPENDS+=	matroska.0:${PORTSDIR}/multimedia/libmatroska
CONFIGURE_ARGS+=--enable-mkv
.endif

.if defined(WITH_MODPLUG)
LIB_DEPENDS+=	modplug.1:${PORTSDIR}/audio/libmodplug
CONFIGURE_ARGS+=--enable-mod
.else
CONFIGURE_ARGS+=--disable-mod
.endif

.if defined(WITHOUT_MPEG2)
CONFIGURE_ARGS+=--disable-libmpeg2
.else
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
CONFIGURE_ARGS+=--enable-libmpeg2
.endif

.if defined(WITHOUT_MUSEPACK)
CONFIGURE_ARGS+=--disable-mpc
.else
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec
CONFIGURE_ARGS+=--enable-mpc
.endif

.if defined(WITH_NCURSES)
CONFIGURE_ARGS+=--enable-ncurses
.else
CONFIGURE_ARGS+=--disable-ncurses
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
.endif

.if defined(WITH_NOTIFY)
CONFIGURE_ARGS+=--enable-notify
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-notify
.endif

.if defined(WITH_OCFLAGS)
CFLAGS+=-O3 -ffast-math -fomit-frame-pointer
CONFIGURE_ARGS+=--enable-optimizations
.endif

.if !defined(WITHOUT_OGG)
LIB_DEPENDS+=	ogg.7:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=--enable-ogg
.else
CONFIGURE_ARGS+=--disable-ogg
WITHOUT_VORBIS=	yes
.endif

.if defined(WITH_OPENGL)
USE_GL=yes
CONFIGURE_ARGS+=--enable-opengl
.else
CONFIGURE_ARGS+=--disable-opengl
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=--disable-png
.else
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--enable-png
.endif

.if defined(WITH_PULSE)
CONFIGURE_ARGS+=--enable-pulse
.else
CONFIGURE_ARGS+=--disable-pulse
.endif

# WITHOUT_QT4
# Before .include <bsd.port.pre.mk>

.if defined(WITHOUT_REALAUDIO)
CONFIGURE_ARGS+=--disable-real --disable-realrtsp
.else
CONFIGURE_ARGS+=--enable-real --enable-realrtsp
.endif

.if !defined(WITHOUT_SAMBA)
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
CONFIGURE_ARGS+=--enable-smb
.else
CONFIGURE_ARGS+=--disable-smb
.endif

.if defined(WITH_SCHROED)
LIB_DEPENDS+=	schroedinger-1.0.3:${PORTSDIR}/multimedia/schroedinger
CONFIGURE_ARGS+=--enable-schroedinger
.else
CONFIGURE_ARGS+=--disable-schroedinger
.endif

.if defined(WITHOUT_SDL) || defined(WITHOUT_XCB)
CONFIGURE_ARGS+=--disable-sdl --disable-sdl-image
.else
WANT_SDL=	yes
USE_SDL=	image
CONFIGURE_ARGS+=--enable-sdl --enable-sdl-image
.endif

.if defined(WITH_SHOUT)
LIB_DEPENDS+=	shout.5:${PORTSDIR}/audio/libshout2
CONFIGURE_ARGS+=--enable-shout
.else
CONFIGURE_ARGS+=--disable-shout
.endif

.if defined(WITHOUT_SKINS) || defined(WITHOUT_QT4)
CONFIGURE_ARGS+=--disable-skins2 --disable-libtar
.else
LIB_DEPENDS+=	tar.0:${PORTSDIR}/devel/libtar
CONFIGURE_ARGS+=--enable-skins2 --enable-libtar
.endif

.if defined(WITHOUT_STREAM)
CONFIGURE_ARGS+=--disable-sout
.else
CONFIGURE_ARGS+=--enable-sout
.endif

.if defined(WITHOUT_SPEEX)
CONFIGURE_ARGS+=--disable-speex
.else
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=--enable-speex
CPPFLAGS+=-I${LOCALBASE}/include/speex
.endif

.if defined(WITH_SQLITE)
LIB_DEPENDS+=	sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=--enable-sqlite
.else
CONFIGURE_ARGS+=--disable-sqlite
.endif

.if defined(WITH_SVG) && !defined(WITHOUT_XCB)
USE_GNOME+=	librsvg2
CONFIGURE_ARGS+=--enable-svg
.else
CONFIGURE_ARGS+=--disable-svg
.endif

.if defined(WITH_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--enable-svgalib
.else
CONFIGURE_ARGS+=--disable-svgalib
.endif

.if defined(WITHOUT_TAGLIB)
CONFIGURE_ARGS+=--disable-taglib
.else
LIB_DEPENDS+=	tag.1:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=--enable-taglib
.endif

.if defined(WITHOUT_THEORA)
CONFIGURE_ARGS+=--disable-theora
.else
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
CONFIGURE_ARGS+=--enable-theora
.endif

.if defined(WITH_TREMOR) && !defined(WITH_VORBIS)
# Tremor is integer based Vorbis subset, using both is redundant
LIB_DEPENDS+=	vorbisidec.1:${PORTSDIR}/audio/libtremor
.else
CONFIGURE_ARGS+=--disable-tremor
.endif

.if defined(WITHOUT_TWOLAME)
CONFIGURE_ARGS+=	--disable-twolame
.else
LIB_DEPENDS+=		twolame.0:${PORTSDIR}/audio/twolame
CONFIGURE_ARGS+=	--enable-twolame
.endif

.if defined(WITH_UPNP)
LIB_DEPENDS+=	upnp.3:${PORTSDIR}/devel/upnp
CONFIGURE_ARGS+=--enable-upnp
.else
CONFIGURE_ARGS+=--disable-upnp
.endif

# Video for Linux and DVB (Digital Video Broadcast) support
.if defined(WITHOUT_V4L)
CONFIGURE_ARGS+=--disable-v4l --disable-dvb
.else
BUILD_DEPENDS+=	v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat
CONFIGURE_ARGS+=--enable-v4l --enable-dvb
.endif

.if defined(WITHOUT_VCD)
CONFIGURE_ARGS+=--disable-vcd --disable-libcddb
.else
CONFIGURE_ARGS+=--enable-vcd --enable-libcddb
.endif

.if defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=--disable-vorbis
.else
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--without-x
.else
CONFIGURE_ARGS+=--with-x
.endif

.if defined(WITH_X264)
CONFIGURE_ARGS+=--enable-x264
LIB_DEPENDS+=	x264.85:${PORTSDIR}/multimedia/x264
.else
CONFIGURE_ARGS+=--disable-x264
.endif

.if defined(WITHOUT_XCB)
CONFIGURE_ARGS+=--disable-xcb --without-x
.else
LIBDEPENDS+=	xcb.2:${PORTSDIR}/x11/libxcb
CONFIGURE_ARGS+=--enable-xcb --with-x
.endif

.if defined(WITH_XOSD)
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=--enable-xosd
.else
CONFIGURE_ARGS+=--disable-xosd
.endif

.if defined(WITHOUT_XVIDEO) || defined(WITHOUT_XCB)
CONFIGURE_ARGS+=--disable-xvideo
.else
CONFIGURE_ARGS+=--enable-xvideo
.endif

.if defined(WITH_ZVBI)
LIB_DEPENDS+=	zvbi.13:${PORTSDIR}/devel/libzvbi
CONFIGURE_ARGS+=--enable-zvbi
.else
CONFIGURE_ARGS+=--disable-zvbi
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf|${WITH_VLC_DEFAULT_FONT}|' \
		${WRKSRC}/modules/misc/freetype.c
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${WITH_CDROM_DEVICE}|g' \
		-e 's|/dev/dvd|${WITH_DVD_DEVICE}|g' \
		${WRKSRC}/include/vlc_config.h

pre-install:
	${RM} -rf ${PLIST} ${FAKEDIR}
	${MKDIR} ${FAKEDIR}
	${TOUCH} -f ${PLIST}
	${ECHO_CMD} "share/pixmaps/vlc.png" >> ${PLIST}
	${ECHO_CMD} "share/applications/vlc.desktop" >> ${PLIST}
	${ECHO_CMD} "@dirrmtry share/applications" >> ${PLIST}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET} prefix=${FAKEDIR}
	${RM} -f ${FAKEDIR}/share/locale/locale.alias
	cd ${FAKEDIR}/bin && ${FIND} -s * | \
		${SED} -e 's|^|bin/|' >> ${PLIST}
	cd ${FAKEDIR}/include && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|include/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrmtry include/|' >> ${PLIST}
.if !defined(WITH_UNSAFE_PLUGINS)
	${RM} -f ${FAKEDIR}/lib/vlc/plugins/services_discovery/libsap_plugin.la
	${RM} -f ${FAKEDIR}/lib/vlc/plugins/services_discovery/libsap_plugin.so
.endif
	cd ${FAKEDIR}/lib && ${FIND} -s * -type f -o -type l| \
		${SED} -e 's|^|lib/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrmtry lib/|' >> ${PLIST}
	if [ -d ${FAKEDIR}/libdata ]; then \
	cd ${FAKEDIR}/libdata && ${FIND} -s * -type f -o -type l| \
		${SED} -e 's|^|libdata/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrmtry libdata/|' >> ${PLIST} ; \
	fi
.for dir in icons kde4 vlc
	if [ -d ${FAKEDIR}/share/${dir} ]; then \
	cd ${FAKEDIR}/share/${dir} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/${dir}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrmtry share/${dir}/|' >> ${PLIST} \
		&& ${ECHO_CMD} "@dirrmtry share/${dir}" >> ${PLIST} ; \
	fi
.endfor
.if !defined(NOPORTDOCS)
	cd ${FAKEDIR}/share/doc && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/doc/|' >> ${PLIST} \
		 && ${FIND} -d * -type d | \
		 ${SED} -e 's|^|@dirrmtry share/doc/|' >> ${PLIST}
.else
	${RM} -rf ${FAKEDIR}/share/doc
.endif
.if !defined(WITHOUT_NLS)
	cd ${FAKEDIR}/share/locale && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|share/locale/|' >> ${PLIST}
.endif
.for locale in ckb co fur kk km my oc ps tet tl
	${ECHO_CMD} "@dirrmtry share/locale/${locale}/LC_MESSAGES" >> ${PLIST}
	${ECHO_CMD} "@dirrmtry share/locale/${locale}" >> ${PLIST}
.endfor

do-install:
	cd ${FAKEDIR}/bin && ${FIND} . | \
		${CPIO} -vpdm -R ${BINOWN}:${BINGRP} ${PREFIX}/bin
	cd ${FAKEDIR}/include && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include
	cd ${FAKEDIR}/lib && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib
	${INSTALL_DATA} ${FAKEDIR}/share/icons/hicolor/48x48/apps/vlc.png \
		${PREFIX}/share/pixmaps/vlc.png
	if [ -d ${FAKEDIR}/libdata ]; then \
	cd ${FAKEDIR}/libdata && ${FIND} . | \
		${CPIO} -vpdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/libdata ; \
	fi
	cd ${FAKEDIR}/share && ${FIND} . | \
		${CPIO} -vpdm -L -R ${SHAREOWN} ${PREFIX}/share
	${INSTALL_MAN} ${WRKSRC}/doc/vlc.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/vlc-config.1 ${MANPREFIX}/man/man1/
	if [ ! -d ${PREFIX}/share/applications ]; then \
		${MKDIR} ${PREFIX}/share/applications ; \
	fi

.include <bsd.port.post.mk>
