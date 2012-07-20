# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious-plugins
PORTVERSION=	3.2.4
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

# no ports for:
#		PULSE		"Enable PulseAudio output plugin"	on \
#		FFAUDIO         "Enable FFAUDIO input plugin"           off \

OPTIONS=	DBUS		"Enable dbus support"			on  \
		OSS		"Enable OSS output plugin"		off  \
		OSS4		"Enable OSS4 output plugin"		off \
		SDLOUT		"Enable SDL output plugin"		off \
		ALSA		"Enable ALSA output plugin"		off \
		CUE             "Enable CUE support"                    on  \
		MP3		"Enable mp3 plugin"			on  \
		STATUSICON	"Enable X11 Status Icon plugin"		on  \
		AOSD		"Enable X11 Audacious OSD plugin"	on  \
		AOSDXCOMP	"Enable X11 Audacious OSD X Composite Support" on  \
		ADPLUG		"Enable AdPlug plugin"			off \
		VORBIS		"Enable Ogg Vorbis input plugin"	off \
		FLAC		"Enable FLAC input plugin"		off \
		WAVPACK 	"Enable WavPack input plugin"		off \
		AAC		"Enable aac plugin"			on  \
		SNDFILE 	"Enable sndfile extensions"		off \
		MODPLUG 	"Enable ModPlug plugin"			off \
		JACK		"Enable jack output plugin"		off \
		SID		"Enable Commodore 64 audio (SID) input plugin"		off \
		CDAUDIO		"Enable cdaudio-ng input plugin"        on  \
		SCROBBLER	"Enable Scrobbler Plugin"		on  \
		NEON		"Enable neon (HTTP) transport plugin"	on  \
		MMS		"Enable mms transport plugin"		off \
		GIO		"Enable GIO transport plugin"		off \
		SMB		"Enable SMB transport plugin"		off \
		MTP		"Enable MTP upload support"             off \
		NLS		"Native Language Support"		on  \
		RESAMPLE	"Enable resample support"		off \
		AMIDI		"Enable amidi support"			off \
		NOTIFY		"Enable libnotify support"		off \
		BS2B		"Enable Bauer stereophonic-to-binaural (bs2b) support" off

.include <bsd.port.pre.mk>

.if defined(WITH_SDLOUT)
PLIST_SUB+=	SDL=""
USE_SDL=	sdl
CONFIGURE_ARGS+=--enable-sdlout
.else
PLIST_SUB+=	SDL="@comment "
CONFIGURE_ARGS+=--disable-sdlout
.endif

.if defined(WITH_NOTIFY) || exists(${LOCALBASE}/lib/libnotify.so.1)
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-notify
PLIST_SUB+=		NOTIFY=""
.else
PLIST_SUB+=	NOTIFY="@comment "
CONFIGURE_ARGS+=--disable-notify
.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-gnomeshortcuts
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-gnomeshortcuts
PLIST_SUB+=	DBUS="@comment "
.endif

.if !defined(WITHOUT_CUE)
LIB_DEPENDS+=	cue.1:${PORTSDIR}/textproc/libcue
CONFIGURE_ARGS+=--enable-cue
PLIST_SUB+=	CUEPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-cue
PLIST_SUB+=	CUEPLUGIN="@comment "
.endif

.if !defined(WITHOUT_MP3)
LIB_DEPENDS+=	mpg123.0:${PORTSDIR}/audio/mpg123
CONFIGURE_ARGS+=--enable-mp3
PLIST_SUB+=	MP3PLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mp3
PLIST_SUB+=	MP3PLUGIN="@comment "
.endif

.if !defined(WITHOUT_STATUSICON)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--enable-statusicon
PLIST_SUB+=	STATUSICONPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-statusicon
PLIST_SUB+=	STATUSICONPLUGIN="@comment "
.endif

.if !defined(WITHOUT_AOSD)
USE_GNOME+=	pango
CONFIGURE_ARGS+=--enable-aosd
PLIST_SUB+=	AOSDPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-aosd
PLIST_SUB+=	AOSDPLUGIN="@comment "
.endif

