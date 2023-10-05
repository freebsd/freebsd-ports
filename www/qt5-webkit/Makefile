PORTNAME=		webkit
DISTVERSION=		5.212.0-alpha4
PORTREVISION=	16
CATEGORIES=		www
MASTER_SITES=		https://github.com/qt${PORTNAME}/qt${PORTNAME}/releases/download/${DISTNAME}/
PKGNAMEPREFIX=		qt5-
DISTNAME=		qt${PORTNAME}-${DISTVERSION}

PATCH_SITES=		https://github.com/qt${PORTNAME}/qt${PORTNAME}/commit/
PATCHFILES+=		78360c01c796b6260bf828bc9c8a0ef73c5132fd.patch:-p1

DEPRECATED=		No longer actively maintained, increasing security concers
EXPIRATION_DATE=	2023-12-31

MAINTAINER=		kde@FreeBSD.org
COMMENT=		QtWebKit with a more modern WebKit code base
WWW=		https://github.com/annulen/webkit

LIB_DEPENDS=		libfontconfig.so:x11-fonts/fontconfig \
			libhyphen.so:textproc/hyphen \
			libicui18n.so:devel/icu \
			libpng.so:graphics/png \
			libwebp.so:graphics/webp \
			libwoff2dec.so:devel/woff2

USES=			bison cmake compiler:c++11-lang gnome gperf jpeg \
	pathfix perl5 pkgconfig python:build qt:5 ruby:build \
	sqlite:3 tar:xz xorg
USE_GNOME=		glib20 libxml2 libxslt
USE_PERL5=		build
USE_QT=			core declarative gui location network opengl printsupport \
			sensors webchannel widgets \
			buildtools:build declarative-test:build qmake:build testlib:build
USE_XORG=		x11 xcomposite xrender

# Fix pkgconfig install paths.
PATHFIX_CMAKELISTSTXT=	PlatformQt.cmake

CMAKE_ARGS=		-DPORT:STRING="Qt" \
			-DKDE_INSTALL_INCLUDEDIR:PATH="${QT_INCDIR_REL}" \
			-DKDE_INSTALL_LIBDIR:PATH="${QT_LIBDIR_REL}"
CMAKE_ON=		ENABLE_OPENGL
CMAKE_OFF=		USE_QT_MULTIMEDIA USE_LD_GOLD

# Add -DNDEBUG to CXXFLAGS which in turn gets sucked into
# CMAKE_CXX_FLAGS_RELEASE where we actually want to have it.
# [for the ASSERT in Source/WebCore/platform/graphics/texmap/GraphicsLayerTextureMapper.cpp ]
CXXFLAGS+=		-DNDEBUG

PLIST_SUB=		FULLVER="${PORTVERSION:R}"

SUB_FILES=		pkg-install
SUB_LIST=		QT_INCDIR="${QT_INCDIR}"

OPTIONS_DEFINE=	GSTREAMER
OPTIONS_DEFAULT=	GSTREAMER

GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GSTREAMER=core
GSTREAMER_CMAKE_OFF=	-DUSE_GSTREAMER:BOOL=OFF

BINARY_ALIAS=		python3=${PYTHON_CMD}

.include <bsd.port.mk>
