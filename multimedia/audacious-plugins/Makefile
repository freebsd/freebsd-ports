# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD$

PORTNAME=	audacious-plugins
PORTVERSION=	3.6.2
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Plugins needed for audacious

LICENSE=	GPLv3

BUILD_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig tar:bzip2 compiler:c++11-lib
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
USE_GNOME=	glib20
WANT_SDL=	yes

OPTIONS_DEFINE=	DBUS OSS4 SDLOUT ALSA CUE MP3 STATUSICON AOSD AOSDXCOMP \
		ADPLUG VORBIS FLAC WAVPACK AAC SNDFILE MODPLUG JACK \
		CDAUDIO SCROBBLER MMS NLS RESAMPLE AMIDI GLSPECTRUM \
		NOTIFY BS2B FFAUDIO PULSE NEON SPEEDPITCH LIRC MP3FILEWRITER \
		SID MPRIS
OPTIONS_DEFAULT=DBUS CUE MP3 STATUSICON AOSD AOSDXCOMP AAC CDAUDIO \
		SCROBBLER NEON NLS OSS4 FFAUDIO

ADPLUG_DESC=	ADPLUG decoder
AMIDI_DESC=	Amidi decoder
AOSD_DESC=	Audacious OSD
AOSDXCOMP_DESC=	Audacious OSD X Composite
BS2B_DESC=	BS2B effect
CDAUDIO_DESC=	CD audio input
FFAUDIO_DESC=	FFAudio decoder
GLSPECTRUM_DESC=OpenGL Spectrum Analyzer
OSS4_DESC=	Open Sound System 4
PULSE_DESC=	PulseAudio support
RESAMPLE_DESC=	Resample effect
SCROBBLER_DESC=	Scrobbler decoder
SDLOUT_DESC=	SDL Output
SID_DESC=	SID decoder
STATUSICON_DESC=X11 Status icon
NEON_DESC=	Neon plugin
SPEEDPITCH_DESC=Speed and Pitch plugin
LIRC_DESC=	LIRC plugin
MP3FILEWRITER=	Filewriter plugin for MP3
MPRIS_DESC=	NPRIS plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDLOUT}
PLIST_SUB+=	SDL=""
USE_SDL=	sdl
CONFIGURE_ARGS+=--enable-sdlout
.else
PLIST_SUB+=	SDL="@comment "
CONFIGURE_ARGS+=--disable-sdlout
.endif

.if ${PORT_OPTIONS:MNOTIFY} || exists(${LOCALBASE}/lib/libnotify.so)
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-notify
PLIST_SUB+=	NOTIFY=""
.else
PLIST_SUB+=	NOTIFY="@comment "
CONFIGURE_ARGS+=--disable-notify
.endif

.if ${PORT_OPTIONS:MGLSPECTRUM}
USE_GL=		gl
CONFIGURE_ARGS+=--enable-glspectrum
PLIST_SUB+=	GLSPECTRUM=""
.else
CONFIGURE_ARGS+=--disable-glspectrum
PLIST_SUB+=	GLSPECTRUM="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-gnomeshortcuts
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-gnomeshortcuts
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MCUE}
LIB_DEPENDS+=	libcue.so:${PORTSDIR}/textproc/libcue
CONFIGURE_ARGS+=--enable-cue
PLIST_SUB+=	CUEPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-cue
PLIST_SUB+=	CUEPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MMP3}
LIB_DEPENDS+=	libmpg123.so:${PORTSDIR}/audio/mpg123
CONFIGURE_ARGS+=--enable-mp3 --enable-filewriter_mp3
PLIST_SUB+=	MP3PLUGIN=""
.if ${PORT_OPTIONS:MMP3FILEWRITER}
LIB_DEPENDS+=	libmp3lame.so:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=--enable-filewriter_mp3
.else
CONFIGURE_ARGS+=--disable-filewriter_mp3
.endif
.else
CONFIGURE_ARGS+=--disable-mp3 --disable-filewriter_mp3
PLIST_SUB+=	MP3PLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MSTATUSICON}
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=--enable-statusicon
PLIST_SUB+=	STATUSICONPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-statusicon
PLIST_SUB+=	STATUSICONPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MAOSD}
USE_GNOME+=	pango
CONFIGURE_ARGS+=--enable-aosd
PLIST_SUB+=	AOSDPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-aosd
PLIST_SUB+=	AOSDPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MAOSDXCOMP}
LIB_DEPENDS+=	libXcomposite.so:${PORTSDIR}/x11/libXcomposite
CONFIGURE_ARGS+=--enable-aosd-xcomp
PLIST_SUB+=	AOSDXCOMPPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-aosd-xcomp
PLIST_SUB+=	AOSDXCOMPPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MADPLUG}
LIB_DEPENDS+=	libbinio.so:${PORTSDIR}/devel/libbinio
CONFIGURE_ARGS+=--enable-adplug
PLIST_SUB+=	ADPLUGPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-adplug
PLIST_SUB+=	ADPLUGPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
PLIST_SUB+=	VORBISPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-vorbis
PLIST_SUB+=	VORBISPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	libFLAC.so:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--enable-flacng --enable-filewriter_flac
PLIST_SUB+=	FLACPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-flacng --disable-filewriter_flac
PLIST_SUB+=	FLACPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MFFAUDIO}
LIB_DEPENDS+=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=--with-ffmpeg=ffmpeg
PLIST_SUB+=	FFAUDIOPLUGIN=""
.else
CONFIGURE_ARGS+=--with-ffmpeg=none
PLIST_SUB+=	FFAUDIOPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	libwavpack.so:${PORTSDIR}/audio/wavpack
CONFIGURE_ARGS+=--enable-wavpack
PLIST_SUB+=	WAVPACKPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-wavpack
PLIST_SUB+=	WAVPACKPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MAAC}
CONFIGURE_ARGS+=--enable-aac
PLIST_SUB+=	AACPLUGIN=""
LIB_DEPENDS+=	libfaad.so:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=--disable-aac
PLIST_SUB+=	AACPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	libsndfile.so:${PORTSDIR}/audio/libsndfile
CONFIGURE_ARGS+=--enable-sndfile
PLIST_SUB+=	SNDFILEPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-sndfile
PLIST_SUB+=	SNDFILEPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	libmodplug.so:${PORTSDIR}/audio/libmodplug
PLIST_SUB+=	MODPLUG=""
CONFIGURE_ARGS+=--enable-modplug
.else
PLIST_SUB+=	MODPLUG="@comment "
CONFIGURE_ARGS+=--disable-modplug
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-jack
PLIST_SUB+=	JACKPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-jack
PLIST_SUB+=	JACKPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MSCROBBLER}
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
PLIST_SUB+=	SCROBBLERPLUGIN=""
CONFIGURE_ARGS+=--enable-scrobbler2
.else
PLIST_SUB+=	SCROBBLERPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-scrobbler2
.endif