.if !defined(WITHOUT_AOSDXCOMP)
LIB_DEPENDS+=	Xcomposite.1:${PORTSDIR}/x11/libXcomposite
CONFIGURE_ARGS+=--enable-aosd-xcomp
PLIST_SUB+=	AOSDXCOMPPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-aosd-xcomp
PLIST_SUB+=	AOSDXCOMPPLUGIN="@comment "
.endif

.if defined(WITH_ADPLUG)
LIB_DEPENDS+=	binio.1:${PORTSDIR}/devel/libbinio
CONFIGURE_ARGS+=--enable-adplug
PLIST_SUB+=	ADPLUGPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-adplug
PLIST_SUB+=	ADPLUGPLUGIN="@comment "
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis
PLIST_SUB+=	VORBISPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-vorbis
PLIST_SUB+=	VORBISPLUGIN="@comment "
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
CONFIGURE_ARGS+=--enable-flacng --enable-filewriter_flac
PLIST_SUB+=	FLACPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-flacng --disable-filewriter_flac
PLIST_SUB+=	FLACPLUGIN="@comment "
.endif

# Needs a newer version of ffmpeg
#.if defined(WITH_FFAUDIO)
#LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
#CONFIGURE_ARGS+=--enable-ffaudio
#PLIST_SUB+=	FFAUDIOPLUGIN=""
#.else
#CONFIGURE_ARGS+=--disable-ffaudio
#PLIST_SUB+=	FFAUDIOPLUGIN="@comment "
#.endif

.if defined(WITH_WAVPACK)
LIB_DEPENDS+=	wavpack.2:${PORTSDIR}/audio/wavpack
CONFIGURE_ARGS+=--enable-wavpack
PLIST_SUB+=	WAVPACKPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-wavpack
PLIST_SUB+=	WAVPACKPLUGIN="@comment "
.endif

.if !defined(WITHOUT_AAC)
CONFIGURE_ARGS+=--enable-aac
PLIST_SUB+=	AACPLUGIN=""
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=--disable-aac
PLIST_SUB+=	AACPLUGIN="@comment "
.endif

.if defined(WITH_SNDFILE)
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
CONFIGURE_ARGS+=--enable-sndfile
PLIST_SUB+=	SNDFILEPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-sndfile
PLIST_SUB+=	SNDFILEPLUGIN="@comment "
.endif

.if defined(WITH_MODPLUG)
LIB_DEPENDS+=	modplug.1:${PORTSDIR}/audio/libmodplug
PLIST_SUB+=	MODPLUG=""
CONFIGURE_ARGS+=--enable-modplug
.else
PLIST_SUB+=	MODPLUG="@comment "
CONFIGURE_ARGS+=--disable-modplug
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack \
		samplerate.1:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-jack
PLIST_SUB+=	JACKPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-jack
PLIST_SUB+=	JACKPLUGIN="@comment "
.endif

.if !defined(WITHOUT_OSS)
PLIST_SUB+=	OSSPLUGIN=""
CONFIGURE_ARGS+=--enable-oss
.else
PLIST_SUB+=	OSSPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-oss
.endif

.if !defined(WITHOUT_SCROBBLER)
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
PLIST_SUB+=	SCROBBLERPLUGIN=""
CONFIGURE_ARGS+=--enable-scrobbler
.else
PLIST_SUB+=	SCROBBLERPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-scrobbler
.endif

.if !defined(WITHOUT_OSS4)
BUILD_DEPENDS+=	${LOCALBASE}/lib/oss/include/sys/soundcard.h:${PORTSDIR}/audio/oss
PLIST_SUB+=	OSS4PLUGIN=""
CONFIGURE_ARGS+=--enable-oss4
.else
PLIST_SUB+=	OSS4PLUGIN="@comment "
CONFIGURE_ARGS+=--disable-oss4
.endif

.if defined(WITH_SID)
LIB_DEPENDS+=	sidplay.1:${PORTSDIR}/audio/libsidplay
PLIST_SUB+=	SIDPLUGIN=""
CONFIGURE_ARGS+=--enable-sid
.else
PLIST_SUB+=	SIDPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-sid
.endif

