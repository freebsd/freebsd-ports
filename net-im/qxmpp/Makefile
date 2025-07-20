PORTNAME=	qxmpp
DISTVERSION=	1.10.4
CATEGORIES=	net-im
MASTER_SITES=	KDE/unstable/${PORTNAME}
PKGNAMESUFFIX=	-qt6
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	XMPP client library based on Qt and C++
WWW=		https://invent.kde.org/libraries/qxmpp

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libomemo-c.so:security/libomemo-c \
		libqca-qt6.so:devel/qca@qt6

USES=		cmake:testing compiler:c++20-lang kde:6 pathfix pkgconfig \
		qt:6 tar:xz
USE_LDCONFIG=	yes
USE_QT=		base

CMAKE_ARGS=	-DQT_VERSION_MAJOR=6
CMAKE_ON=	BUILD_OMEMO
CMAKE_OFF=	BUILD_EXAMPLES \
		BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=		GSTREAMER
OPTIONS_SUB=		yes

GSTREAMER_DESC=		Audio/video support over Jingle via GStreamer
GSTREAMER_USES=		gnome gstreamer
GSTREAMER_USE=		GNOME=glib20 \
			GSTREAMER=good,ugly
GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER

.include <bsd.port.mk>
