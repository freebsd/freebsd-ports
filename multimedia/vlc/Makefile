# Created by: Brian Somers <brian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vlc
DISTVERSION=	2.1.0
PORTREVISION=	3
PORTEPOCH=	4
CATEGORIES=	multimedia audio ipv6 net www
MASTER_SITES=	http://download.videolan.org/pub/videolan/${PORTNAME}/${DISTVERSION:S/a$//}/ \
		http://ftp.snt.utwente.nl/pub/software/videolan/${PORTNAME}/${DISTVERSION:S/a$//}/ \
		ftp://ftp.crans.org/pub/videolan/${PORTNAME}/${DISTVERSION:S/a$//}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Qt4 based multimedia player and streaming server

LICENSE=	GPLv2

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libproxy.so:${PORTSDIR}/net/libproxy \
		libdvbpsi.so:${PORTSDIR}/multimedia/libdvbpsi \
		libpulse.so:${PORTSDIR}/audio/pulseaudio
BUILD_DEPENDS=	ffmpeg>=2.0:${PORTSDIR}/multimedia/ffmpeg
RUN_DEPENDS=	ffmpeg>=2.0:${PORTSDIR}/multimedia/ffmpeg

OPTIONS_DEFINE=	A52 AALIB ASS AVAHI CACA DBUS DIRAC DOCS DTS DVDREAD \
		DVDNAV FAAD FLAC FLUID FRIBIDI GNOMEVFS GNUTLS GOOM \
		HTTPD JACK LIBSSH2 LIRC LIVEMEDIA LUA MAD MATROSKA MODPLUG \
		MPEG2 MTP MUSEPACK NCURSES NLS NOTIFY OPTIMIZED_CFLAGS OGG \
		OPUS PNG QT4 REALAUDIO RUNROOT \
		SAMBA SCHROED SDL SHOUTCAST SKINS STREAM SPEEX SVG \
		TAGLIB THEORA TWOLAME UPNP V4L VAAPI VCD VORBIS \
		X11 X264 ZVBI SERVER_ONLY DEBUG \
		GME NO_DVD LIBBLURAY SAMPLERATE SIDPLAY
OPTIONS_DEFAULT=A52 AVAHI DBUS DTS DVDREAD DVDNAV FAAD FLAC GNUTLS \
		HTTPD LUA MAD MATROSKA MPEG2 OGG OPUS PNG QT4 REALAUDIO \
		SDL SKINS STREAM SPEEX TAGLIB THEORA TWOLAME V4L \
		VCD VORBIS X11 X264 SAMPLERATE
ASS_DESC=	ASS/SSA subtitle rendering
DTS_DESC=	DTS DVD audio decoder
DVDREAD_DESC=	DVD Playback support
DVDNAV_DESC=	DVD menu navigation
FLUID_DESC=	Fluidsynth MIDI support
GME_DESC=	Game_Music_Emu (libgme) support
GNOMEVFS_DESC=	Gnome VFS support
GOOM_DESC=	the Goom visual effect library
LIBSSH2_DESC=	SCP/SFTP support via libssh2
NCURSES_DESC=	ncurses (console) interface
OPUS_DESC=	Opus audio format
REALAUDIO_DESC=	Real Audio(R) support
RUNROOT_DESC=	Enable running as root
SAMBA_DESC=	SAMBA Access module
SCHROED_DESC=	Schroedinger decoder
SIDPLAY_DESC=	C64 sid demux support
SKINS_DESC=	winamp skins interface
STREAM_DESC=	stream output
TAGLIB_DESC=	ID3 tag and Ogg comment support
V4L_DESC=	Video4Linux video capture compatibility
VCD_DESC=	Video CD support
ZVBI_DESC=	VBI decoding support
SERVER_ONLY_DESC=	Only build server parts
NO_DVD_DESC=	disable DVD specific features

QT4_CONFIGURE_ENABLE=	qt

A52_CONFIGURE_ENABLE=	a52
A52_LIB_DEPENDS=	liba52.so:${PORTSDIR}/audio/liba52

AALIB_LIB_DEPENDS=	libaa.so:${PORTSDIR}/graphics/aalib
AALIB_CONFIGURE_ENABLE=	aa

