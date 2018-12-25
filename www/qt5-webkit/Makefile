# $FreeBSD$

PORTNAME=		webkit
DISTVERSION=		5.212.0-alpha2
PORTREVISION=		17
CATEGORIES=		www
MASTER_SITES=		https://github.com/annulen/${PORTNAME}/releases/download/${DISTNAME}/
PKGNAMEPREFIX=		qt5-
DISTNAME=		qt${PORTNAME}-${DISTVERSION}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		QtWebKit with a more modern WebKit code base

LIB_DEPENDS=		libfontconfig.so:x11-fonts/fontconfig \
			libgstapp-1.0.so:multimedia/gstreamer1-plugins \
			libgstbase-1.0.so:multimedia/gstreamer1 \
			libhyphen.so:textproc/hyphen \
			libicui18n.so:devel/icu \
			libpng.so:graphics/png \
			libwebp.so:graphics/webp

USES=			bison cmake compiler:c++11-lang gperf jpeg \
			pathfix perl5 pkgconfig python:2.7,build qt:5 sqlite:3 \
			tar:xz
USE_GNOME=		glib20 libxml2 libxslt
USE_PERL5=		build
USE_GSTREAMER1=		core
USE_QT=			core declarative gui location network opengl printsupport \
			sensors testlib webchannel widgets \
			buildtools_build qmake_build
USE_RUBY=		yes
USE_XORG=		x11 xcomposite xrender

# Fix pkgconfig install paths.
PATHFIX_CMAKELISTSTXT=	PlatformQt.cmake

RUBY_NO_RUN_DEPENDS=	yes

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

.include <bsd.port.mk>
