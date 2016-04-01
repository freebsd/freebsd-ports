# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webkit
PORTVERSION=	2.8.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/releases/
PKGNAMESUFFIX=	2-gtk3
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK+ 3 toolkit

BUILD_DEPENDS=	geoclue>=0:net/geoclue
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libwebp.so:graphics/webp \
		libpng.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libicutu.so:devel/icu \
		libharfbuzz.so:print/harfbuzz \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limitw:1,even

USE_GSTREAMER1=	yes
USE_XORG=	x11 xext ice
USES=		bison cmake compiler:c++11-lib gettext gmake gperf jpeg perl5 \
		pkgconfig python:2 sqlite tar:xz
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes
USE_GNOME=	cairo gtk20 gtk30 introspection:build libxml2 libxslt
USE_GL=		gl egl
USE_PERL5=	build
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CMAKE_ARGS+=	-DPORT=GTK \
		-DUSE_LD_GOLD:BOOL=0
CONFIGURE_ENV+=	XDG_CACHE_HOME=${WRKDIR}

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk3
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS_DEFINE=	DEBUG FULLDEBUG
DEBUG_DESC=	Just enable debug symbols
FULLDEBUG_DESC=	Enable asserts and other debug support

FULLDEBUG_CONFIGURE_ENABLE=	debug
DEBUG_CMAKE_OFF=	-DCMAKE_BUILD_TYPE=Release

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=0:textproc/flex
CONFIGURE_ENV+=	FLEX_PATH="${LOCALBASE}/bin/flex"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/Source/WebKit2/UIProcess/Plugins/unix/PluginInfoStoreUnix.cpp

pre-configure:
.if !exists(${LOCALBASE}/libdata/pkgconfig/cairo-egl.pc)
	@${ECHO_CMD} "${PKGNAME}: Needs cairo with OPENGL support enabled."
	@${FALSE}
.endif

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/jsc \
		${STAGEDIR}/${PREFIX}/bin/jsc-4
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/webkit2gtk-4.0/injected-bundle/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jsc-4
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/webkit2gtk-4.0/WebKit*

.include <bsd.port.mk>
