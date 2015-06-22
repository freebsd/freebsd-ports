# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webkit
PORTVERSION=	2.6.6
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/releases/
PKGNAMESUFFIX=	2-gtk3
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK+ 3 toolkit

BUILD_DEPENDS=	geoclue>=0:${PORTSDIR}/net/geoclue
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libwebp.so:${PORTSDIR}/graphics/webp \
		libpng.so:${PORTSDIR}/graphics/png \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		libharfbuzz.so:${PORTSDIR}/print/harfbuzz \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
#add		libicu
RUN_DEPENDS=	geoclue>=0:${PORTSDIR}/net/geoclue 

PORTSCOUT=	^${PORTVERSION:R:S|.|\.|}\.*$$

USE_GSTREAMER1=	yes
USE_XORG=	x11 xext ice
# when it USES=cmake safe
USES=		bison compiler:c++11-lib gettext gmake gperf jpeg perl5 \
		pkgconfig python:2 tar:xz
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes
USE_GNOME=	cairo gtk20 gtk30 introspection:build \
		libxml2 libxslt:build
USE_GL=		gl egl
USE_SQLITE=	3
USE_PERL5=	build
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BUILD_DEPENDS+=	cmake:${PORTSDIR}/devel/cmake
#USES=cmake is not used because it triggers:
#Linking CXX executable ../../../bin/jsc
#../../../lib/libjavascriptcoregtk-4.0.so.18.0.8: undefined reference to `JSC::JSCell::inherits(JSC::ClassInfo const*) const'
#../../../lib/libjavascriptcoregtk-4.0.so.18.0.8: undefined reference to `JSC::JSCell::structure() const'
#c++: error: linker command failed with exit code 1 (use -v to see invocation)
#Source/JavaScriptCore/shell/CMakeFiles/jsc.dir/build.make:94: recipe for target 'bin/jsc' failed
# there is something in CMAKE_ENV that cause this ... but what.

CMAKE_ARGS+=	-DPORT=GTK
CMAKE_ENV+=	XDG_CACHE_HOME=${WRKDIR} \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		CC="${CC}" CXX="${CXX}" CPP="${CPP}"

#CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE=1
#MAKE_ARGS+=	V=1 VERBOSE=1

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk3
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS_DEFINE=	DEBUG FULLDEBUG
DEBUG_DESC=	Just enable debug symbols
FULLDEBUG_DESC=	Enable asserts and other debug support

FULLDEBUG_CONFIGURE_ENABLE=	debug
DEBUG_CONFIGURE_ON=	--enable-debug-symbols=yes
DEBUG_CONFIGURE_OFF=	--disable-debug-symbols

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900000
IGNORE=		Not supported on 8.x due to c++ madness
.endif

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=0:${PORTSDIR}/textproc/flex
CONFIGURE_ENV+=	FLEX_PATH="${LOCALBASE}/bin/flex"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/Source/WebCore/plugins/PluginDatabase.cpp

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CFLAGS="${CFLAGS}" \
		${CMAKE_ENV} cmake -DPORT=GTK ${CMAKE_ARGS}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/jsc \
		${STAGEDIR}/${PREFIX}/bin/jsc-4
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/webkit2gtk-4.0/injected-bundle/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jsc-4
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/webkit2gtk-4.0/WebKit*

.include <bsd.port.mk>