ASS_LIB_DEPENDS=	libass.so:${PORTSDIR}/multimedia/libass
ASS_CONFIGURE_ENABLE=	libass

AVAHI_LIB_DEPENDS=	libavahi-common.so:${PORTSDIR}/net/avahi-app
AVAHI_CONFIGURE_ENABLE=	bonjour

CACA_LIB_DEPENDS=	libcaca.so:${PORTSDIR}/graphics/libcaca
CACA_CONFIGURE_ENABLE=	caca

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CONFIGURE_ENABLE=	dbus

DEBUG_CONFIGURE_ENABLE=	debug

DIRAC_LIB_DEPENDS=	libdirac_decoder.so:${PORTSDIR}/multimedia/dirac
DIRAC_CONFIGURE_ENABLE=	dirac
DIRAC_CPPFLAGS=		-I${LOCALBASE}/include/dirac

DTS_LIB_DEPENDS=	libdca.so:${PORTSDIR}/multimedia/libdca
DTS_CONFIGURE_ARGS=	dca

DVDREAD_LIB_DEPENDS=	libdvdread.so:${PORTSDIR}/multimedia/libdvdread
DVDREAD_CONFIGURE_ENABLE=	dvdread

DVDNAV_LIB_DEPENDS=	libdvdnav.so:${PORTSDIR}/multimedia/libdvdnav
DVDNAV_CONFIGURE_ENABLE=	dvdnav

FAAD_LIB_DEPENDS=	libfaad.so:${PORTSDIR}/audio/faad
FAAD_CONFIGURE_ENABLE=	faad

FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CONFIGURE_ENABLE=	flac

FLUID_LIB_DEPENDS=	libfluidsynth.so:${PORTSDIR}/audio/fluidsynth
FLUID_CONFIGURE_ENABLE=	fluidsynth

FRIBIDI_LIB_DEPENDS=	libfribidi.so:${PORTSDIR}/converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=	fribidi

GME_LIB_DEPENDS=	libgme.so:${PORTSDIR}/audio/libgme
GME_CONFIGURE_ENABLE=	gme

GNOMEVFS_USE=	GNOME=gnomevfs2
GNOMEVFS_CONFIGURE_ENABLE=	gnomevfs

GNUTLS_LIB_DEPENDS=	libgnutls.so.28:${PORTSDIR}/security/gnutls3
GNUTLS_CONFIGURE_ENABLE=	gnutls

GOOM_LIB_DEPENDS=	libgoom2.so:${PORTSDIR}/graphics/goom
GOOM_CONFIGURE_ENABLE=	goom

HTTPD_CONFIGURE_ENABLE=	httpd

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ENABLE=	jack

LIBBLURAY_LIB_DEPENDS=	libbluray.so:${PORTSDIR}/multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	bluray

LIBSSH2_LIB_DEPENDS=	libssh2.so:${PORTSDIR}/security/libssh2
LIBSSH2_CONFIGURE_ENABLE=	sftp

LIRC_LIB_DEPENDS=	liblirc_client.so:${PORTSDIR}/comms/lirc
LIRC_CONFIGURE_ENABLE=	lirc

LIVEMEDIA_BUILD_DEPENDS=	${LOCALBASE}/live/liveMedia/libliveMedia.a:${PORTSDIR}/net/liveMedia
LIVEMEDIA_CONFIGURE_ENABLE=	live555
LIVEMEDIA_CPPFLAGS=	-I${LOCALBASE}/live/liveMedia/include \
		-I${LOCALBASE}/live/BasicUsageEnvironment/include \
		-I${LOCALBASE}/live/UsageEnvironment/include \
		-I${LOCALBASE}/live/groupsock/include
LIVEMEDIA_LDFLAGS=	-L${LOCALBASE}/live/groupsock \
		-L${LOCALBASE}/live/liveMedia \
		-L${LOCALBASE}/live/UsageEnvironment \
		-L${LOCALBASE}/live/BasicUsageEnvironment

MAD_LIB_DEPENDS=	libid3tag.so:${PORTSDIR}/audio/libid3tag \
			libmad.so:${PORTSDIR}/audio/libmad
