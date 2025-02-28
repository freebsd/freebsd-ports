PORTNAME=	qxmpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
CATEGORIES=	net-im
PKGNAMESUFFIX=	-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	XMPP client library based on Qt and C++
WWW=		https://github.com/qxmpp-project/qxmpp/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libomemo-c.so:security/libomemo-c \
		libqca-qt6.so:devel/qca@qt6

USES=		cmake compiler:c++20-lang pathfix pkgconfig qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	qxmpp-project
USE_LDCONFIG=	yes
USE_QT=		base

CMAKE_ARGS=	-DQT_VERSION_MAJOR=6
CMAKE_ON=	BUILD_OMEMO
CMAKE_OFF=	BUILD_EXAMPLES

PLIST_SUB=	SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=		GSTREAMER TEST
OPTIONS_SUB=		yes

GSTREAMER_DESC=		Audio/video support over Jingle via GStreamer
GSTREAMER_USES=		gnome gstreamer
GSTREAMER_USE=		GNOME=glib20 \
			GSTREAMER=good,ugly
GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER

TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
