PORTNAME=	qtkeychain
DISTVERSIONPREFIX=	v
DISTVERSION=	0.13.2
PORTREVISION=	1
CATEGORIES=	security
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Platform independent Qt API for storing passwords

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++11-lang localbase:ldflags pkgconfig qt:${FLAVOR:S/qt//}
_WITH_QT6_qt5=	OFF
_WITH_QT6_qt6=	ON
CMAKE_ARGS=	-DBUILD_WITH_QT6=${_WITH_QT6_${FLAVOR}} \
		-DQT_MKSPECDIR_REL=${QT_MKSPECDIR_REL}
USE_GITHUB=	yes
_USE_QT_qt5=	core dbus buildtools_build qmake_build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}
GH_ACCOUNT=	frankosterfeld
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
PLIST_SUB=	VERSION=${PORTVERSION} \
		QT_VER=${FLAVOR:S/qt//}


OPTIONS_DEFINE=		LIBSECRET NLS
OPTIONS_DEFAULT=	LIBSECRET NLS

LIBSECRET_DESC=		Enable libsecret backend
LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_BOOL=	LIBSECRET_SUPPORT

_QT_LINGUIST_qt5=	linguisttools_build
_QT_LINGUIST_qt6=	tools_build
NLS_USE=		qt=${_QT_LINGUIST_${FLAVOR}}
NLS_CMAKE_BOOL=		BUILD_TRANSLATIONS

.include <bsd.port.mk>
