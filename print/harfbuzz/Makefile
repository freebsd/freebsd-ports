# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	harfbuzz
PORTVERSION=	1.0.6
CATEGORIES=	print
MASTER_SITES=	http://www.freedesktop.org/software/harfbuzz/release/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	OpenType text shaping engine

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2 \
		libicudata.so:${PORTSDIR}/devel/icu \
		libgraphite2.so:${PORTSDIR}/graphics/graphite2

USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	cairo glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-graphite2
INSTALL_TARGET=	install-strip

PLIST_SUB+=	LIBVER=0.10000.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
EXTRA_PATCHES=	${PATCHDIR}/extra-src_hb-open-type-private.hh
.endif

.include <bsd.port.post.mk>
