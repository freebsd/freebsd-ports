# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webkit
PORTVERSION=	2.26.4
CATEGORIES=	www
MASTER_SITES=	https://webkitgtk.org/releases/
PKGNAMESUFFIX=	2-gtk3
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK+ 3 toolkit

LICENSE=	GPLv2 BSD2CLAUSE
LICENSE_COMB=	dual

LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libfribidi.so:converters/fribidi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libwebp.so:graphics/webp \
		libpng.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libnotify.so:devel/libnotify \
		libhyphen.so:textproc/hyphen \
		libicutu.so:devel/icu \
		libopenjp2.so:graphics/openjpeg \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libsoup-2.4.so:devel/libsoup \
		libgcrypt.so:security/libgcrypt \
		libtasn1.so:security/libtasn1 \
		libwoff2dec.so:devel/woff2

PORTSCOUT=	limitw:1,even

USES=		bison cmake compiler:c++14-lang gettext gl gnome gperf \
		jpeg localbase:ldflags perl5 pkgconfig python:build \
		sqlite tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build libxml2 libxslt
USE_GL=		gl egl glesv2
USE_GSTREAMER1=	bad gl
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
USE_XORG=	x11 xcomposite xdamage xext xrender xt ice

BINARY_ALIAS=		python=${PYTHON_CMD}
CXXFLAGS+=		-DFIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB=32
CXXFLAGS_powerpc=	-DENABLE_YARR_JIT=0
CXXFLAGS_powerpc64=	-DENABLE_YARR_JIT=0
CMAKE_ARGS=		-DPORT=GTK
CMAKE_OFF=		USE_LD_GOLD ${CMAKE_OFF_${ARCH}:U} \
			ENABLE_GLES2 \
			USE_SYSTEM_MALLOC
CMAKE_ON=		ENABLE_MINIBROWSER
CMAKE_OFF_armv6=	ENABLE_JIT
CMAKE_OFF_armv7=	ENABLE_JIT
CMAKE_OFF_powerpc=	ENABLE_JIT
CMAKE_OFF_powerpc64=	ENABLE_JIT
CONFIGURE_ENV=		XDG_CACHE_HOME=${WRKDIR}
INSTALL_TARGET=		install

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk3

OPTIONS_DEFINE=		DEBUG GEOIP WAYLAND
OPTIONS_DEFAULT=	GEOIP WAYLAND
OPTIONS_SUB=		yes

# Building WebKit with debugging symbols requires ar and ld with
# support for thin archives.  Also see
# https://bugs.webkit.org/show_bug.cgi?id=140384
# binutils can be removed when 12.0-R and 11.2 and 11.3 are EOL
# https://svnweb.freebsd.org/base?view=revision&revision=346079
DEBUG_BUILD_DEPENDS=	binutils>=0:devel/binutils
DEBUG_CMAKE_ON=		-DCMAKE_AR=${LOCALBASE}/bin/ar \
			-DCMAKE_RANLIB=${LOCALBASE}/bin/ranlib \
			-DCMAKE_LINKER=${LOCALBASE}/bin/ld
DEBUG_CXXFLAGS=		-B${LOCALBASE}/bin

DEBUG_CMAKE_OFF=	-DCMAKE_AR=/usr/bin/ar \
			-DCMAKE_RANLIB=/usr/bin/ranlib \
			-DCMAKE_LINKER=/usr/bin/ld
DEBUG_CXXFLAGS_OFF=	-B/usr/bin
DEBUG_CFLAGS_OFF=	-DNDEBUG

GEOIP_CMAKE_BOOL=	ENABLE_GEOLOCATION
GEOIP_BUILD_DEPENDS=	geoclue>=2.4.3:net/geoclue
GEOIP_RUN_DEPENDS=	geoclue>=2.4.3:net/geoclue

WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND_TARGET
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libwpe-1.0.so:www/libwpe \
			libWPEBackend-fdo-1.0.so:www/wpebackend-fdo

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/lib/browser/plugins|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/Source/WebKit/Shared/Plugins/unix/PluginSearchPath.cpp

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-egl; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with OPENGL support enabled."; \
		${FALSE}; \
	fi

post-install:
	@${RLN} ${STAGEDIR}${PREFIX}/libexec/webkit2gtk-4.0/jsc \
		${STAGEDIR}${PREFIX}/bin/jsc-4
	@${RLN} ${STAGEDIR}${PREFIX}/libexec/webkit2gtk-4.0/MiniBrowser \
		${STAGEDIR}${PREFIX}/bin/MiniBrowser-4
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/webkit2gtk-4.0/injected-bundle/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/webkit2gtk-4.0/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/WebKitWebDriver

.include <bsd.port.mk>
