# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	harfbuzz
PORTVERSION=	0.9.19
CATEGORIES=	print
MASTER_SITES=	http://www.freedesktop.org/software/harfbuzz/release/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	OpenType text shaping engine

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2 \
		icudata:${PORTSDIR}/devel/icu \
		graphite2:${PORTSDIR}/graphics/graphite2

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	cairo glib20 ltverhack
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-graphite2

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
EXTRA_PATCHES=	${PATCHDIR}/extra-src_hb-open-type-private.hh
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^build_old_libs=yes|build_old_libs=no|g' \
		${WRKDIR}/gnome-libtool

.include <bsd.port.post.mk>