MAD_CONFIGURE_ENABLE=	mad
MAD_CONFIGURE_ON=	--with-mad=${LOCALBASE}

MATROSKA_LIB_DEPENDS=	libmatroska.so:${PORTSDIR}/multimedia/libmatroska
MATROSKA_CONFIGURE_ENABLE=	mkv

MODPLUG_LIB_DEPENDS=	libmodplug.so:${PORTSDIR}/audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	mod

MPEG2_LIB_DEPENDS=	libmpeg2.so:${PORTSDIR}/multimedia/libmpeg2
MPEG2_CONFIGURE_ENABLE=	libmpeg2

MTP_LIB_DEPENDS=	libmtp.so:${PORTSDIR}/audio/libmtp
MTP_CONFIGURE_ENABLE=	mtp

MUSEPACK_LIB_DEPENDS=	libmpcdec.so:${PORTSDIR}/audio/musepack
MUSEPACK_CONFIGURE_ENABLE=	mpc

NCURSES_CONFIGURE_ENV=	NCURSES_CFLAGS="-I/usr/include" NCURSES_LIBS="-lncursesw"
NCURSES_CONFIGURE_ENABLE=	ncurses

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	notify

OPTIMIZED_CFLAGS_CFLAGS=	-O3 -ffast-math -fomit-frame-pointer
OPTIMIZED_CFLAGS_CONFIGURE_ENABLE=	optimizations

OPUS_LIB_DEPENDS=	libopus.so:${PORTSDIR}/audio/opus
OPUS_CONFIGURE_ENABLE=	opus

PNG_LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_ENABLE=	png

#PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
#PULSEAUDIO_CONFIGURE_ENABLE=	pulse

REALAUDIO_CONFIGURE_ENABLE=	realrtsp

RUNROOT_CONFIGURE_ENABLE=	run-as-root

SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:${PORTSDIR}/audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=	samplerate

SAMBA_LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
SAMBA_CONFIGURE_ENABLE=	smbclient
# There is no libsmbclient.pc
SAMBA_CONFIGURE_ENV=	SMBCLIENT_CFLAGS="-I${LOCALBASE}/include" \
			SMBCLIENT_LIBS="-lsmbclient"

SCHROED_LIB_DEPENDS=	libschroedinger-1.0.so:${PORTSDIR}/multimedia/schroedinger
SCHROED_CONFIGURE_ENABLE=	schroedinger

SIDPLAY_LIB_DEPENDS=	libsidplay2.so:${PORTSDIR}/audio/libsidplay2
SIDPLAY_LDFLAGS=	-L${LOCALBASE}/lib/sidplay/builders
SIDPLAY_CONFIGURE_ENABLE=	sid

SHOUTCAST_LIB_DEPENDS=	libshout.so:${PORTSDIR}/audio/libshout2
SHOUTCAST_CONFIGURE_ENABLE=	shout

STREAM_CONFIGURE_ENABLE=	sout

SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex
SPEEX_CONFIGURE_ENABLE=	speex
SPEEX_CPPFLAGS=		-I${LOCALBASE}/include/speex

TAGLIB_LIB_DEPENDS=	libtag.so:${PORTSDIR}/audio/taglib
TAGLIB_CONFIGURE_ENABLE=taglib

THEORA_LIB_DEPENDS=	libtheora.so:${PORTSDIR}/multimedia/libtheora
THEORA_CONFIGURE_ENABLE=theora

TWOLAME_LIB_DEPENDS=		libtwolame.so:${PORTSDIR}/audio/twolame
TWOLAME_CONFIGURE_ENABLE=	twolame

UPNP_LIB_DEPENDS=	libupnp.so:${PORTSDIR}/devel/upnp
UPNP_CONFIGURE_ENABLE=	upnp

VAAPI_LIB_DEPENDS=	libva.so:${PORTSDIR}/multimedia/libva
VAAPI_CONFIGURE_ENABLE=	libva

VCD_LIB_DEPENDS=	libcddb.so:${PORTSDIR}/audio/libcddb
VCD_CONFIGURE_ENABLE=	vcd libcddb

VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
VORBIS_CONFIGURE_ENABLE=vorbis

