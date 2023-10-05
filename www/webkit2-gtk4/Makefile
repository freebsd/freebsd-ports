PORTNAME=	webkit
DISTVERSION=	2.38.3
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	https://webkitgtk.org/releases/
PKGNAMESUFFIX=	2-gtk4
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://github.com/WebKit/WebKit/commit/
PATCHFILES=	285ff73b5f6d46d6e502aca30061667e41a3114b.diff:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK 4 toolkit
WWW=		https://webkitgtk.org/

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	dual

BROKEN_riscv64=	error: Unknown Architecture

BUILD_DEPENDS=	${LOCALBASE}/bin/ar:devel/binutils \
		${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgcrypt.so:security/libgcrypt \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libharfbuzz.so:print/harfbuzz \
		libhyphen.so:textproc/hyphen \
		libicutu.so:devel/icu \
		libnotify.so:devel/libnotify \
		libopenjp2.so:graphics/openjpeg \
		libpng.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3 \
		libtasn1.so:security/libtasn1 \
		libwebp.so:graphics/webp \
		libwoff2dec.so:devel/woff2

PORTSCOUT=	limitw:1,even

USES=		bison cmake compiler:c++20-lang cpe gettext gl gnome gperf jpeg \
		localbase:ldflags perl5 pkgconfig python:build ruby:build \
		sqlite tar:xz xorg
USE_GNOME=	cairo gdkpixbuf2 gtk40 libxml2 libxslt introspection:build
USE_GL=		egl gl glesv2
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	ice x11 xcomposite xdamage xext xrender xt

CPE_VENDOR=	webkitgtk
CPE_PRODUCT=	webkitgtk

BINARY_ALIAS=		python=${PYTHON_CMD}
CXXFLAGS+=		-DFIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB=32
CMAKE_ARGS=		-DPORT=GTK
CMAKE_OFF=		${CMAKE_OFF_${ARCH}:U} ENABLE_GAMEPAD ENABLE_GLES2 \
			ENABLE_JOURNALD_LOG USE_LD_GOLD USE_SYSTEMD
CMAKE_ON=		ENABLE_MINIBROWSER USE_GTK4 USE_SYSTEM_MALLOC
CMAKE_OFF_armv6=	ENABLE_JIT
CMAKE_OFF_armv7=	ENABLE_JIT
INSTALL_TARGET=		install

OPTIONS_DEFINE=		DEBUG GEOIP GSTREAMER WAYLAND
OPTIONS_DEFAULT=	GEOIP GSTREAMER WAYLAND
OPTIONS_SUB=		yes

# Building WebKit with debugging symbols requires ar and ld with
# support for thin archives.  Also see
# https://bugs.webkit.org/show_bug.cgi?id=140384
DEBUG_CMAKE_ON=	-DCMAKE_AR=${LOCALBASE}/bin/ar \
		-DCMAKE_LINKER=${LOCALBASE}/bin/ld \
		-DCMAKE_RANLIB=${LOCALBASE}/bin/ranlib
DEBUG_CXXFLAGS=	-B${LOCALBASE}/bin

DEBUG_CMAKE_OFF=	-DCMAKE_AR=/usr/bin/ar \
			-DCMAKE_LINKER=/usr/bin/ld \
			-DCMAKE_RANLIB=/usr/bin/ranlib
DEBUG_CXXFLAGS_OFF=	-B/usr/bin
DEBUG_CFLAGS_OFF=	-DNDEBUG

GEOIP_CMAKE_BOOL=	ENABLE_GEOLOCATION
GEOIP_BUILD_DEPENDS=	geoclue>=2.4.3:net/geoclue
GEOIP_RUN_DEPENDS=	geoclue>=2.4.3:net/geoclue

GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GSTREAMER=bad,gl
GSTREAMER_CMAKE_BOOL=	ENABLE_VIDEO ENABLE_WEB_AUDIO

WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND_TARGET
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libwpe-1.0.so:www/libwpe \
			libWPEBackend-fdo-1.0.so:www/wpebackend-fdo

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 160
CXXFLAGS+=	-Wno-error=enum-constexpr-conversion
.endif

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-egl; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with OPENGL support enabled."; \
		${FALSE}; \
	fi

post-install:
	@${RLN} ${STAGEDIR}${PREFIX}/libexec/webkit2gtk-5.0/jsc \
		${STAGEDIR}${PREFIX}/bin/jsc-5
	@${RLN} ${STAGEDIR}${PREFIX}/libexec/webkit2gtk-5.0/MiniBrowser \
		${STAGEDIR}${PREFIX}/bin/MiniBrowser-5
	@${MV} ${STAGEDIR}${PREFIX}/bin/WebKitWebDriver \
		${STAGEDIR}${PREFIX}/bin/WebKitWebDriver-5
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*.*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/webkit2gtk-5.0/injected-bundle/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/webkit2gtk-5.0/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/WebKitWebDriver-5

.include <bsd.port.post.mk>
