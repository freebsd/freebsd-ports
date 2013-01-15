# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious-plugins
PORTVERSION=	3.3.3
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Plugins needed for audacious

BUILD_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--disable-pulse --disable-mpris2
WANT_GNOME=	yes
WANT_EFL=	yes
WANT_SDL=	yes

PORTDOCS=	AUTHORS

OPTIONS_DEFINE=	DBUS OSS4 SDLOUT ALSA CUE MP3 STATUSICON AOSD AOSDXCOMP \
				ADPLUG VORBIS FLAC WAVPACK AAC SNDFILE MODPLUG JACK SID \
				CDAUDIO SCROBBLER MMS GIO MTP NLS RESAMPLE AMIDI \
				NOTIFY BS2B FFAUDIO PULSE NEON
OPTIONS_DEFAULT=	DBUS CUE MP3 STATUSICON AOSD AOSDXCOMP AAC CDAUDIO \
					SCROBBLER NEON NLS OSS4

ADPLUG_DESC=	ADPLUG decoder
AMIDI_DESC=	Amidi decoder
AOSD_DESC=	Audacious OSD
AOSDXCOMP_DESC=	Audacious OSD X Composite
BS2B_DESC=	BS2B effect
CDAUDIO_DESC=	CD audio input
FFAUDIO_DESC=	FFAudio decoder
GIO_DESC=	GIO support
OSS4_DESC=	Open Sound System 4
PULSE_DESC=	PulseAudio support
RESAMPLE_DESC=	Resample effect
SCROBBLER_DESC=	Scrobbler decoder
SDLOUT_DESC=	SDL Output
SID_DESC=	Commodore64
STATUSICON_DESC=	X11 Status icon
NEON_DESC=	Neon plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDLOUT}
PLIST_SUB+=	SDL=""
USE_SDL=	sdl
CONFIGURE_ARGS+=--enable-sdlout
.else
PLIST_SUB+=	SDL="@comment "
CONFIGURE_ARGS+=--disable-sdlout
.endif

.if ${PORT_OPTIONS:MNOTIFY} || exists(${LOCALBASE}/lib/libnotify.so.1)
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-notify
PLIST_SUB+=		NOTIFY=""
.else
PLIST_SUB+=	NOTIFY="@comment "
CONFIGURE_ARGS+=--disable-notify
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-glib:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-gnomeshortcuts
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-gnomeshortcuts
PLIST_SUB+=	DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MCUE}
LIB_DEPENDS+=	cue:${PORTSDIR}/textproc/libcue
CONFIGURE_ARGS+=--enable-cue
PLIST_SUB+=	CUEPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-cue
PLIST_SUB+=	CUEPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MMP3}
LIB_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
CONFIGURE_ARGS+=--enable-mp3
PLIST_SUB+=	MP3PLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mp3
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
LIB_DEPENDS+=	Xcomposite:${PORTSDIR}/x11/libXcomposite
CONFIGURE_ARGS+=--enable-aosd-xcomp
PLIST_SUB+=	AOSDXCOMPPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-aosd-xcomp
PLIST_SUB+=	AOSDXCOMPPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MADPLUG}
LIB_DEPENDS+=	binio:${PORTSDIR}/devel/libbinio
CONFIGURE_ARGS+=--enable-adplug
PLIST_SUB+=	ADPLUGPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-adplug
PLIST_SUB+=	ADPLUGPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
PLIST_SUB+=	VORBISPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-vorbis
PLIST_SUB+=	VORBISPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--enable-flacng --enable-filewriter_flac
PLIST_SUB+=	FLACPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-flacng --disable-filewriter_flac
PLIST_SUB+=	FLACPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MFFAUDIO}
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg1
CONFIGURE_ARGS+=--enable-ffaudio
PLIST_SUB+=	FFAUDIOPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-ffaudio
PLIST_SUB+=	FFAUDIOPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
CONFIGURE_ARGS+=--enable-wavpack
PLIST_SUB+=	WAVPACKPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-wavpack
PLIST_SUB+=	WAVPACKPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MAAC}
CONFIGURE_ARGS+=--enable-aac
PLIST_SUB+=	AACPLUGIN=""
LIB_DEPENDS+=	faad:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=--disable-aac
PLIST_SUB+=	AACPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
CONFIGURE_ARGS+=--enable-sndfile
PLIST_SUB+=	SNDFILEPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-sndfile
PLIST_SUB+=	SNDFILEPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MMODPLUG}
LIB_DEPENDS+=	modplug:${PORTSDIR}/audio/libmodplug
PLIST_SUB+=	MODPLUG=""
CONFIGURE_ARGS+=--enable-modplug
.else
PLIST_SUB+=	MODPLUG="@comment "
CONFIGURE_ARGS+=--disable-modplug
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack \
		samplerate:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-jack
