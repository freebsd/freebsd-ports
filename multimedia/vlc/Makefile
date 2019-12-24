# Created by: Brian Somers <brian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vlc
DISTVERSION=	3.0.8
PORTREVISION=	15
PORTEPOCH=	4
CATEGORIES=	multimedia audio net www
MASTER_SITES=	http://download.videolan.org/pub/videolan/${PORTNAME}/${DISTVERSION:S/a$//}/ \
		http://ftp.snt.utwente.nl/pub/software/videolan/${PORTNAME}/${DISTVERSION:S/a$//}/ \
		ftp://ftp.crans.org/pub/videolan/${PORTNAME}/${DISTVERSION:S/a$//}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Qt based multimedia player and streaming server

LICENSE=	GPLv2

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libdvbpsi.so:multimedia/libdvbpsi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libidn.so:dns/libidn \
		libmatroska.so:multimedia/libmatroska
BUILD_DEPENDS=	ffmpeg>=3.4.1,1:multimedia/ffmpeg \
		yasm:devel/yasm
RUN_DEPENDS=	ffmpeg>=3.4.1,1:multimedia/ffmpeg

USES=		compiler:c++11-lib desktop-file-utils gettext-tools gmake gnome \
		iconv libtool localbase pathfix pkgconfig tar:xz

# VLC git (post 2.2.4) requires C++11 support and passes the appropriate flag
# to the compiler. Until the port is updated, we explicitly pass -std=c++11 to
# the compiler because Qt 5.7+ requires C++11 support, and FreeBSD 10's clang
# does not default to C++11 mode.
USE_CXXSTD=	c++11

USE_GNOME=	libxml2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-avcodec --enable-avformat --enable-dvbpsi \
		--enable-fontconfig --enable-freetype --enable-libgcrypt \
		--enable-libxml2 --enable-oss --enable-postproc \
		--enable-swscale --enable-vlc \
		--disable-alsa --disable-archive --disable-chromaprint --disable-crystalhd \
		--disable-dc1394 --disable-decklink --disable-dsm \
		--disable-dv1394 --disable-fdkaac --disable-gst-decode \
		--disable-gles2 --disable-kai --disable-kva \
		--disable-vnc --disable-opencv --disable-projectm \
		--disable-secret --disable-soxr --disable-telx \
		--disable-tiger --disable-tremor --disable-udev \
		--disable-update-check --disable-vsxu \
		--disable-wasapi --disable-x26410b \
		--with-kde-solid=${PREFIX}/share/solid/actions \
		ac_cv_search_pthread_rwlock_init=-pthread \
		BUILDCC="${CC}"
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif
CFLAGS_i386=	-fomit-frame-pointer

OPTIONS_DEFINE=	A52 AALIB AOM ASS AVAHI CACA CHROMECAST DAV1D DBUS DCA DOCS DVDREAD \
		DVDNAV FAAD FLAC FLUID FREERDP FRIBIDI GME GNUTLS \
		GOOM HARFBUZZ JACK JPEG KATE LIBBLURAY LIBPLACEBO LIBRSVG2 LIBSSH2 LIRC \
		LIVEMEDIA LUA MAD MFX MODPLUG MPEG2 MTP MUSEPACK \
		NCURSES NFS NLS NOTIFY OGG OGGSPOTS OPTIMIZED_CFLAGS OPUS PNG PULSEAUDIO \
		QT5 REALRTSP RUNROOT SAMPLERATE SIDPLAY SCHROEDINGER \
		SDL SHOUTCAST SKINS SMB SNDIO STREAM SPEEX TAGLIB THEORA \
		TWOLAME UPNP V4L VAAPI VCD VDPAU VPX VORBIS WAYLAND X11 X264 X265 ZVBI
OPTIONS_DEFINE_powerpc=	ALTIVEC
OPTIONS_DEFINE_powerpc64=	ALTIVEC
OPTIONS_DEFAULT=A52 AVAHI DAV1D DBUS DCA DVDREAD DVDNAV FAAD FLAC GNUTLS JPEG \
		LIVEMEDIA LUA MAD MPEG2 OGG OPTIMIZED_CFLAGS \
		OPUS PNG QT5 SAMPLERATE STREAM SPEEX TAGLIB THEORA TWOLAME \
		V4L VAAPI VCD VDPAU VORBIS WAYLAND X11
