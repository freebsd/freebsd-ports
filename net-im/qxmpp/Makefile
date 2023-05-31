PORTNAME=	qxmpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.5
CATEGORIES=	net-im
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	XMPP client library based on Qt and C++
WWW=		https://github.com/qxmpp-project/qxmpp/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libomemo-c.so:security/libomemo-c

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++17-lang libtool pathfix pkgconfig qca qt:${FLAVOR:S/qt//}
USE_GITHUB=	yes
GH_ACCOUNT=	qxmpp-project
USE_QT=		${_USE_QT_${FLAVOR}}
CMAKE_ARGS=	-DQT_VERSION_MAJOR=${FLAVOR:S/qt//}
CMAKE_ON=	BUILD_OMEMO

_USE_QT_qt5=	core gui network xml \
		buildtools:build qmake:build testlib:build
_USE_QT_qt6=	base

_PLIST_QT5_qt5=
_PLIST_QT5_qt6=	"@comment "
PLIST_SUB=	VERSION=${PORTVERSION} \
		QT_VER=${FLAVOR:S/qt//} \
		QT5_ONLY=${_PLIST_QT5_${FLAVOR}}

.include <bsd.port.mk>
