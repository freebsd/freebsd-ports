# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	harfbuzz
PORTVERSION=	1.4.1
CATEGORIES=	print
MASTER_SITES=	http://www.freedesktop.org/software/harfbuzz/release/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenType text shaping engine

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libicudata.so:devel/icu \
		libgraphite2.so:graphics/graphite2

USE_LDCONFIG=	yes
USES=		compiler:c++0x gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	cairo glib20 introspection:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-graphite2 --with-gobject=yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB+=	LIBVER=0.10400.1

EXTRA_PATCHES+=	${EXTRA_PATCHES_${OPSYS}_${OSREL:R}}
EXTRA_PATCHES_FreeBSD_9=	${PATCHDIR}/extra-src_hb-open-type-private.hh

.include <bsd.port.mk>
