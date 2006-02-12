# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious
PORTVERSION=	0.2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://audacious-media-player.org/release/
DISTNAME=	audacious-${PORTVERSION}
EXTRACT_SUFX=.tgz

MAINTAINER=	redchrom@gmail.com
COMMENT=	A media player based on BMP and XMMS

LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile

USE_GNOME=	gtk20 libglade2
WANT_GNOME=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_AUTOTOOLS=	libtool:15
LIBTOOLFILES=	configure
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lstdc++" \
		INPUT_PLUGINS="${INPUT_PLUGINS}" \
		OUTPUT_PLUGINS="${OUTPUT_PLUGINS}" \
		VISUALIZATION_PLUGINS="${VISUALIZATION_PLUGINS}"

MAN1=		audacious.1

PORTDOCS=	README AUTHORS ChangeLog NEWS

INPUT_PLUGINS=	cdaudio,mpg123,wav,tonegen,wma,console,sexypsf
OUTPUT_PLUGINS=	OSS,disk_writer,crossfade
VISUALIZATION_PLUGINS=	blur_scope

OPTIONS=	VORBIS	"Enable Ogg Vorbis input" on \
		FLAC	"Enable flac input" on \
		MODPLUG	"Enable modplug input" off \
		MPC	"Enable mpc input" off \
		ESOUND	"Enable Esound output"  off \
		VISUAL  "Enable libvisual plugin" off \
		ID3V2	"Enable id3v2 editing" off \
		SIMD	"Build with x86 SIMD(3DNow!/MMX) instructions support" on \
		SDL	"Enable SDL support" off \
		GNOME   "Build with gnomevfs/gconf support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
INPUT_PLUGINS+=	vorbis
PLIST_SUB+=	VORBISPLUGIN=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBISPLUGIN="@comment "
.endif

.if !defined(WITHOUT_FLAC)
INPUT_PLUGINS+=	flac
PLIST_SUB+=	FLACPLUGIN=""
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.else
PLIST_SUB+=	FLACPLUGIN="@comment "
CONFIGURE_ARGS+=	--disable-flac
.endif

.if !defined(WITHOUT_MODPLUG)
INPUT_PLUGINS+=	modplug
PLIST_SUB+=	MODPLUG=""
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug
.else
PLIST_SUB+=	MODPLUG="@comment "
CONFIGURE_ARGS+=	--disable-modplug
.endif

.if !defined(WITHOUT_MPC)
INPUT_PLUGINS+=	musepack
PLIST_SUB+=	MPCPLUGIN=""
LIB_DEPENDS+=	mpcdec.3:${PORTSDIR}/audio/libmpcdec \
	tag.5:${PORTSDIR}/audio/taglib
.else
PLIST_SUB+=	MPCPLUGIN="@comment "
CONFIGURE_ARGS+=	--disable-musepack
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
OUTPUT_PLUGINS+=	esd
PLIST_SUB+=	ESDPLUGIN=""
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-esound
.else
PKGNAMESUFFIX=	-esound
.endif
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESDPLUGIN="@comment "
.endif

.if defined(WITH_VISUAL)
PLIST_SUB+=	LIBVISUAL=""
VISUALIZATION_PLUGINS+=	libvisual-proxy
LIB_DEPENDS+=	visual.0:${PORTSDIR}/graphics/libvisual
.else
PLIST_SUB+=	LIBVISUAL="@comment "
.endif

.if defined(WITH_ID3V2)
LIB_DEPENDS+=	id3-3.8.3:${PORTSDIR}/audio/id3lib
.endif

.if ${ARCH} != "i386"
WITHOUT_SIMD=	yes
.endif

.if !defined(WITHOUT_SIMD) && ${OSVERSION} >= 400021
CONFIGURE_ARGS+=	--enable-simd
.endif

.if defined(WITH_SDL)
USE_SDL=	sdl
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gconf2 gnomevfs2
CONFIGURE_ARGS+=	--enable-gnome-vfs --enable-gconf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g' \
		${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}
.if defined(WITH_GNOME)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You have installed audacious with gconf support."
	@${ECHO_MSG} "ALL PRESETS will be storing in the gconf database."
	@${ECHO_MSG} ""
.endif
.if defined(WITH_VISUAL)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You have installed audacious with libvisual support."
	@${ECHO_MSG} "If you want to be able to access any visualizations,"
	@${ECHO_MSG} "you must install the graphics/libvisual-plugins port."
	@${ECHO_MSG} ""
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README AUTHORS ChangeLog NEWS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
