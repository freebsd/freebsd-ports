PORTNAME=		mediaelch
DISTVERSIONPREFIX=	v
DISTVERSION=		2.12.0
CATEGORIES=		multimedia
PKGNAMESUFFIX=		-${FLAVOR}

PATCH_SITES=	https://github.com/Komet/MediaElch/commit/
PATCHFILES+=	dbea12fbf2c1fe603819392aa2a181cffa168548.patch:-p1 # Fix build with Qt >= 6.9.0
PATCHFILES+=	f125fad644d72f2740aeab64a2016ae2dd341b35.patch:-p1 # Suppress -Wc++20-extensions

MAINTAINER=	ports@freebsd.org
COMMENT=	Desktop utility to manage metadata and artwork for Kodi and Jellyfin
WWW=		https://www.mediaelch.de/mediaelch/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmediainfo.so:multimedia/libmediainfo	\
		libcurl.so:ftp/curl			\
		libquazip1-${FLAVOR}.so:archivers/quazip@${FLAVOR}

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

USES=		cmake gl localbase:ldflags qt:${FLAVOR:S/qt//}

USE_GITHUB=	yes
GH_ACCOUNT=	Komet
GH_PROJECT=	MediaElch

USE_GL=		opengl

_USE_QT_qt5=	buildtools:build qmake:build linguisttools:build \
		concurrent core gui multimedia network opengl qmake sql svg \
		widgets xml
_USE_QT_qt6=	5compat base multimedia svg tools
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ON=	USE_EXTERN_QUAZIP MEDIAELCH_FORCE_QT${FLAVOR:S/qt//}

PLIST_FILES=	bin/MediaElch \
		share/applications/MediaElch.desktop \
		share/metainfo/com.kvibes.MediaElch.metainfo.xml \
		share/pixmaps/MediaElch.png

.include <bsd.port.mk>
