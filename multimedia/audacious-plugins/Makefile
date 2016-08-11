# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD$

PORTNAME=	audacious-plugins
PORTVERSION=	3.7.2
PORTREVISION=	2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Plugins needed for audacious

LICENSE=	GPLv3

BUILD_DEPENDS=	audacious:multimedia/audacious

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib gettext-tools gmake pkgconfig tar:bzip2
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
USE_GNOME=	glib20 libxml2

CONFIGURE_ARGS+=--disable-console --disable-sndio --disable-soxr

OPTIONS_MULTI=	TOOLKITS
OPTIONS_MULTI_TOOLKITS=	GTK2 QT5
OPTIONS_EXCLUDE=	QT5
OPTIONS_DEFINE=	AAC ALSA AMIDI AOSD AOSDXCOMP BS2B CDDA CUE DBUS FFMPEG \
		FLAC JACK LAME LIRC MP3 MMS MODPLUG MPRIS NEON NLS NOTIFY \
		OPENGL OSS PULSEAUDIO SAMPLERATE SCROBBLER SDL SID SNDFILE \
		SPEEDPITCH VORBIS WAVPACK
OPTIONS_DEFAULT=	AAC AOSD AOSDXCOMP CDDA CUE DBUS FFMPEG FLAC GTK2 \
		MP3 MMS NEON NLS NOTIFY OSS SCROBBLER VORBIS WAVPACK

AAC_LIB_DEPENDS=	libfaad.so:audio/faad
AAC_CONFIGURE_OFF=	--disable-aac
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=	--disable-alsa
AMIDI_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
AMIDI_CONFIGURE_OFF=	--disable-amidiplug
AOSD_USE=	gnome=pango
AOSD_CONFIGURE_ENABLE=	aosd
AOSD_IMPLIES=	GTK2
AOSDXCOMP_LIB_DEPENDS=	libXcomposite.so:x11/libXcomposite
AOSDXCOMP_CONFIGURE_ENABLE=	aosd-xcomp
AOSDXCOMP_IMPLIES=	AOSD
BS2B_LIB_DEPENDS=	libbs2b.so:audio/libbs2b
BS2B_CONFIGURE_OFF=	--disable-bs2b
CDDA_LIB_DEPENDS=	libcdio_cdda.so:sysutils/libcdio-paranoia \
	libcddb.so:audio/libcddb
CDDA_CONFIGURE_OFF=	--disable-cdaudio
CUE_LIB_DEPENDS=	libcue.so:textproc/libcue
CUE_CONFIGURE_OFF=	--disable-cue
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
DBUS_CONFIGURE_ENABLE=	gnomeshortcuts
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	ffmpeg=ffmpeg
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ON=	--enable-flacng --enable-filewriter_flac
FLAC_CONFIGURE_OFF=	--disable-flacng --disable-filewriter_flac
GTK2_USE=	gnome=gtk20
GTK2_CONFIGURE_ON=	--enable-gtk --enable-filewriter --enable-hotkey
GTK2_CONFIGURE_OFF=	--disable-gtk --disable-filewriter --disable-hotkey
GTK2_IMPLIES=	DBUS
JACK_LIB_DEPENDS=	libjack.so:audio/jack \
	libsamplerate.so:audio/libsamplerate
JACK_CONFIGURE_OFF=	--disable-jack
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_OFF=	--disable-filewriter_mp3
LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_OFF=	--disable-lirc
MP3_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MP3_CONFIGURE_OFF=	--disable-mp3
MMS_LIB_DEPENDS=	libmms.so:net/libmms
MMS_CONFIGURE_OFF=	--disable-mms
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_OFF=	--disable-modplug
MPRIS_CONFIGURE_ENABLE=	mpris2
MPRIS_IMPLIES=	DBUS
NEON_LIB_DEPENDS=	libneon.so:www/neon
NEON_CONFIGURE_OFF=	--disable-neon
NLS_USES=	gettext-runtime
NLS_CONFIGURE_OFF=	--disable-nls
NLS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-Makefile
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=	notify
NOTIFY_IMPLIES=	GTK2
OPENGL_USE=	xorg=x11 gl=gl
OPENGL_CONFIGURE_ENABLE=	glspectrum
OPENGL_IMPLIES=	GTK2
OSS_CONFIGURE_ENABLE=	oss4
PULSEAUDIO_LIB_DEPENDS=	libpulse-mainloop-glib.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-pulse
PULSEAUDIO_IMPLIES=	DBUS
QT5_USE=	qt5=multimedia,opengl
QT5_CONFIGURE_ENABLE=	qt
QT5_CONFIGURE_OFF=	--disable-qtaudio
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_OFF=	--disable-resample
SCROBBLER_LIB_DEPENDS=	libcurl.so:ftp/curl
SCROBBLER_CONFIGURE_OFF=	--disable-scrobbler2
SCROBBLER_IMPLIES=	GTK2
SDL_LIB_DEPENDS=	libSDL2.so:devel/sdl20
SDL_CONFIGURE_ON=	--enable-sdlout --with-libsdl=2
SDL_CONFIGURE_OFF=	--disable-sdlout
SID_LIB_DEPENDS=	libsidplayfp.so:audio/libsidplayfp
SID_CONFIGURE_OFF=	--disable-sid
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_OFF=	--disable-sndfile
SPEEDPITCH_CONFIGURE_OFF=	--disable-speedpitch
SPEEDPITCH_IMPLIES=	SAMPLERATE
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_ENABLE=	vorbis
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_OFF=	--disable-wavpack
OPTIONS_SUB=	yes

AMIDI_DESC=	Amidi decoder
AOSD_DESC=	Audacious OSD
AOSDXCOMP_DESC=	Audacious OSD X Composite
BS2B_DESC=	BS2B effect
SCROBBLER_DESC=	Scrobbler decoder
SID_DESC=	Sound chip emulator of Commodore
NEON_DESC=	Neon plugin
SPEEDPITCH_DESC=Speed and Pitch plugin
MPRIS_DESC=	NPRIS plugin

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/lib/audacious/ -name "*.so" \
		-exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
