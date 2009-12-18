# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious-plugins
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.atheme.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Plugins needed for audacious

BUILD_DEPENDS=	audacious2:${PORTSDIR}/multimedia/audacious

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include" \
		CPP=${CPP}
CONFIGURE_ARGS=	--disable-evdevplug --disable-alsa --disable-amidiplug \
		--disable-pulse --disable-projectm --disable-projectm-1.0
WANT_GNOME=	yes
WANT_EFL=	yes
WANT_SDL=	yes

PORTDOCS=	AUTHORS

# no ports for:
#		PULSE		"Enable PulseAudio output plugin"	on \
#		COREAUDIO	"Enable CoreAudio output plugin"	on \
#		PROJECTM	"Enable projectM vis plugin"		on \

OPTIONS=	DBUS		"Enable dbus support"			on  \
		ESOUND		"Enable Esound output output"		off \
		MP3		"Enable mp3 plugin"			on  \
		ROCKLIGHT	"Enable Rocklight vis plugin"		on  \
		LIRC		"Enable LIRC plugin"			off \
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
		SID		"Enable sid input plugin"		off \
		OSS		"Enable OSS output plugin"		on  \
		OSS4		"Enable OSS4 output plugin"		off \
		CDAUDIO		"Enable cdaudio-ng input plugin"        on  \
		NEON		"Enable neon (HTTP) support"            on  \
		MMS		"Enable mms support"			off \
		MTP		"Enable MTP upload support"             off \
		PARANORMAL	"Enable paranormal vis plugin"		on  \
		XSPF		"Enable XSPF support"			on  \
		GNOME		"Build with gnomevfs/gconf support"	off \
		NLS		"Native Language Support"		on  \
		CURL		"curl for lastfm/scrobbler support"	off \
		SSE2		"Enable SSE2 support"			on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus --enable-gnomeshortcuts
PLIST_SUB+=	DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus --disable-gnomeshortcuts
PLIST_SUB+=	DBUS="@comment "
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
CONFIGURE_ARGS+=--enable-esd
PLIST_SUB+=	ESDPLUGIN=""
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-esound
.else
PKGNAMESUFFIX=	-esound
.endif
.else
CONFIGURE_ARGS+=--disable-esd
PLIST_SUB+=	ESDPLUGIN="@comment "
.endif

.if !defined(WITHOUT_MP3)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=--enable-mp3
PLIST_SUB+=	MP3PLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mp3
PLIST_SUB+=	MP3PLUGIN="@comment "
.endif

.if !defined(WITHOUT_ROCKLIGHT)
PLIST_SUB+=	ROCKLIGHTPLUGIN=""
CONFIGURE_ARGS+=--enable-rocklight
.else
CONFIGURE_ARGS+=--disable-rocklight
PLIST_SUB+=	ROCKLIGHTPLUGIN="@comment "
.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=--enable-lirc
PLIST_SUB+=	LIRCPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-lirc
PLIST_SUB+=	LIRCPLUGIN="@comment "
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

.if defined(WITH_WAVPACK)
LIB_DEPENDS+=	wavpack.1:${PORTSDIR}/audio/wavpack
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
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug
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

#OSS4 only works with recent changed in HEAD
.if ${OSVERSION} >= 800061
.if !defined(WITHOUT_OSS)
PLIST_SUB+=	OSSPLUGIN=""
CONFIGURE_ARGS+=--enable-oss
.else
PLIST_SUB+=	OSSPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-oss
.endif

.if !defined(WITHOUT_OSS4)
PLIST_SUB+=	OSS4PLUGIN=""
CONFIGURE_ARGS+=--enable-oss4
.else
PLIST_SUB+=	OSS4PLUGIN="@comment "
CONFIGURE_ARGS+=--disable-oss4
.endif
.else
PLIST_SUB+=     OSS4PLUGIN="@comment "
CONFIGURE_ARGS+=--disable-oss4
.if defined(WITH_OSS) || defined(WITH_OSS4)
PLIST_SUB+=     OSSPLUGIN=""
CONFIGURE_ARGS+=--enable-oss
.else
PLIST_SUB+=     OSSPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-oss
.endif
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
LIB_DEPENDS+=	cdio.12:${PORTSDIR}/sysutils/libcdio \
		cddb.4:${PORTSDIR}/audio/libcddb
CONFIGURE_ARGS+=--enable-cdaudio
PLIST_SUB+=	CDAUDIOPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-cdaudio
PLIST_SUB+=	CDAUDIOPLUGIN="@comment "
.endif

.if defined(WITH_PARANORMAL)
CONFIGURE_ARGS+=--enable-paranormal
PLIST_SUB+=	PARANORMALPLUGIN=""
USE_SDL+=	sdl
.else
CONFIGURE_ARGS+=--disable-paranormal
PLIST_SUB+=	PARANORMALPLUGIN="@comment "
.endif

.if !defined(WITHOUT_NEON)
LIB_DEPENDS+= neon.28:${PORTSDIR}/www/neon28
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
LIB_DEPENDS+=	mtp.8:${PORTSDIR}/audio/libmtp
CONFIGURE_ARGS+=--enable-mtp_up
PLIST_SUB+=	MTPPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mtp_up
PLIST_SUB+=	MTPPLUGIN="@comment "
.endif

.if !defined(WITHOUT_XSPF)
USE_GNOME+=	libxml2
CONFIGURE_ARGS+=--enable-xspf
PLIST_SUB+=	XSPFPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-xspf
PLIST_SUB+=	XSPFPLUGIN="@comment "
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gnomevfs2 gconf2
CONFIGURE_ARGS+=--enable-gnome-vfs --enable-gconf
.endif

.if !defined(WITHOUT_CURL) || exists(${LOCALBASE}/lib/libcurl.so)
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
PLIST_SUB+=     CURLPLUGIN=""
.else
PLIST_SUB+=     CURLPLUGIN="@comment "
.endif

.if !defined(WITHOUT_SSE2)
CONFIGURE_ARGS+=--disable-sse2
.else
CONFIGURE_ARGS+=--enable-sse2
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

post-patch:
	@${REINPLACE_CMD} -e 's|$$EGREP|egrep|g; \
		s| -ldl||g' ${WRKSRC}/configure

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
