PORTNAME=	qxmpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	net-im
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	XMPP client library based on Qt and C++
WWW=		https://github.com/qxmpp-project/qxmpp/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libomemo-c.so:security/libomemo-c

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++17-lang pathfix pkgconfig qca \
		qt:${QT_VER}
USE_GITHUB=	yes
GH_ACCOUNT=	qxmpp-project
USE_LDCONFIG=	yes
_USE_QT_qt5=	core network xml \
		buildtools:build qmake:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ARGS=	-DQT_VERSION_MAJOR=${QT_VER}
CMAKE_ON=	BUILD_OMEMO
CMAKE_OFF=	BUILD_EXAMPLES

_PLIST_SUB_qt5=	QT5_ONLY=""
_PLIST_SUB_qt6=	QT5_ONLY="@comment "
PLIST_SUB=	VERSION=${PORTVERSION} \
		QT_VER=${QT_VER} \
		${_PLIST_SUB_${FLAVOR}}

QT_VER=		${FLAVOR:S/qt//}

OPTIONS_DEFINE=		GSTREAMER TEST
OPTIONS_SUB=		yes

GSTREAMER_DESC=		Audio/video support over Jingle via GStreamer
GSTREAMER_USES=		gnome gstreamer
GSTREAMER_USE=		GNOME=glib20 \
			GSTREAMER=good,ugly
GSTREAMER_CMAKE_BOOL=	WITH_GSTREAMER

_TEST_USE_QT_qt5=	QT=testlib:build
_TEST_USE_QT_qt6=	# empty
TEST_USE=		${_TEST_USE_QT_${FLAVOR}}
TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