.if defined(WITH_CDAUDIO)
LIB_DEPENDS+=	cdio.13:${PORTSDIR}/sysutils/libcdio \
		cddb.4:${PORTSDIR}/audio/libcddb
CONFIGURE_ARGS+=--enable-cdaudio
PLIST_SUB+=	CDAUDIOPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-cdaudio
PLIST_SUB+=	CDAUDIOPLUGIN="@comment "
.endif

.if !defined(WITHOUT_NEON)
LIB_DEPENDS+=	neon.27:${PORTSDIR}/www/neon29
CONFIGURE_ARGS+=--enable-neon
PLIST_SUB+=	NEONPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-neon
PLIST_SUB+=	NEONPLUGIN="@comment "
.endif

.if defined(WITH_MMS)
LIB_DEPENDS+=	mms.0:${PORTSDIR}/net/libmms
CONFIGURE_ARGS+=--enable-mms
PLIST_SUB+=	MMSPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mms
PLIST_SUB+=	MMSPLUGIN="@comment "
.endif

.if defined(WITH_MTP)
LIB_DEPENDS+=	mtp.9:${PORTSDIR}/audio/libmtp
CONFIGURE_ARGS+=--enable-mtp_up
PLIST_SUB+=	MTPPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mtp_up
PLIST_SUB+=	MTPPLUGIN="@comment "
.endif

.if !defined(WITHOUT_RESAMPLE)
LIB_DEPENDS+=	samplerate.1:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=--enable-resample
PLIST_SUB+=		RESAMPLEPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-resample
PLIST_SUB+=		RESAMPLEPLUGIN="@comment "
.endif

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
CONFIGURE_ARGS+=--enable-alsa
PLIST_SUB+=	ALSAPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSAPLUGIN="@comment "
.endif

.if defined(WITH_AMIDI)
.if defined(WITH_ALSA)
CONFIGURE_ARGS+=--enable-amidiplug --enable-amidiplug-alsa
PLIST_SUB+=	AMIDIFPLUGIN="@comment "
PLIST_SUB+=	AMIDIAPLUGIN=""
.else
LIB_DEPENDS+=	fluidsynth.1:${PORTSDIR}/audio/fluidsynth
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

.if defined(WITH_BS2B)
LIB_DEPENDS+=	bs2b.0:${PORTSDIR}/audio/libbs2b
CONFIGURE_ARGS+=--enable-bs2b
PLIST_SUB+=	BS2BPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-bs2b
PLIST_SUB+=	BS2BPLUGIN="@comment "
.endif

.if defined(WITH_GIO)
USE_GNOME+=	glib20
CONFIGURE_ARGS+=--enable-gio
PLIST_SUB+=	GIOPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-gio
PLIST_SUB+=	GIOPLUGIN="@comment "
.endif

.if defined(WITH_SMB)
SAMBA_PORT?=	net/samba34
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
CONFIGURE_ARGS+=--enable-smb
PLIST_SUB+=	SMBPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-smb
PLIST_SUB+=	SMBPLUGIN="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-everything::
.if defined(WITH_AUDIOCD) && !exists(${LOCALBASE}/lib/libcdio_cdda.so)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Make sure you select the PARANOIA option when installing libcdio!"
	@${ECHO_CMD} ""
.endif

pre-configure:
.if defined(WITH_AUDIOCD) && !exists(${LOCALBASE}/lib/libcdio_cdda.so)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "sysutils/libcdio got not installed with PARANOIA enabled!"
	@${ECHO_CMD} "To use the audiocd option you have to install libcdio with"
	@${ECHO_CMD} "PARANOIA support! So please reinstall it properly."
	@${ECHO_CMD} ""
	@exit 1
.endif

post-install:
.if defined(WITH_GNOME)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You have installed audacious with gconf support."
	@${ECHO_MSG} "ALL PRESETS will be stored in the gconf database."
	@${ECHO_MSG} ""
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