X264_LIB_DEPENDS=	libx264.so:${PORTSDIR}/multimedia/x264
X264_CONFIGURE_ENABLE=	x264

ZVBI_LIB_DEPENDS=	libzvbi.so:${PORTSDIR}/devel/libzvbi
ZVBI_CONFIGURE_ENABLE=	zvbi

USE_XZ=		yes
USES=		desktop-file-utils iconv perl5 gmake pkgconfig
USE_PERL5=	build
USE_GL=		yes
USE_CSTD=	gnu99
WANT_GNOME=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${WRKSRC}/include
CONFIGURE_ENV=	LIBS="-lc"
LDFLAGS+=	${PTHREAD_LIBS} -lc

CONFIGURE_ARGS+=	--enable-vlc \
			--enable-avcodec \
			--enable-avformat \
			--enable-postproc \
			--enable-pulse \
			--enable-sftp \
			--enable-libgcrypt \
			--disable-alsa \
			--disable-dc1394 \
			--disable-directfb \
			--disable-oss \
			--disable-projectm \
			--disable-telx \
			--disable-tremor \
			--disable-udev \
			--disable-update-check

.include <bsd.port.options.mk>

# Macro section
# Use these for batch control of certain types of builds

# Disable DVD specific features
.if ${PORT_OPTIONS:MNO_DVD}
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}
PORT_OPTIONS:=	${PORT_OPTIONS:NA52}
PORT_OPTIONS:=	${PORT_OPTIONS:NDVDREAD}
PORT_OPTIONS:=	${PORT_OPTIONS:NDVDNAV}
.endif

# Use this to disable all UI and output modules
.if ${PORT_OPTIONS:MSERVER_ONLY}
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}
PORT_OPTIONS:=	${PORT_OPTIONS:NLUA}
PORT_OPTIONS:=	${PORT_OPTIONS:NQT4}
PORT_OPTIONS:=	${PORT_OPTIONS:NSKINS}
.if empty(PORT_OPTIONS:MRUNROOT)
PORT_OPTIONS+=	RUNROOT
PORT_OPTIONS:=	${PORT_OPTIONS:O:u}
.endif
.endif

# End Macro section
#

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	gui corelib moc_build rcc_build uic_build
.endif

# This may become mandantory in the future
.if ${PORT_OPTIONS:MLUA}
USE_LUA=5.1+
WANT_LUA_VER=5.1
CONFIGURE_ENV+=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
CONFIGURE_ARGS+=--enable-lua LUAC=luac-${WANT_LUA_VER}
.else
CONFIGURE_ARGS+=--disable-lua
.endif

.if ${PORT_OPTIONS:MOGG}
LIB_DEPENDS+=	libogg.so:${PORTSDIR}/audio/libogg \
		libkate.so:${PORTSDIR}/multimedia/libkate
CONFIGURE_ARGS+=--enable-ogg --enable-kate
.else
PORT_OPTIONS:=	${PORT_OPTIONS:NVORBIS}
CONFIGURE_ARGS+=--disable-ogg --disable-kate
.endif

.if ${PORT_OPTIONS:MSDL} && ${PORT_OPTIONS:MX11}
WANT_SDL=	yes
USE_SDL=	image
CONFIGURE_ARGS+=--enable-sdl --enable-sdl-image
.else
CONFIGURE_ARGS+=--disable-sdl --disable-sdl-image
.endif

.if ${PORT_OPTIONS:MSKINS}
.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	libtar.so:${PORTSDIR}/devel/libtar
CONFIGURE_ARGS+=--enable-skins2 --enable-libtar
.else
IGNORE=	SKINS option requires QT4 option
.endif
.else
CONFIGURE_ARGS+=--disable-skins2 --disable-libtar
.endif

.if ${PORT_OPTIONS:MSVG} && ${PORT_OPTIONS:MX11}
USE_GNOME+=	librsvg2
CONFIGURE_ARGS+=--enable-svg
.else
CONFIGURE_ARGS+=--disable-svg
.endif

