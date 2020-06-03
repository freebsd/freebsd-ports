# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	harfbuzz
DISTVERSION=	2.6.7
PORTREVISION?=	0
CATEGORIES=	print
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	OpenType text shaping engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2

USES=		compiler:c++11-lib gettext-runtime gmake gnome libtool \
		pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-graphite2 --with-gobject=yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_SUB+=	LIBVER=0.20600.7

HARFBUZZ_SLAVE?=	no

.if ${HARFBUZZ_SLAVE} == no
CONFIGURE_ARGS+=	--without-icu --without-cairo
.elif ${HARFBUZZ_SLAVE} ==  icu
CONFIGURE_ARGS+=	--with-icu \
			--without-cairo \
		--disable-gtk-doc-html
LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz \
		libicudata.so:devel/icu

.elif ${HARFBUZZ_SLAVE} == hb-view
CONFIGURE_ARGS+=	--with-cairo \
			--without-icu
LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz
USE_GNOME+=	cairo
.endif

.if ${HARFBUZZ_SLAVE} != no
post-patch:
	${REINPLACE_CMD} -e 's|install-data-am: install-data-local|install-data-am:|g' \
		${WRKSRC}/docs/Makefile.in
.endif

.include <bsd.port.mk>
