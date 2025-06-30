PORTNAME=	audacious-plugins
DISTVERSION=	4.4.2
PORTREVISION=	4
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Plugins needed for audacious
WWW=		https://audacious-media-player.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

FLAVORS=	qt6 qt5 gtk2 gtk3
FLAVOR?=	${FLAVORS:[1]}

gtk2_PKGNAMESUFFIX=	-gtk2
gtk2_BUILD_DEPENDS=	audacious:multimedia/audacious@gtk2
gtk2_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
gtk2_RUN_DEPENDS=	audacious:multimedia/audacious@gtk2
gtk2_CONFLICTS_INSTALL=	audacious-plugins audacious-plugins-gtk3 \
			audacious-plugins-qt6

gtk3_PKGNAMESUFFIX=	-gtk3
gtk3_BUILD_DEPENDS=	audacious:multimedia/audacious@gtk3
gtk3_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
gtk3_RUN_DEPENDS=	audacious:multimedia/audacious@gtk3
gtk3_CONFLICTS_INSTALL=	audacious-plugins audacious-plugins-gtk2 \
			audacious-plugins-qt6

qt5_PKGNAMESUFFIX=	-qt5
qt5_BUILD_DEPENDS=	audacious:multimedia/audacious@qt5
qt5_RUN_DEPENDS=	audacious:multimedia/audacious@qt5
qt5_CONFLICTS_INSTALL=	audacious-plugins-gtk2 audacious-plugins-gtk3 \
			audacious-plugins-qt6

qt6_BUILD_DEPENDS=	audacious:multimedia/audacious@qt6
qt6_RUN_DEPENDS=	audacious:multimedia/audacious@qt6
qt6_CONFLICTS_INSTALL=	audacious-plugins audacious-plugins-gtk2 \
			audacious-plugins-gtk3

USES=		compiler:c++11-lib gettext-tools gmake gnome iconv localbase \
		meson pkgconfig tar:bzip2 xorg
USE_GNOME=	gdkpixbuf glib20 libxml2
USE_XORG=	x11

CONFIGURE_ENV=	LIBRARY_PATH="${LOCALBASE}/lib"
MESON_ARGS=	-Dcoreaudio=false \
		-Dmms=false \
		-Dcdaudio-cddb=false
MAKE_ENV=	LIBRARY_PATH="${LOCALBASE}/lib"

.if ${FLAVOR} == qt5
MESON_ARGS+=	-Dgtk2=false \
		-Dgtk=false \
		-Dqt5=true \
		-Dqt=true
USES+=		qt:5
USE_QT=		core gui multimedia network svg widgets x11extras
PLIST_SUB=	GTK="@comment " \
		QT5="" \
		QT=""
.elif ${FLAVOR} == qt6
MESON_ARGS+=	-Dgtk2=false \
		-Dgtk=false \
		-Dqt5=false \
		-Dqt=true
USES+=		qt:6
USE_QT=		base multimedia svg
PLIST_SUB=	GTK="@comment " \
		QT5="@comment " \
		QT=""
.elif ${FLAVOR} == gtk2
LIB_DEPENDS+=	libjson-glib-1.0.so:devel/json-glib
MESON_ARGS+=	-Dgtk2=true \
		-Dgtk=true \
		-Dhotkey=true \
		-Dqt5=false \
		-Dqt=false
USE_GNOME+=	cairo gtk20
PLIST_SUB=	GTK="" \
		QT6="@comment " \
		QT="@comment "
.elif ${FLAVOR} == gtk3
LIB_DEPENDS+=	libjson-glib-1.0.so:devel/json-glib
MESON_ARGS+=	-Dgtk2=false \
		-Dgtk=true \
		-Dhotkey=true \
		-Dqt5=false \
		-Dqt=false
USE_GNOME+=	cairo gtk30
PLIST_SUB=	GTK="" \
		QT6="@comment " \
		QT="@comment "
.endif

OPTIONS_DEFINE=		AAC ADPLUG AMIDI BS2B CDDA CONSOLE CUE FFMPEG FLAC LAME \
			LIRC MODPLUG MPG123 MPRIS NEON NLS NOTIFY OPENGL \
			OPENMPT OPUS SAMPLERATE SCROBBLER SID SNDFILE SOXR \
			SPEEDPITCH VORBIS WAVPACK
OPTIONS_DEFAULT=	AAC ADPLUG AMIDI CDDA CUE FFMPEG FILEWRITER FLAC JACK MPG123 \
			MPRIS NEON NLS NOTIFY OPENMPT OPUS OSS PIPEWIRE PULSEAUDIO \
			SCROBBLER SID VORBIS WAVPACK
OPTIONS_MULTI=		OUTPUT
OPTIONS_MULTI_OUTPUT=	ALSA FILEWRITER JACK OSS PIPEWIRE PULSEAUDIO SDL SNDIO
OPTIONS_SUB=		yes

