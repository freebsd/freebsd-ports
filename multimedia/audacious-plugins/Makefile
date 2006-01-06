# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious
PORTVERSION=	0.1.2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://audacious-media-player.org/release/
DISTNAME=	audacious-${PORTVERSION}
EXTRACT_SUFX=.tgz

MAINTAINER=	redchrom@mail.ru
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

INPUT_PLUGINS=	cdaudio,mpg123,wav,tonegen,wma,console
OUTPUT_PLUGINS=	OSS,disk_writer,crossfade
VISUALIZATION_PLUGINS=	blur_scope

OPTIONS=	VORBIS	"Enable Ogg Vorbis input" on \
		FLAC	"Enable flac input" on \
		ESOUND	"Enable Esound output"  off \
		ID3V2	"Enable id3v2 editing" off \
		SIMD	"build with x86 SIMD(3DNow!/MMX) instructions support" on \
		SDL	"Enable SDL support" off \

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		requires include/tgmath.h, which isn't available until FreeBSD 5.3
.endif

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
INPUT_PLUGINS+=	vorbis
PLIST_SUB+=	VORBISPLUGIN:=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBISPLUGIN:="@comment "
.endif

.if !defined(WITHOUT_FLAC)
INPUT_PLUGINS+=	flac
PLIST_SUB+=	FLACPLUGIN:=""
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.else
PLIST_SUB+=	FLACPLUGIN:="@comment "
CONFIGURE_ARGS+=	--disable-flac
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
OUTPUT_PLUGINS+=	esd
PLIST_SUB+=	ESDPLUGIN:=""
.if defined(PKGNAMESUFFIX)
PKGNAMESUFFIX:=	${PKGNAMESUFFIX}-esound
.else
PKGNAMESUFFIX=	-esound
.endif
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUB+=	ESDPLUGIN:="@comment "
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

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g' \
		${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
