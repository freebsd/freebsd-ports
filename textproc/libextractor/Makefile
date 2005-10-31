# New ports collection makefile for:	libextractor
# Date created:		25 May 2005
# Whom:			kevlo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libextractor
PORTVERSION=	0.5.6a
CATEGORIES=	textproc
MASTER_SITES=	http://gnunet.org/libextractor/download/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Library for keyword extraction

USE_GNOME=	glib20
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_AUTOTOOLS=	libtool:15 libltdl
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-ltdl-install
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude libltdl

MAN1=		extract.1
MAN3=		libextractor.3

post-extract:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$||g'

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${TOUCH} -f
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/src/plugins/Makefile.*
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

check: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/wand/magick-wand.h)
LIB_DEPENDS+=	Magick.8:${PORTSDIR}/graphics/ImageMagick
PLIST_SUB+=	IMAGEMAGICK:=""
.else
PLIST_SUB+=	IMAGEMAGICK:="@comment "
.endif

.if exists(${LOCALBASE}/include/vorbis/vorbisfile.h)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS:=""
.else
PLIST_SUB+=	VORBIS:="@comment "
.endif

.include <bsd.port.post.mk>