.if ${PORT_OPTIONS:MV4L} || ${PORT_OPTIONS:MDVB}
LIB_DEPENDS+=	libv4l1.so:${PORTSDIR}/multimedia/libv4l
CONFIGURE_ARGS+=--enable-v4l2
.else
CONFIGURE_ARGS+=--disable-v4l2
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=xcb xpm
LIB_DEPENDS+=	libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms
CONFIGURE_ARGS+=--with-x --enable-glx --enable-xcb --enable-xvideo
.else
CONFIGURE_ARGS+=--without-x --disable-glx --disable-xcb --disable-xvideo
.endif

.include <bsd.port.pre.mk>

# base clang in 9.0 builds a corrupted lib/vlc/plugins/gui/libqt4_plugin.so
.if (${CC:T:Mclang} == "clang") && \
	(${OSVERSION} >= 900014) && (${OSVERSION} < 900506)
IGNORE=		base clang version too old, set NO_IGNORE to override
.endif

.if ${ARCH} == "powerpc64"
CONFIGURE_ARGS+=--enable-altivec # VLC's config script doesn't know to do this
.endif

# prefer clang on 9.1+
.if (${OSVERSION} >= 901000) && exists(${DESTDIR}/usr/bin/clang)
CC=	clang
CXX=	clang++
CPP=	clang-cpp
.else
.if ${ARCH} == "i386"
USE_GCC?=	yes # sse/3dnow detection on i386 needs newer GCC
.endif
.endif

# End OS specific hacks

# User tunables

# Define these to override
# FreeBSD 9.x uses CAM devices
.if (${OSVERSION} > 900037)
WITH_CDROM_DEVICE?=/dev/cd0
WITH_DVD_DEVICE?=/dev/cd0
.else
WITH_CDROM_DEVICE?=/dev/acd0
WITH_DVD_DEVICE?=/dev/acd0
.endif

# If you change this value, the dependancy will not be recorded
.if !defined(WITH_VLC_DEFAULT_FONT)
WITH_VLC_DEFAULT_FONT=		${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf
WITH_VLC_DEFAULT_MONO_FONT=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/VeraMono.ttf
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e '\|LIBS|s|-lrt||' \
		-e 's|gnutls |gnutls3 |g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf|${WITH_VLC_DEFAULT_FONT}|' \
		${WRKSRC}/modules/text_renderer/freetype.c
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${WITH_CDROM_DEVICE}|g' \
		-e 's|/dev/dvd|${WITH_DVD_DEVICE}|g' \
		${WRKSRC}/include/vlc_config.h
	@${RM} -rf ${WRKSRC}/modules/access/v4l2/linux

post-install:
	@if [ -n "${MTREE_FILE}" ]; then \
	{ ${ECHO_CMD} "#mtree"; ${CAT} ${MTREE_FILE}; } | ${TAR} tf - | \
		awk '{ sub(/^\.$$/, "", $$1); \
		if ($$1 == "") print "${PREFIX}"; else print "${PREFIX}/"$$1; }' ; \
	fi > ${WRKDIR}/.mtree
	@a=${PREFIX}; \
		while :; do \
			a=$${a%/*} ; \
			[ -z "$${a}" ] && break ; \
			${ECHO_CMD} $${a} >> ${WRKDIR}/.mtree ; \
		done
	@${FIND} ${STAGEDIR} -type f -o -type l | ${SORT} | ${SED} -E -e "s,${STAGEDIR},,g" \
		-e "s,${PREFIX}/,,g" -e "s,(.*man/.*\.[0-9])$$,\1.gz,g"| ${GREP} -v "^share/licenses" >> ${TMPPLIST} || ${TRUE}
	@${FIND} ${STAGEDIR} -type d | ${SED} -e "s,${STAGEDIR},,g" \
		| while read line; do \
		${GREP} -qw "^$${line}$$" ${WRKDIR}/.mtree || { \
			[ -n "$${line}" ] && ${ECHO_CMD} "@unexec rmdir "%D/$${line}" >/dev/null 2>&1 || :"; \
		}; \
		done | ${SORT} -r | ${SED} \
		-e "s,${PREFIX}/,,g" | ${GREP} -v "^@unexec rmdir %D/share/licenses" >> ${TMPPLIST} || ${TRUE}


.include <bsd.port.post.mk>