.if ${FLAVOR} == gtk2 || ${FLAVOR} == gtk3
OPTIONS_DEFINE+=	AOSD
OPTIONS_DEFAULT+=	AOSD
.endif

ADPLUG_DESC=		ADPLUG plugin
AMIDI_DESC=		Amidi decoder
AOSD_DESC=		Audacious OSD
BS2B_DESC=		BS2B effect
CONSOLE_DESC=		Game Console Music Emulation
FILEWRITER_DESC=	File writer
MPRIS_DESC=		NPRIS plugin
NEON_DESC=		Neon plugin
OPENMPT_DESC=		OpenMPT plugin
SCROBBLER_DESC=		Scrobbler decoder
SID_DESC=		Sound chip emulator of Commodore
SPEEDPITCH_DESC=	Speed and Pitch plugin

AAC_LIB_DEPENDS=	libfaad.so:audio/faad
AAC_MESON_TRUE=		aac

ADPLUG_LIB_DEPENDS=	libadplug.so:audio/libadplug \
			libbinio.so:devel/libbinio
ADPLUG_MESON_TRUE=	adplug

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MESON_TRUE=	alsa

AMIDI_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
AMIDI_MESON_TRUE=	amidiplug

AOSD_LIB_DEPENDS=	libXcomposite.so:x11/libXcomposite
AOSD_USES=		xorg
AOSD_USE=		GNOME=pango \
			XORG=xrender
AOSD_MESON_TRUE=	aosd

BS2B_LIB_DEPENDS=	libbs2b.so:audio/libbs2b
BS2B_MESON_TRUE=	bs2b

CDDA_LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
			libcdio_cdda.so:sysutils/libcdio-paranoia
CDDA_MESON_TRUE=	cdaudio

CONSOLE_MESON_TRUE=	console

CUE_LIB_DEPENDS=	libcue.so:textproc/libcue
CUE_MESON_TRUE=		cue

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_MESON_TRUE=	ffaudio

FILEWRITER_MESON_TRUE=	filewriter

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_MESON_TRUE=	flac

JACK_LIB_DEPENDS=	libjack.so:audio/jack \
			libsamplerate.so:audio/libsamplerate
JACK_MESON_TRUE=	jack

LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_MESON_TRUE=	lirc

MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_MESON_TRUE=	modplug

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MPG123_MESON_TRUE=	mpg123

MPRIS_MESON_TRUE=	mpris2

NEON_LIB_DEPENDS=	libneon.so:www/neon
NEON_MESON_TRUE=	neon

NLS_USES=		gettext-runtime

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MESON_TRUE=	notify

OPENGL_USES=		gl
OPENGL_USE=		GL=gl
.if ${FLAVOR} == qt5
OPENGL_USE+=		QT=opengl
.endif
OPENGL_MESON_TRUE=	gl-spectrum

OPENMPT_LIB_DEPENDS=	libopenmpt.so:audio/libopenmpt
OPENMPT_MESON_TRUE=	openmpt

OPUS_LIB_DEPENDS=	libopus.so:audio/opus \
			libopusfile.so:audio/opusfile
OPUS_MESON_TRUE=	opus

OSS_MESON_TRUE=		oss

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_MESON_TRUE=	pipewire

PULSEAUDIO_LIB_DEPENDS=	libpulse-mainloop-glib.so:audio/pulseaudio
PULSEAUDIO_MESON_TRUE=	pulse

SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_MESON_TRUE=	resample

SCROBBLER_LIB_DEPENDS=	libcurl.so:ftp/curl
SCROBBLER_MESON_TRUE=	scrobbler2

SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_MESON_TRUE=		sdlout

SID_LIB_DEPENDS=	libsidplayfp.so:audio/libsidplayfp
SID_MESON_TRUE=		sid

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_MESON_TRUE=	sndfile

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_MESON_TRUE=	sndio

SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SOXR_MESON_TRUE=	soxr

SPEEDPITCH_IMPLIES=	SAMPLERATE
SPEEDPITCH_MESON_TRUE=	speedpitch

VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis
VORBIS_MESON_TRUE=	vorbis

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_MESON_TRUE=	wavpack

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFILEWRITER}
.if ${PORT_OPTIONS:MFLAC}
MESON_ARGS+=	-Dfilewriter-flac=true
.else
MESON_ARGS+=	-Dfilewriter-flac=false
.endif
.if ${PORT_OPTIONS:MLAME}
MESON_ARGS+=	-Dfilewriter-mp3=true
.else
MESON_ARGS+=	-Dfilewriter-mp3=false
.endif
.if ${PORT_OPTIONS:MVORBIS}
MESON_ARGS+=	-Dfilewriter-ogg=true
.else
MESON_ARGS+=	-Dfilewriter-ogg=false
.endif
.else
MESON_ARGS+=	-Dfilewriter-flac=false \
		-Dfilewriter-mp3=false \
		-Dfilewriter-ogg=false
.endif

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
