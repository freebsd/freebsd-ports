# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	harfbuzz
DISTVERSION=	2.8.1
PORTREVISION?=	0
CATEGORIES=	print
MASTER_SITES=	https://github.com/harfbuzz/harfbuzz/releases/download/${DISTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	OpenType text shaping engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2

USES=		compiler:c++11-lib gnome meson \
		pkgconfig python:build shebangfix tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
SHEBANG_GLOB=	*.py

MESON_ARGS=	-Dglib=enabled -Dgobject=enabled -Dgraphite=enabled \
		-Dfreetype=enabled -Dbenchmark=disabled

PLIST_SUB+=	LIBVER=0.20801.0

HARFBUZZ_SLAVE?=	no

.if ${HARFBUZZ_SLAVE} == no
OPTIONS_DEFINE=	DOCS TEST
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_ENABLED=	docs
TEST_MESON_ENABLED=	tests
.endif

.if ${HARFBUZZ_SLAVE} == no
MESON_ARGS+=	-Dicu=disabled -Dcairo=disabled
.elif ${HARFBUZZ_SLAVE} == icu
MESON_ARGS+=	-Dicu=enabled -Dcairo=disabled -Ddocs=disabled \
		-Dtests=disabled
LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz \
		libicudata.so:devel/icu

.elif ${HARFBUZZ_SLAVE} == hb-view
MESON_ARGS+=	-Dcairo=enabled -Dicu=disabled -Ddocs=disabled \
		-Dtests=disabled
LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz
USE_GNOME+=	cairo
.endif

.include <bsd.port.mk>
