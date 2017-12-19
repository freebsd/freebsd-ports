# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	harfbuzz
PORTVERSION=	1.7.3
PORTREVISION?=	0
CATEGORIES=	print
MASTER_SITES=	http://www.freedesktop.org/software/harfbuzz/release/

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	OpenType text shaping engine

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2

USE_LDCONFIG=	yes
USES=		gettext-runtime gmake gnome libtool \
		pathfix pkgconfig tar:bzip2
USE_GNOME=	cairo glib20 introspection:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-graphite2 --with-gobject=yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB+=	LIBVER=0.10703.0

HARFBUZZ_SLAVE?=	no

.if ${HARFBUZZ_SLAVE} == no
CONFIGURE_ARGS+=	--without-icu
.else
CONFIGURE_ARGS+=	--with-icu \
		--disable-gtk-doc-html
USES+=		compiler:c++11-lib
LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz \
		libicudata.so:devel/icu

post-patch:
	${REINPLACE_CMD} -e 's|install-data-am: install-data-local|install-data-am:|g' \
		${WRKSRC}/docs/Makefile.in
.endif

.include <bsd.port.mk>
