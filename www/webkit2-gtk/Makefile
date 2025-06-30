PORTNAME=	webkit
DISTVERSION=	2.46.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://webkitgtk.org/releases/
PKGNAMESUFFIX=	2-gtk_${FLAVOR}
DISTNAME=	${PORTNAME}gtk-${DISTVERSION}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://github.com/WebKit/WebKit/commit/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK 3 toolkit
WWW=		https://webkitgtk.org/

LICENSE=	GPLv2 BSD2CLAUSE
LICENSE_COMB=	dual

BROKEN_riscv64=	error: Unknown Architecture

BUILD_DEPENDS=	rubygem-getoptlong>0:devel/rubygem-getoptlong
LIB_DEPENDS=	libavif.so:graphics/libavif \
		libdrm.so:graphics/libdrm \
		libenchant-2.so:textproc/enchant2 \
		libepoxy.so:graphics/libepoxy \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgcrypt.so:security/libgcrypt \
		libgraphene-1.0.so:graphics/graphene \
		libgpg-error.so:security/libgpg-error \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libharfbuzz.so:print/harfbuzz \
		libhyphen.so:textproc/hyphen \
		libicudata.so:devel/icu \
		libjxl.so:graphics/libjxl \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libsecret-1.so:security/libsecret \
		libsysinfo.so:devel/libsysinfo \
		libtasn1.so:security/libtasn1 \
		libwebp.so:graphics/webp \
		libwoff2dec.so:devel/woff2

PORTSCOUT=	limitw:1,even

FLAVORS=	60 41 40
FLAVOR?=	${FLAVORS:[1]}

USES=		bison cmake compiler:c++23-lang cpe gettext gl gnome gperf \
		jpeg localbase:ldflags perl5 pkgconfig python:build \
		ruby:build sqlite tar:xz xorg
USE_GNOME=	cairo gdkpixbuf introspection:build libxml2 libxslt
USE_GL=		egl gbm gl glesv2
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	x11

CPE_VENDOR=	webkitgtk
CPE_PRODUCT=	webkitgtk

BINARY_ALIAS=		python=${PYTHON_CMD}
CXXFLAGS+=		-DFIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB=32 \
			-I${LOCALBASE}/include -lsysinfo
CMAKE_ARGS=		-DPORT=GTK
CMAKE_OFF=		${CMAKE_OFF_${ARCH}:U} \
			ENABLE_GAMEPAD \
			ENABLE_JOURNALD_LOG \
			USE_LIBBACKTRACE \
			USE_SYSTEM_MALLOC \
			USE_SYSPROF_CAPTURE \
			USE_SYSTEM_SYSPROF_CAPTURE
CMAKE_OFF_armv6=	ENABLE_JIT
CMAKE_OFF_armv7=	ENABLE_JIT
INSTALL_TARGET=		install

.if ${FLAVOR:M60}
USE_GNOME+=	gtk40

PLIST=	${.CURDIR}/pkg-plist_${FLAVOR}
API_VERSION=	6.0
WEBKIT_LIBRARY_VERSION=	4 10 8
JAVASCRIPTCORE_LIBRARY_VERSION=	1 3 15
.else
USE_GNOME+=	gtk30

CMAKE_OFF+=	USE_GTK4
.endif
.if ${FLAVOR:M40}
LIB_DEPENDS+=	libsoup-2.4.so:devel/libsoup

CMAKE_ON+=	USE_SOUP2
API_VERSION=	4.0
WEBKIT_LIBRARY_VERSION=	37 71 8
JAVASCRIPTCORE_LIBRARY_VERSION=	18 25 15
.else
LIB_DEPENDS+=	libsoup-3.0.so:devel/libsoup3
.endif
.if ${FLAVOR:M41}
API_VERSION=	4.1
WEBKIT_LIBRARY_VERSION=	0 16 8
JAVASCRIPTCORE_LIBRARY_VERSION=	0 6 15
.endif

PLIST_SUB=	API_VERSION=${API_VERSION} \
		WEBKIT_LIBRARY_VERSION=${WEBKIT_LIBRARY_VERSION:ts.} \
		WEBKIT_LIBRARY_VERSION_MAJOR=${WEBKIT_LIBRARY_VERSION:[1]} \
		JAVASCRIPTCORE_LIBRARY_VERSION=${JAVASCRIPTCORE_LIBRARY_VERSION:ts.} \
		JAVASCRIPTCORE_LIBRARY_VERSION_MAJOR=${JAVASCRIPTCORE_LIBRARY_VERSION:[1]}

OPTIONS_DEFINE=		DOCS GEOIP GSTREAMER WAYLAND
OPTIONS_DEFAULT=	GEOIP GSTREAMER WAYLAND
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	ENABLE_DOCUMENTATION
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gi-docgen>0:textproc/py-gi-docgen@${PY_FLAVOR}

GEOIP_CMAKE_BOOL=	ENABLE_GEOLOCATION
GEOIP_BUILD_DEPENDS=	geoclue>=2.4.3:net/geoclue
GEOIP_RUN_DEPENDS=	geoclue>=2.4.3:net/geoclue

GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GSTREAMER=bad,gl
GSTREAMER_CMAKE_BOOL=	ENABLE_VIDEO ENABLE_WEB_AUDIO

WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND_TARGET
WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland

.include <bsd.port.options.mk>

.ifdef WITH_DEBUG
DEBUG_FLAGS=	-g1 # resulting package otherwise is huge
.endif

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/WebKitWebDriver \
		${STAGEDIR}${PREFIX}/bin/WebKitWebDriver-${API_VERSION}

.include <bsd.port.mk>
