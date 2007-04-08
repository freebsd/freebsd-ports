# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious-plugins
PORTVERSION=	1.3.2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://static.audacious-media-player.org/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Plugins needed for audacious

BUILD_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious
LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl
		
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--disable-evdevplug --disable-alsa --disable-amidiplug \
		--disable-pulse --disable-coreaudio --disable-projectm
WANT_GNOME=	yes
WANT_SDL=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS

# no ports for:
#		PULSE		"Enable PulseAudio output plugin"	off \
#		COREAUDIO	"Enable CoreAudio output plugin"	off \
#		PROJECTM	"Enable projectM vis plugin"		off \

OPTIONS=	ESOUND		"Enable Esound output output"		off \
		MP3		"Enable mp3 plugin"			on  \
		ROCKLIGHT	"Enable Rocklight vis plugin"		on  \
		LIRC		"Enable LIRC plugin"			off \
		STATUSICON	"Enable X11 Status Icon plugin"		on  \
		AOSD		"Enable X11 Audacious OSD plugin"	on  \
		ADPLUG		"Enable AdPlug plugin"			off \
		VORBIS		"Enable Ogg Vorbis input plugin"	off \
		WAVPACK 	"Enable WavPack input plugin"		off \
		AAC		"Enable aac plugin"			on  \
		SNDFILE 	"Enable sndfile extensions"		off \
		MODPLUG 	"Enable ModPlug plugin"			off \
		MPC		"Enable musepack input plugin"		off \
		WMA		"Enable wma plugin"			on  \
		JACK		"Enable jack output plugin"		off \
		ARTS		"Enable arts output plugin"		off \
		SID		"Enable sid input plugin"		off \
		OSS		"Enable OSS output plugin"		on  \
		TIMIDITY	"Enable timidity plugin"		on  \
		MMS		"Enable mms support"			off \
		PARANORMAL	"Enable paranormal vis plugin"		on  \
		XSPF		"Enable XSPF support"			on  \
		TTA		"Enable TrueAudio plugin"		on  \
		LAME		"Enable liblame plugin"			off \
		GNOME		"Build with gnomevfs/gconf support"	off \
		NLS		"Native Language Support"		on

.include <bsd.port.pre.mk>

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
CONFIGURE_ARGS+=--enable-mad
PLIST_SUB+=	MP3PLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mad
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

.if defined(WITH_ADPLUG)
LIB_DEPENDS+=	binio.1:${PORTSDIR}/devel/libbinio
CONFIGURE_ARGS+=--enable-adplug
PLIST_SUB+=	ADPLUGPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-adplug
PLIST_SUB+=	ADPLUGPLUGIN="@comment "
.endif

.if defined(WITH_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--enable-vorbis --enable-flac	# it uses an internal flac-lib copy
PLIST_SUB+=	VORBISPLUGIN=""
CFLAGS+=	-I. -I../libflac -Ilibflac	# to not use system flac if it is installed
.else
CONFIGURE_ARGS+=--disable-vorbis --disable-flac
PLIST_SUB+=	VORBISPLUGIN="@comment "
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

.if defined(WITH_MPC)
LIB_DEPENDS+=	mpcdec.5:${PORTSDIR}/audio/libmpcdec \
		tag.5:${PORTSDIR}/audio/taglib
PLIST_SUB+=	MPCPLUGIN=""
CONFIGURE_ARGS+=--enable-musepack
.else
PLIST_SUB+=	MPCPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-musepack
.endif

.if !defined(WITHOUT_WMA)
CONFIGURE_ARGS+=--enable-wma
PLIST_SUB+=	WMAPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-wma
PLIST_SUB+=	WMAPLUGIN="@comment "
.endif

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=--enable-jack
PLIST_SUB+=	JACKPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-jack
PLIST_SUB+=	JACKPLUGIN="@comment "
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=--enable-arts
PLIST_SUB+=	ARTSPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-arts
PLIST_SUB+=	ARTSPLUGIN="@comment "
.endif

.if !defined(WITHOUT_OSS)
PLIST_SUB+=	OSSPLUGIN=""
CONFIGURE_ARGS+=--enable-oss
.else
PLIST_SUB+=	OSSPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-oss
.endif

.if defined(WITH_SID)
LIB_DEPENDS+=	sidplay.1:${PORTSDIR}/audio/libsidplay
PLIST_SUB+=	SIDPLUGIN=""
CONFIGURE_ARGS+=--enable-sid
.else
PLIST_SUB+=	SIDPLUGIN="@comment "
CONFIGURE_ARGS+=--disable-sid
.endif

.if !defined(WITHOUT_TIMIDITY)
CONFIGURE_ARGS+=--enable-timidity
PLIST_SUB+=	TIMIDITYPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-timidity
PLIST_SUB+=	TIMIDITYPLUGIN="@comment "
.endif

.if !defined(WITHOUT_PARANORMAL)
CONFIGURE_ARGS+=--enable-paranormal --disable-mms
PLIST_SUB+=	PARANORMALPLUGIN="" MMSPLUGIN="@comment "
USE_SDL=	sdl
.else
CONFIGURE_ARGS+=--disable-paranormal
PLIST_SUB+=	PARANORMALPLUGIN="@comment "
.if defined(WITH_MMS)
LIB_DEPENDS+=	mms.0:${PORTSDIR}/net/libmms
CONFIGURE_ARGS+=--enable-mms
PLIST_SUB+=	MMSPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-mms
PLIST_SUB+=	MMSPLUGIN="@comment "
.endif
.endif

.if !defined(WITHOUT_XSPF)
USE_GNOME+=	libxml2
CONFIGURE_ARGS+=--enable-xspf
PLIST_SUB+=	XSPFPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-xspf
PLIST_SUB+=	XSPFPLUGIN="@comment "
.endif

.if !defined(WITHOUT_TTA)
CONFIGURE_ARGS+=--enable-tta
PLIST_SUB+=	TTAPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-tta
PLIST_SUB+=	TTAPLUGIN="@comment "
.endif

.if defined(WITH_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=--enable-lame
PLIST_SUB+=	LAMEPLUGIN=""
.else
CONFIGURE_ARGS+=--disable-lame
PLIST_SUB+=	LAMEPLUGIN="@comment "
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gnomevfs2 gconf2
CONFIGURE_ARGS+=--enable-gnome-vfs --enable-gconf
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
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