PLIST_SUB+=	JACKPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-jack
PLIST_SUB+=	JACKPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MSCROBBLER}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
PLIST_SUB+=	SCROBBLERPLUGIN=""
CONFIGURE_ARGS+=--enable-scrobbler
.else
PLIST_SUB+=	SCROBBLERPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-scrobbler
.endif

.if ${PORT_OPTIONS:MOSS4}
BUILD_DEPENDS+=	${LOCALBASE}/lib/oss/include/sys/soundcard.h:${PORTSDIR}/audio/oss
PLIST_SUB+=	OSS4PLUGIN=""
CONFIGURE_ARGS+=--enable-oss4
.else
PLIST_SUB+=	OSS4PLUGIN="@comment "
CONFIGURE_ARGS+=--disable-oss4
.endif

.if ${PORT_OPTIONS:MSID}
LIB_DEPENDS+=	sidplay:${PORTSDIR}/audio/libsidplay
PLIST_SUB+=	SIDPLUGIN=""
CONFIGURE_ARGS+=--enable-sid
.else
PLIST_SUB+=	SIDPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-sid
.endif

.if ${PORT_OPTIONS:MCDAUDIO}
LIB_DEPENDS+=	cdio:${PORTSDIR}/sysutils/libcdio \
		cddb:${PORTSDIR}/audio/libcddb
CONFIGURE_ARGS+=--enable-cdaudio
PLIST_SUB+=	CDAUDIOPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-cdaudio
PLIST_SUB+=	CDAUDIOPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MNEON}
LIB_DEPENDS+=	neon:${PORTSDIR}/www/neon29
CONFIGURE_ARGS+=--enable-neon
PLIST_SUB+=	NEONPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-neon
PLIST_SUB+=	NEONPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MMMS}
LIB_DEPENDS+=	mms:${PORTSDIR}/net/libmms
CONFIGURE_ARGS+=--enable-mms
PLIST_SUB+=	MMSPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mms
PLIST_SUB+=	MMSPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MMTP}
LIB_DEPENDS+=	mtp:${PORTSDIR}/audio/libmtp
CONFIGURE_ARGS+=--enable-mtp_up
PLIST_SUB+=	MTPPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mtp_up
PLIST_SUB+=	MTPPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MRESAMPLE}
LIB_DEPENDS+=	samplerate:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-resample
PLIST_SUB+=		RESAMPLEPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-resample
PLIST_SUB+=		RESAMPLEPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
CONFIGURE_ARGS+=--enable-alsa
PLIST_SUB+=	ALSAPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSAPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MAMIDI}
.if ${PORT_OPTIONS:MALSA}
CONFIGURE_ARGS+=--enable-amidiplug --enable-amidiplug-alsa
PLIST_SUB+=	AMIDIFPLUGIN="@comment "
PLIST_SUB+=	AMIDIAPLUGIN=""
.else
LIB_DEPENDS+=	fluidsynth:${PORTSDIR}/audio/fluidsynth
CONFIGURE_ARGS+=--enable-amidiplug --enable-amidiplug-flsyn
PLIST_SUB+=	AMIDIFPLUGIN=""
PLIST_SUB+=	AMIDIAPLUGIN="@comment "
.endif
PLIST_SUB+=	AMIDIPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-amidiplug
PLIST_SUB+=	AMIDIFPLUGIN="@comment "
PLIST_SUB+=	AMIDIAPLUGIN="@comment "
PLIST_SUB+=	AMIDIPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MBS2B}
LIB_DEPENDS+=	bs2b:${PORTSDIR}/audio/libbs2b
CONFIGURE_ARGS+=--enable-bs2b
PLIST_SUB+=	BS2BPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-bs2b
PLIST_SUB+=	BS2BPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MGIO}
USE_GNOME+=	glib20
CONFIGURE_ARGS+=--enable-gio
PLIST_SUB+=	GIOPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-gio
PLIST_SUB+=	GIOPLUGIN="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPULSE}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--enable-pulse
PLIST_SUB+=	PULSE=""
.else
CONFIGURE_ARGS+=--disable-pulse
PLIST_SUB+=	PULSE="@comment "
.endif

pre-everything::
.if ${PORT_OPTIONS:MAUDIOCD} && !exists(${LOCALBASE}/lib/libcdio_cdda.so)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Make sure you select the PARANOIA option when installing libcdio!"
	@${ECHO_CMD} ""
.endif

pre-configure:
.if ${PORT_OPTIONS:MAUDIOCD} && !exists(${LOCALBASE}/lib/libcdio_cdda.so)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "sysutils/libcdio got not installed with PARANOIA enabled!"
	@${ECHO_CMD} "To use the audiocd option you have to install libcdio with"
	@${ECHO_CMD} "PARANOIA support! So please reinstall it properly."
	@${ECHO_CMD} ""
	@exit 1
.endif

post-install:
.if ${PORT_OPTIONS:MGNOME}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You have installed audacious with gconf support."
	@${ECHO_MSG} "ALL PRESETS will be stored in the gconf database."
	@${ECHO_MSG} ""
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
