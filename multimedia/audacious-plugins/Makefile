# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD$

PORTNAME=	audacious-plugins
PORTVERSION=	4.1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Plugins needed for audacious

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libmpg123.so:audio/mpg123

FLAVORS=	qt5 gtk2
FLAVOR?=	${FLAVORS:[1]}

USES=		compiler:c++11-lib gettext-tools gmake gnome iconv \
		localbase pkgconfig tar:bzip2 xorg
USE_GNOME=	glib20 libxml2 gdkpixbuf2
USE_XORG=	x11

qt5_CONFLICTS_INSTALL=	audacious-plugins-gtk2
qt5_RUN_DEPENDS=	audacious:multimedia/audacious@qt5
qt5_BUILD_DEPENDS=	audacious:multimedia/audacious@qt5

gtk2_PKGNAMESUFFIX=	-gtk2
gtk2_CONFLICTS_INSTALL=	audacious-plugins
gtk2_RUN_DEPENDS=	audacious:multimedia/audacious@gtk2
gtk2_BUILD_DEPENDS=	audacious:multimedia/audacious@gtk2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-console --disable-soxr \
		--enable-gnomeshortcuts

.if ${FLAVOR} == qt5
CONFIGURE_ARGS+=	--enable-qt --disable-gtk
USES+=			qt:5
USE_QT=			core gui widgets
PLIST_SUB=		QT5="" GTK2="@comment "
.elif ${FLAVOR} == gtk2
CONFIGURE_ARGS+=	--disable-qt --enable-gtk --enable-hotkey
USE_GNOME+=		gtk20 cairo
PLIST_SUB=		QT5="@comment " GTK2=""
.endif

OPTIONS_DEFINE=	AAC ADPLUG AMIDI BS2B CDDA CUE FFMPEG FLAC LAME LIRC \
		MMS MODPLUG MPRIS NEON NLS NOTIFY OPENMPT SAMPLERATE \
		SCROBBLER SID SNDFILE SPEEDPITCH VORBIS WAVPACK
OPTIONS_MULTI=		OUTPUT
OPTIONS_MULTI_OUTPUT=	ALSA FILEWRITER JACK OSS PULSEAUDIO SDL SNDIO
OPTIONS_DEFAULT=	AAC ADPLUG CDDA CUE FILEWRITER FFMPEG FLAC MMS MPRIS \
			NEON NLS NOTIFY OPENMPT OSS PULSEAUDIO SCROBBLER \
			SID VORBIS WAVPACK
OPTIONS_SUB=	yes

.if ${FLAVOR} == gtk2
OPTIONS_DEFINE+=	AOSD OPENGL
OPTIONS_DEFAULT+=	AOSD
.endif

ADPLUG_DESC=	ADPLUG plugin
AMIDI_DESC=	Amidi decoder
AOSD_DESC=	Audacious OSD
BS2B_DESC=	BS2B effect
FILEWRITER_DESC=File writer
MPRIS_DESC=	NPRIS plugin
NEON_DESC=	Neon plugin
OPENMPT_DESC=	OpenMPT plugin
SCROBBLER_DESC=	Scrobbler decoder
SID_DESC=	Sound chip emulator of Commodore
SPEEDPITCH_DESC=Speed and Pitch plugin

AAC_LIB_DEPENDS=	libfaad.so:audio/faad
AAC_CONFIGURE_ENABLE=	aac
ADPLUG_LIB_DEPENDS=	libadplug.so:audio/libadplug \
			libbinio.so:devel/libbinio
ADPLUG_CONFIGURE_ENABLE=	adplug

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa
AMIDI_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
AMIDI_CONFIGURE_ENABLE=	amidiplug
AOSD_USES=		xorg
AOSD_USE=		gnome=pango xorg=xrender
AOSD_LIB_DEPENDS=	libXcomposite.so:x11/libXcomposite
AOSD_CONFIGURE_ENABLE=	aosd
BS2B_LIB_DEPENDS=	libbs2b.so:audio/libbs2b
BS2B_CONFIGURE_ENABLE=	bs2b
CDDA_LIB_DEPENDS=	libcdio_cdda.so:sysutils/libcdio-paranoia \
			libcddb.so:audio/libcddb \
			libcdio.so:sysutils/libcdio
CDDA_CONFIGURE_ENABLE=	cdaudio
CUE_LIB_DEPENDS=	libcue.so:textproc/libcue
CUE_CONFIGURE_ENABLE=	cue
FILEWRITER_CONFIGURE_ENABLE=	filewriter
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	ffmpeg=ffmpeg
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ENABLE=	flac
JACK_LIB_DEPENDS=	libjack.so:audio/jack \
			libsamplerate.so:audio/libsamplerate
JACK_CONFIGURE_ENABLE=	jack
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_ENABLE=	filewriter_mp3
LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_ENABLE=	lirc
MMS_LIB_DEPENDS=	libmms.so:net/libmms
MMS_CONFIGURE_ENABLE=	mms
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	modplug
MPRIS_CONFIGURE_ENABLE=	mpris2
NEON_LIB_DEPENDS=	libneon.so:www/neon
NEON_CONFIGURE_ENABLE=	neon
NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=notify
OPENGL_USES=		gl xorg
OPENGL_USE=		xorg=x11 gl=gl
OPENGL_CONFIGURE_ENABLE=glspectrum
OPENMPT_LIB_DEPENDS=	libopenmpt.so:audio/libopenmpt
OPENMPT_CONFIGURE_ENABLE=	openmpt
OSS_CONFIGURE_ENABLE=	oss4
PULSEAUDIO_LIB_DEPENDS=	libpulse-mainloop-glib.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=	resample
SCROBBLER_LIB_DEPENDS=	libcurl.so:ftp/curl
SCROBBLER_CONFIGURE_ENABLE=	scrobbler2
SDL_CONFIGURE_ON=	--enable-sdlout --with-libsdl=2
SDL_CONFIGURE_OFF=	--disable-sdlout
SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SID_LIB_DEPENDS=	libsidplayfp.so:audio/libsidplayfp
SID_CONFIGURE_ENABLE=	sid
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_ENABLE=	sndfile
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	sndio
SPEEDPITCH_CONFIGURE_ENABLE=	speedpitch
SPEEDPITCH_IMPLIES=	SAMPLERATE
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_CONFIGURE_ENABLE=vorbis
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_ENABLE=	wavpack

post-patch:
	@${REINPLACE_CMD} -e 's| $${MFLAGS}||g' \
		${WRKSRC}/buildsys.mk.in
	@${FIND} ${WRKSRC} -type f -name 'Makefile' \
		| ${XARGS} ${REINPLACE_CMD} -e 's| -Wno-bool-operation||'

post-patch-NLS-off:
	${REINPLACE_CMD} -e 's,po,,' ${WRKSRC}/Makefile

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/lib/audacious/ -name "*.so" \
		-exec ${STRIP_CMD} {} \;

post-install-ADPLUG-on:
	${INSTALL_LIB} ${WRKSRC}/src/adplug/adplug.so \
		${STAGEDIR}${PREFIX}/lib/audacious/Input

post-install-OPENMPT-on:
	${INSTALL_LIB} ${WRKSRC}/src/openmpt/openmpt.so \
		${STAGEDIR}${PREFIX}/lib/audacious/Input

.include <bsd.port.mk>