OPTIONS_DEFAULT_powerpc=	ALTIVEC
OPTIONS_DEFAULT_powerpc64=	ALTIVEC
OPTIONS_SUB=	yes

AOM_DESC=	AV1 video encoding/decoding via libaom
ASS_DESC=	ASS/SSA subtitle rendering
CHROMECAST_DESC=Streaming to Chromecast devices
DAV1D_DESC=	AV1 video decoding via libdav1d
DVDREAD_DESC=	DVD Playback support
DVDNAV_DESC=	DVD menu navigation
FLUID_DESC=	Fluidsynth MIDI support
FREERDP_DESC=	RDP support
GME_DESC=	Game Music Emu (libgme) support
GOOM_DESC=	Goom visualisation plugin
HARFBUZZ_DESC=	OpenType text shaping engine
KATE_DESC=	Kate codec support
LIBPLACEBO_DESC=HDR tonemapping support through libplacebo
LIBSSH2_DESC=	SCP/SFTP support via libssh2
MFX_DESC=	Intel MediaSDK (aka Quick Sync Video)
OGGSPOTS_DESC=	Experimental OggSpots codec
REALRTSP_DESC=	Real RTSP access module
RUNROOT_DESC=	Enable running as root
SIDPLAY_DESC=	C64 sid demux support
SKINS_DESC=	Skins interface module
STREAM_DESC=	stream output
TAGLIB_DESC=	ID3 tag and Ogg comment support
VCD_DESC=	Audio/Video CD support
ZVBI_DESC=	VBI decoding support

A52_CONFIGURE_ENABLE=	a52
A52_CONFIGURE_ON=	--with-a52=${LOCALBASE}
A52_LIB_DEPENDS=	liba52.so:audio/liba52

AALIB_LIB_DEPENDS=	libaa.so:graphics/aalib
AALIB_CONFIGURE_ENABLE=	aa

ASS_LIB_DEPENDS=	libass.so:multimedia/libass
ASS_CONFIGURE_ENABLE=	libass

ALTIVEC_CONFIGURE_ENABLE=	altivec

AOM_LIB_DEPENDS=	libaom.so:multimedia/aom
AOM_CONFIGURE_ENABLE=	aom

AVAHI_LIB_DEPENDS=	libavahi-common.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi

CACA_LIB_DEPENDS=	libcaca.so:graphics/libcaca
CACA_CONFIGURE_ENABLE=	caca

CHROMECAST_LIB_DEPENDS=	libprotobuf-lite.so:devel/protobuf
CHROMECAST_CONFIGURE_ENABLE=	chromecast

DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_CONFIGURE_ENABLE=	dav1d

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_ENABLE=	dbus

DCA_LIB_DEPENDS=	libdca.so:multimedia/libdca
DCA_CONFIGURE_ENABLE=	dca

DVDREAD_LIB_DEPENDS=	libdvdread.so:multimedia/libdvdread
DVDREAD_CONFIGURE_ENABLE=	dvdread

DVDNAV_LIB_DEPENDS=	libdvdnav.so:multimedia/libdvdnav
DVDNAV_CONFIGURE_ENABLE=dvdnav

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FAAD_CONFIGURE_ENABLE=	faad
FAAD_CONFIGURE_ENV=	CPPFLAGS_faad="-I${LOCALBASE}/include" \
			LIBS_faad="-L${LOCALBASE}/lib"

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ENABLE=	flac

FLUID_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUID_CONFIGURE_ENABLE=	fluidsynth

FREERDP_LIB_DEPENDS=	libfreerdp2.so:net/freerdp
FREERDP_CONFIGURE_ENABLE=	freerdp
FREERDP_CONFIGURE_ENV=	FREERDP_CFLAGS="-I${LOCALBASE}/include/freerdp2 \
					-I${LOCALBASE}/include/winpr2" \
			FREERDP_LIBS="-L${LOCALBASE}/lib"

FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=	fribidi

GME_LIB_DEPENDS=	libgme.so:audio/libgme
GME_CONFIGURE_ENABLE=	gme
GME_CONFIGURE_ENV=	LIBS_gme="-L${LOCALBASE}/lib -lgme"

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ENABLE=gnutls

