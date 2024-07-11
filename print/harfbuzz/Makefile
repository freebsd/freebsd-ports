PORTNAME=	harfbuzz
DISTVERSION=	9.0.0
PORTREVISION?=	0
CATEGORIES=	print
MASTER_SITES=	https://github.com/harfbuzz/harfbuzz/releases/download/${DISTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	OpenType text shaping engine
WWW=		https://harfbuzz.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2

USES=		compiler:c++11-lib cpe gnome meson \
		pkgconfig python:build shebangfix tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
SHEBANG_GLOB=	*.py
CPE_VENDOR=	harfbuzz_project

MESON_ARGS=	-Dgraphite2=enabled -Dchafa=disabled -Dtests=disabled

PLIST_SUB+=	LIBVER=0.60900.0

HARFBUZZ_SLAVE?=	no

.if ${HARFBUZZ_SLAVE} == no
OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_ENABLED=	docs
.endif

.if ${HARFBUZZ_SLAVE} == no
MESON_ARGS+=	-Dicu=disabled -Dcairo=disabled
.elif ${HARFBUZZ_SLAVE} == icu
MESON_ARGS+=	-Dicu=enabled -Dcairo=disabled -Ddocs=disabled
LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz \
		libicudata.so:devel/icu

.elif ${HARFBUZZ_SLAVE} == cairo
MESON_ARGS+=	-Dcairo=enabled -Dicu=disabled -Ddocs=disabled
LIB_DEPENDS+=	libharfbuzz.so:print/harfbuzz
USE_GNOME+=	cairo
.endif

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=enabled"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