.if ${PORT_OPTIONS:MOSS4}
PLIST_SUB+=	OSS4PLUGIN=""
CONFIGURE_ARGS+=--enable-oss4
.else
PLIST_SUB+=	OSS4PLUGIN="@comment "
CONFIGURE_ARGS+=--disable-oss4
.endif

.if ${PORT_OPTIONS:MSID}
LIB_DEPENDS+=	libsidplayfp.so:${PORTSDIR}/audio/libsidplayfp
PLIST_SUB+=	SIDPLUGIN=""
CONFIGURE_ARGS+=--enable-sid
.else
PLIST_SUB+=	SIDPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-sid
.endif

.if ${PORT_OPTIONS:MCDAUDIO}
LIB_DEPENDS+=	libcdio_cdda.so:${PORTSDIR}/sysutils/libcdio-paranoia \
		libcddb.so:${PORTSDIR}/audio/libcddb
CONFIGURE_ARGS+=--enable-cdaudio
PLIST_SUB+=	CDAUDIOPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-cdaudio
PLIST_SUB+=	CDAUDIOPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MNEON}
LIB_DEPENDS+=	libneon.so:${PORTSDIR}/www/neon
CONFIGURE_ARGS+=--enable-neon
PLIST_SUB+=	NEONPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-neon
PLIST_SUB+=	NEONPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MMMS}
LIB_DEPENDS+=	libmms.so:${PORTSDIR}/net/libmms
CONFIGURE_ARGS+=--enable-mms
PLIST_SUB+=	MMSPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mms
PLIST_SUB+=	MMSPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MRESAMPLE}
LIB_DEPENDS+=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-resample
PLIST_SUB+=	RESAMPLEPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-resample
PLIST_SUB+=	RESAMPLEPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MSPEEDPITCH}
LIB_DEPENDS+=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-speedpitch
PLIST_SUB+=	SPEEDPITCHPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-speedpitch
PLIST_SUB+=	SPEEDPITCHPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
CONFIGURE_ARGS+=--enable-alsa
PLIST_SUB+=	ALSAPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSAPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MAMIDI}
LIB_DEPENDS+=	libfluidsynth.so:${PORTSDIR}/audio/fluidsynth
CONFIGURE_ARGS+=--enable-amidiplug
PLIST_SUB+=	AMIDIPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-amidiplug
PLIST_SUB+=	AMIDIPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MBS2B}
LIB_DEPENDS+=	libbs2b.so:${PORTSDIR}/audio/libbs2b
CONFIGURE_ARGS+=--enable-bs2b
PLIST_SUB+=	BS2BPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-bs2b
PLIST_SUB+=	BS2BPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPULSE}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--enable-pulse
PLIST_SUB+=	PULSE=""
.else
CONFIGURE_ARGS+=--disable-pulse
PLIST_SUB+=	PULSE="@comment "
.endif

.if ${PORT_OPTIONS:MLIRC}
LIB_DEPENDS+=	liblirc_client.so:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=--enable-lirc
PLIST_SUB+=	LIRC=""
.else
CONFIGURE_ARGS+=--disable-lirc
PLIST_SUB+=	LIRC="@comment "
.endif

.if ${PORT_OPTIONS:MMPRIS}
CONFIGURE_ARGS+=--enable-mpris2
PLIST_SUB+=	MPRIS=""
.else
CONFIGURE_ARGS+=--disable-mpris2
PLIST_SUB+=	MPRIS="@comment "
.endif

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/lib/audacious/ -name "*.so" \
		-exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