GOOM_LIB_DEPENDS=	libgoom2.so:graphics/goom
GOOM_CONFIGURE_ENABLE=	goom

HARFBUZZ_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
HARFBUZZ_CONFIGURE_ENABLE=	harfbuzz

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack

JPEG_USES=		jpeg
JPEG_CONFIGURE_ENABLE=	jpeg

KATE_LIB_DEPENDS=	libkate.so:multimedia/libkate
KATE_CONFIGURE_ENABLE=	kate

LIBBLURAY_LIB_DEPENDS=	libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	bluray

LIBPLACEBO_LIB_DEPENDS=	libplacebo.so:graphics/libplacebo
LIBPLACEBO_CONFIGURE_ENABLE=	libplacebo

LIBRSVG2_USE=			GNOME=librsvg2,cairo
LIBRSVG2_CONFIGURE_ENABLE=	svg

LIBSSH2_LIB_DEPENDS=	libssh2.so:security/libssh2
LIBSSH2_CONFIGURE_ENABLE=	sftp

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_ENABLE=	lirc
LIRC_CONFIGURE_ENV=	LIBS_lirc="-L${LOCALBASE}/lib -llirc_client"

LIVEMEDIA_LIB_DEPENDS=	libliveMedia.so:net/liveMedia
LIVEMEDIA_CONFIGURE_ENABLE=	live555
LIVEMEDIA_CONFIGURE_ENV= \
	LIVE555_CFLAGS="-I${LOCALBASE}/include/liveMedia \
			-I${LOCALBASE}/include/UsageEnvironment \
			-I${LOCALBASE}/include/groupsock \
			-I${LOCALBASE}/include/BasicUsageEnvironment" \
	LIVE555_LIBS="-L${LOCALBASE}/lib -lliveMedia \
			-lgroupsock -lBasicUsageEnvironment \
			-lUsageEnvironment"

LUA_USES=		lua
LUA_CONFIGURE_ENABLE=	lua
LUA_CONFIGURE_ON=	LUAC=${LUAC_CMD} LUA_CFLAGS="-I${LUA_INCDIR}" \
			LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"

MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_CONFIGURE_ENABLE=	mad
MAD_CONFIGURE_ON=	--with-mad=${LOCALBASE}

MFX_LIB_DEPENDS=	libmfx.so:multimedia/intel-media-sdk
MFX_CONFIGURE_ENABLE=	mfx

MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	mod

MPEG2_LIB_DEPENDS=	libmpeg2.so:multimedia/libmpeg2
MPEG2_CONFIGURE_ENABLE=	libmpeg2

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_CONFIGURE_ENABLE=	mtp

MUSEPACK_LIB_DEPENDS=	libmpcdec.so:audio/musepack
MUSEPACK_CONFIGURE_ENABLE=	mpc
MUSEPACK_CONFIGURE_ENV=		LIBS_mpc="-L${LOCALBASE}/lib -lmpcdec"

NCURSES_USES=			ncurses
NCURSES_CONFIGURE_ENV=		NCURSES_CFLAGS="-I${NCURSESINC}" \
				NCURSES_LIBS="-L${NCURSESLIB} -lncursesw"
NCURSES_CONFIGURE_ENABLE=	ncurses

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs
NFS_CONFIGURE_ENABLE=	nfs

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_USE=		GNOME=gtk30,cairo
NOTIFY_CONFIGURE_ENABLE=notify

OGG_LIB_DEPENDS=	libogg.so:audio/libogg
OGG_CONFIGURE_ENABLE=	ogg

OGGSPOTS_CONFIGURE_ENABLE=	oggspots
OGGSPOTS_IMPLIES=	OGG

OPTIMIZED_CFLAGS_CONFIGURE_ENABLE=	optimizations

OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CONFIGURE_ENABLE=	opus

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ENABLE=	png

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse

QT5_USES=	qt:5
QT5_USE=	QT=gui,core,svg,widgets,x11extras,buildtools_build
QT5_CONFIGURE_ENABLE=	qt
QT5_IMPLIES=	X11

REALRTSP_CONFIGURE_ENABLE=	realrtsp

