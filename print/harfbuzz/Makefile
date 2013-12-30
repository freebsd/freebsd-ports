# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	harfbuzz
PORTVERSION=	0.9.25
CATEGORIES=	print
MASTER_SITES=	http://www.freedesktop.org/software/harfbuzz/release/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	OpenType text shaping engine

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libicudata.so:${PORTSDIR}/devel/icu \
		libgraphite2.so:${PORTSDIR}/graphics/graphite2

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	cairo glib20 ltverhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-graphite2

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
EXTRA_PATCHES=	${PATCHDIR}/extra-src_hb-open-type-private.hh
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libharfbuzz*.so.0

.include <bsd.port.post.mk>
