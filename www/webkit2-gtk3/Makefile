# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webkit
PORTVERSION=	2.16.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/releases/
PKGNAMESUFFIX=	2-gtk3
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK+ 3 toolkit

LICENSE=	GPLv2 BSD2CLAUSE
LICENSE_COMB=	dual

LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libwebp.so:graphics/webp \
		libpng.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libnotify.so:devel/libnotify \
		libhyphen.so:textproc/hyphen \
		libicutu.so:devel/icu \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libsoup-2.4.so:devel/libsoup \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls

PORTSCOUT=	limitw:1,even

USE_GSTREAMER1=	bad gl
USE_XORG=	x11 xcomposite xdamage xext xrender xt ice
USES=		bison cmake compiler:c++14-lang gettext gnome gperf \
		jpeg perl5 pkgconfig python:2.7,build sqlite tar:xz
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build libxml2 libxslt
USE_GL=		gl egl
USE_PERL5=	build
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install

CMAKE_ARGS+=	-DPORT=GTK \
		-DENABLE_WAYLAND_TARGET:BOOL=OFF \
		-DENABLE_MINIBROWSER:BOOL=ON \
		-DENABLE_GLES2:BOOL=OFF \
		-DENABLE_ACCELERATED_2D_CANVAS=ON \
		-DUSE_LD_GOLD:BOOL=OFF \
		-DENABLE_WEBKIT:BOOL=OFF
CONFIGURE_ENV+=	XDG_CACHE_HOME=${WRKDIR}

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk3
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DEBUG GEOIP NPAPI
OPTIONS_DEFAULT=GEOIP
OPTIONS_DEFAULT_i386=	NPAPI
OPTIONS_DEFAULT_amd64=	NPAPI

DEBUG_BUILD_DEPENDS=	binutils>=0:devel/binutils
DEBUG_CMAKE_ON=		-DCMAKE_BUILD_TYPE:STRING=Debug \
			-DCMAKE_AR=${LOCALBASE}/bin/ar \
			-DCMAKE_RANLIB=${LOCALBASE}/bin/ranlib \
			-DCMAKE_LINKER=${LOCALBASE}/bin/ld
DEBUG_CXXFLAGS=		-B${LOCALBASE}/bin

DEBUG_CMAKE_OFF=	-DCMAKE_BUILD_TYPE:STRING=Release \
			-DCMAKE_AR=/usr/bin/ar \
			-DCMAKE_RANLIB=/usr/bin/ranlib \
			-DCMAKE_LINKER=/usr/bin/ld
DEBUG_CXXFLAGS_OFF=	-B/usr/bin
DEBUG_CFLAGS_OFF=	-DNDEBUG

GEOIP_CMAKE_BOOL=	ENABLE_GEOLOCATION
GEOIP_BUILD_DEPENDS+=	geoclue>=2.4.3:net/geoclue
GEOIP_RUN_DEPENDS+=	geoclue>=2.4.3:net/geoclue

NPAPI_DESC=	Support gtk2 (NPAPI) based plugins (like flash)
NPAPI_CMAKE_BOOL=	ENABLE_PLUGIN_PROCESS_GTK2
NPAPI_USE=	GNOME=gtk20

.include <bsd.port.options.mk>

.if ${ARCH} == armv6
CMAKE_ARGS+=	-DENABLE_JIT:BOOL=OFF
.endif

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
CMAKE_ARGS+=	-DENABLE_JIT:BOOL=OFF
CFLAGS+=	-DENABLE_YARR_JIT=0
.endif

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/Source/WebKit2/Shared/Plugins/unix/PluginSearchPath.cpp

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-egl; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with OPENGL support enabled."; \
		${FALSE}; \
	fi

post-install:
	@${LN} -sf ../libexec/webkit2gtk-4.0/jsc ${STAGEDIR}${PREFIX}/bin/jsc-4
	@${LN} -sf ../libexec/webkit2gtk-4.0/MiniBrowser ${STAGEDIR}${PREFIX}/bin/MiniBrowser-4
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/webkit2gtk-4.0/injected-bundle/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/webkit2gtk-4.0/*

.include <bsd.port.mk>