RUNROOT_CONFIGURE_ENABLE=	run-as-root

SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=	samplerate

SCHROEDINGER_LIB_DEPENDS=	libschroedinger-1.0.so:multimedia/schroedinger
SCHROEDINGER_CONFIGURE_ENABLE=	schroedinger

SDL_USES=		sdl
SDL_USE=		SDL=image
SDL_CONFIGURE_ENABLE=	sdl-image

SIDPLAY_LIB_DEPENDS=	libsidplay2.so:audio/libsidplay2
SIDPLAY_LDFLAGS=	-L${LOCALBASE}/lib/sidplay/builders
SIDPLAY_CONFIGURE_ENABLE=	sid
CONFIGURE_ARGS+=	--disable-sid

SKINS_USE=		XORG=xext,xinerama,xpm
SKINS_LIB_DEPENDS=	libminizip.so:archivers/minizip \
			libtar.so:devel/libtar
SKINS_CONFIGURE_ENABLE=	skins2 libtar
SKINS_IMPLIES=		QT5

SHOUTCAST_LIB_DEPENDS=	libshout.so:audio/libshout
SHOUTCAST_CONFIGURE_ENABLE=	shout

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	sndio

SMB_USES=		samba:lib
SMB_CONFIGURE_ENABLE=	smbclient

STREAM_CONFIGURE_ENABLE=sout

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
SPEEX_CONFIGURE_ENABLE=	speex

TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CONFIGURE_ENABLE=taglib

THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CONFIGURE_ENABLE=theora

TWOLAME_LIB_DEPENDS=		libtwolame.so:audio/twolame
TWOLAME_CONFIGURE_ENABLE=	twolame

UPNP_LIB_DEPENDS=	libupnp.so:devel/upnp
UPNP_CONFIGURE_ENABLE=	upnp

V4L_BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CONFIGURE_ENABLE=	v4l2

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_CONFIGURE_ENABLE=	libva

VCD_LIB_DEPENDS=	libcddb.so:audio/libcddb
VCD_CONFIGURE_ENABLE=	vcd libcddb

VDPAU_LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau
VDPAU_CONFIGURE_ENABLE=	vdpau
VDPAU_IMPLIES=		X11

VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_CONFIGURE_ENABLE=	vpx

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_ENABLE=vorbis

WAYLAND_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=	wayland

X11_USE=		GL=gl XORG=xcb,xorgproto,sm,ice,x11
X11_USES=		gl xorg
X11_LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms
X11_CONFIGURE_ENABLE=	xcb xvideo
X11_CONFIGURE_WITH=	x

X264_LIB_DEPENDS=	libx264.so:multimedia/libx264
X264_CONFIGURE_ENABLE=	x264

X265_LIB_DEPENDS=	libx265.so:multimedia/x265
X265_CONFIGURE_ENABLE=	x265

ZVBI_LIB_DEPENDS=	libzvbi.so:devel/libzvbi
ZVBI_CONFIGURE_ENABLE=	zvbi

PORTDATA=	*
PORTDOCS=	*

WITH_CDROM_DEVICE?=/dev/cd0
WITH_DVD_DEVICE?=/dev/cd0

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
INSTALLS_ICONS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '\|LIBS|s|-lrt||' \
		-e 's|LIBS="-llirc_client|LIBS="$$LIBS_lirc|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/dev/cdrom|${WITH_CDROM_DEVICE}|g' \
		-e 's|/dev/dvd|${WITH_DVD_DEVICE}|g' \
		${WRKSRC}/src/libvlc-module.c
	@${RM} -r ${WRKSRC}/modules/access/v4l2/linux
# XXX FreeBSD doesn't have strerror_l() - use the android version of error.c
	@${CP} ${WRKSRC}/src/android/error.c ${WRKSRC}/src/posix

post-install:
	@(cd ${STAGEDIR}${PREFIX} && ${FIND} -s lib/vlc -not -name '*.la' \
		-type f -o -type l >> ${TMPPLIST})
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/vlc/plugins/*/*.so
	# plugin cache becomes stale after strip. Regenerate it:
	${WRKSRC}/bin/vlc-cache-gen ${STAGEDIR}${PREFIX}/lib/vlc/plugins

.include <bsd.port.mk>
